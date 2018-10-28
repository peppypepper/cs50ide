import sqlite3
import time, datetime, random, matplotlib.pyplot as plt, matplotlib.dates as mdates
from matplotlib import style
style.use('fivethirtyeight')


conn = sqlite3.connect('tutorial.db')
c = conn.cursor()

def create_table():
    c.execute('CREATE TABLE IF NOT EXISTS stuffToPlot(unix REAL, datestamp TEXT, keyword TEXT, value REAL)')

def data_entry():
    c.execute("INSERT INTO stuffToPlot VALUES(547, '10-11-18', 'Python', 5 )")
    conn.commit()
    c.close()
    conn.close()

def dynamic_data_entry():
    unix = time.time()
    date = str(datetime.datetime.fromtimestamp(unix).strftime('%Y-%m-%d %H: %M: %S'))
    keyword = 'Python'
    value = random.randrange(0,10)
    c.execute("INSERT INTO stuffToPlot (unix, datestamp, keyword, value) VALUES (?, ?, ?, ?)",
                (unix, date, keyword, value))
    conn.commit()

def del_and_update():
    c.execute("SELECT * FROM stuffToPlot")
    [print(row) for row in c.fetchall()]

    c.execute("UPDATE stuffToPlot SET value=99 WHERE value=7")
    conn.commit

    c.execute("DELETE FROM stuffToPLot WHERE value=99")

#create_table()
#data_entry()

#for i in range(10):
#   dynamic_data_entry()
#    time.sleep(1)

c.close()
conn.close()


