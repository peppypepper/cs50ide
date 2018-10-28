import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions
from werkzeug.security import check_password_hash, generate_password_hash
from time import gmtime, strftime

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached to get fresh data everytime from server not the cache
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    rows = db.execute("SELECT * FROM transactions WHERE username = :username", username=session["user_id"][0]['username'])

    if not rows:
         return render_template("index.html" cash, total)
    cash = float(db.execute("SELECT cash FROM users WHERE id=1")


    symbol = rows['symbol']
    name = rows['name']
    shares = rows['shares']

    #get current price for the index table
    price = lookup(request.form.get("symbol"))['price']

    total = shares * price

    return render_template("index.html", symbol, name, shares, price, total)



@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    if request.method == "POST":

        if not request.form.get("symbol"):
            return apology("need stock symbol")

        if not request.form.get("shares"):
            return apology("how many would you like?")

        if lookup(request.form.get("symbol")) is None:
            return apology("invalid stock symbol")

        if float(request.form.get("shares")) <= 0:
            return apology("only numbers allowed")


        quote = lookup(request.form.get("symbol"))
        shares = int(request.form.get("shares"))
        
        #current cash
        cash = db.execute("SELECT cash FROM users WHERE id = 1")
        username = db.execute("SELECT username FROM users WHERE id = 1")
        price = quote["price"]
        buyvalue =  shares * price
        time = strftime("%Y-%m-%d %H:%M:%S", gmtime())
        
        #can user afford the buy
        if buyvalue > cash:
            return apology("not enough funds", 400)
        
        #update the purchase in transaction
        db.execute("UPDATE transactions SET  ")
        
        #update cash
        db.execute("UPDATE users SET cash = cash - buyvalue WHERE id=1")

        return redirect("/quote")

    else:
        return render_template("buy.html")

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/quote")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("need a stock symbol", 403)


        quote = lookup(request.form.get("symbol"))
        if quote is None:
            return apology("invalid stock symbol", 403)
        else:
            return render_template("quoted.html", name = quote['name'], symbol = quote['symbol'], price = quote['price'])
    else:
        return render_template("quote.html")

@app.route("/register", methods=["GET", "POST"])
def register():
    session.clear()

    if request.method == "POST":  #post is the safe method when submitting information, get is not

        if not request.form.get("username"):
            return apology("missing username")

        elif not request.form.get("password"):
            return apology("missing password")

        elif not request.form.get("passwordconfirmation"):
            return apology("missing password confirmation")

        #make sure password and confirmation match, else apologize
        elif not request.form.get("password") == request.form.get("passwordconfirmation"):
            return apology("passwords do not match")


        #add username and password to database, if username already in db, apology
        result = db.execute("INSERT INTO users (username, hash) VALUES (:username, :hashed)", username=request.form.get("username"), hashed=generate_password_hash(request.form.get("password")))
        if not result:
            return apology("username already exists")

        # create user session
        session["user_id"] = result[0]["id"]

        # Redirect user to home page
        return redirect("/")

    else:
        return render_template("register.html")

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")


def errorhandler(e):
    """Handle error"""
    return apology(e.name, e.code)


# listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
