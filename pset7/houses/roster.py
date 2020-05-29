# TODO
from sys import argv
import sqlite3
def printer(argv):
    if len(argv) != 2:
        print("Input error")
        return 1

    db = sqlite3.connect("students.db")
    data = (db.execute(f"SELECT * FROM students WHERE house=\"{argv[1]}\" ORDER BY last, first")).fetchall()
    db.close()
    for row in data:
        if row[2] == None:
            print(f"{row[1]} {row[3]}, born {row[-1]}")
        else:
            print(f"{row[1]} {row[2]} {row[3]}, born {row[-1]}")



if(__name__ == '__main__'):
    printer(argv)
