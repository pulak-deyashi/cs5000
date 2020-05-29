# TODO
import csv, sqlite3
from sys import argv
def dataload(argv):
    if len(argv) != 2:
        print("input error")
        return 1
    db = sqlite3.connect('students.db')
    with open(argv[1], 'r') as csvf:
        dr = csv.DictReader(csvf)
        for row in dr:
            names = row['name'].split()
            if len(names) == 2:
                to_db = [names[0], None, names[1], row['house'], int(row['birth'])]
                db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)", to_db)
                db.commit()
            elif len(names) == 3:
                to_db = [names[0], names[1], names[2], row['house'], int(row['birth'])]
                db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)", to_db)
                db.commit()
    db.commit()
    db.close()
if(__name__ == "__main__"):
    dataload(argv)