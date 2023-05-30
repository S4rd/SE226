import mysql.connector
from tkinter import *


# Connect to database and create table
mydb = mysql.connector.connect(
  host="localhost",
  port="3306",
  user="root",
  password="your_password",
  database="your_db"
)

mycursor = mydb.cursor()

mycursor.execute("CREATE TABLE marvel (id INT AUTO_INCREMENT PRIMARY KEY, movie VARCHAR(255), date DATE, mcu_phase VARCHAR(255))")

# Read from file and insert data into table
with open("Marvel.txt", "r") as f:
    for line in f:
        data = line.strip().split()
        id = int(data[0])
        movie = data[1]
        date = data[2]
        mcu_phase = data[3]
        sql = "INSERT INTO marvel (id, movie, date, mcu_phase) VALUES (%s, %s, %s, %s)"
        val = (id, movie, date, mcu_phase)
        mycursor.execute(sql, val)

mydb.commit()


root = Tk()
root.title("Marvel Database")


id_list = []
mycursor.execute("SELECT id FROM marvel")
myresult = mycursor.fetchall()
for x in myresult:
    id_list.append(x[0])

clicked = StringVar()
clicked.set(id_list[0])

drop = OptionMenu(root, clicked, *id_list)
drop.pack()


text_box = Text(root)
text_box.pack()


def update_text_box(*args):
    text_box.delete("1.0", END)
    mycursor.execute("SELECT * FROM marvel WHERE id=%s", (clicked.get(),))
    myresult = mycursor.fetchone()
    text_box.insert(END, myresult)

clicked.trace("w", update_text_box)


def add_data():
    def add_to_db():
        id = int(id_entry.get())
        movie = movie_entry.get()
        date = date_entry.get()
        mcu_phase = mcu_phase_entry.get()
        sql = "INSERT INTO marvel (id, movie, date, mcu_phase) VALUES (%s, %s, %s, %s)"
        val = (id, movie, date, mcu_phase)
        mycursor.execute(sql, val)
        mydb.commit()
        top.destroy()

    top = Toplevel()
    top.title("Add Data")

    id_label = Label(top, text="ID")
    id_label.pack()
    id_entry = Entry(top)
    id_entry.pack()

    movie_label = Label(top, text="Movie")
    movie_label.pack()
    movie_entry = Entry(top)
    movie_entry.pack()

    date_label = Label(top, text="Date")
    date_label.pack()
    date_entry = Entry(top)
    date_entry.pack()

    mcu_phase_label = Label(top, text="MCU Phase")
    mcu_phase_label.pack()
    mcu_phase_entry = Entry(top)
    mcu_phase_entry.pack()

    ok_button = Button(top, text="OK", command=add_to_db)
    ok_button.pack()

    cancel_button = Button(top, text="Cancel", command=top.destroy)
    cancel_button.pack()


add_button = Button(root, text="Add", command=add_data)
add_button.pack()


def list_all():
    text_box.delete("1.0", END)
    mycursor.execute("SELECT * FROM marvel")
    myresult = mycursor.fetchall()
    for x in myresult:
        text_box.insert(END, x)
        text_box.insert(END, "\n")


list_all_button = Button(root, text="List All", command=list_all)
list_all_button.pack()

root.mainloop()
