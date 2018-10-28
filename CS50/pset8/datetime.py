from flask import Flask  #import Flask function from flask module/class
from datetime import datetime
from pytz import timezone #import timezone function from pytz module

app = Flask(__name__)  # create an application from datetime.py or usually named application.py

@app.route("/") # a decorator, /, /khoa, /sample, /whatever, to associate a particular function with a particular URL
def time():
    now = datetime.now(timezone('America/New_York'))
    return "the current date and time in Cambridge is {}".format(now)

# 3 steps to run a flash application
export FLASH_APP=application.py  # save the flash app in memory
export FLASH_DEBUG=1 # optional but recommended, 1 is True
flash run

#data can be passed in via URLs, akin to using HTTP GET
@app.route("/show/<number>")  #allow user to pass in imformation
def show(number):
    return "You passed in {}".format(number)

#data can also be passed in via HTML forms, as with HTTP POST,
#but we need to indicate that Flask should respond to HTTP POST requests explicitly
@app.route("/login", methods=['GET', 'POST'])  #use either method to retrieve the data
def login():
    if not request.form.get("username")  #if the username field is blank on the form
        return apology("must provide username") #return apology

#we could also vary the behavior of our function depending on the type of HTTP request received
@app.route("/login", methods=['GET', 'POST'])
def login():
    if request.method == "POST":
        #do one thing
    else:
        #do another thing

url_for()
redirect()
session()
render_template() #mix html and python


















