import csv
from sys import argv

def function(argv):
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return 1
    # open
    f = open(argv[2])
    txt = f.read()
    # open 
    file = open(argv[1], newline="")
    # read
    read = csv.reader(file)
    # exclude
    header = next(read)
    count = 0
    # initialize
    str_dict = dict()
    # iterate 
    for i in range(1, len(header)):
        tr = header[i]
        length = len(tr)
        str_dict[tr] = []
        for j in range(len(txt)):
            while txt[j: j+length] == tr:
                count = count + 1
                j = j+length
            # append
            str_dict[tr].append(count)
            count = 0
    val = list()
    for key in str_dict:
        val.append(str(max(str_dict[key])))
    for row in read:
        if row[1:] == val:
            print(row[0])
            return 0
    # if not found
    print("No match")
    
if __name__ == "__main__":
    function(argv)
