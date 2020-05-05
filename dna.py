import csv
from sys import argv

def function(argv):

    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return 1

    f = open(argv[2])
    txt = f.read()

    file = open(argv[1], newline="")
    read = csv.reader(file)
    header = next(read)
    maxcount = 0;
    count = 0
    j = 0
    str_dict = dict()
    for i in range(1, len(header)):
        tr = header[i]
        str_dict[tr] = []
        for j in range(len(txt)):
            while txt[j : j+len(tr)] == tr:
                count = count + 1
                j = j+len(tr)
            str_dict[tr].append(count)
            count = 0
    val = list()
    for key in str_dict:
        val.append(str(max(str_dict[key])))
    for row in read:
        if row[1:] == val:
            print(row[0])
            return 0
    print("No match")
