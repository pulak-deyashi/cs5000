import csv
from sys import argv


def function(argv):

    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return 1

    # open the text file
    f = open(argv[2])
    # assign it to a variable as string
    txt = f.read()

    # open csv file
    file = open(argv[1], newline="")
    # read the file inside a variable
    read = csv.reader(file)
    # exclude the header file which contains the STR names
    header = next(read)
    count = 0
    # initialize dictionary file for counting the number of
    # STR repeat in each position of the text
    str_dict = dict()
    # iterate for each STR (Short Tandem Repeat)
    for i in range(1, len(header)):
        tr = header[i]
        # declare an empty string for key name of corrosponding STR
        str_dict[tr] = []
        # for every letter ie positon of the string
        for j in range(len(txt)):
            # chech whether each substring of length of corrosponding STR equal to the STR
            while txt[j: j+len(tr)] == tr:
                count = count + 1
                j = j+len(tr)
            # append each value to list of corrosponding key
            str_dict[tr].append(count)
            count = 0
    # intialize an empty list
    val = list()
    # fill the list with the max value of each list inside the dict
    # (in str format for later comparison operation)
    for key in str_dict:
        val.append(str(max(str_dict[key])))
    # now compare each row of the read file staring fron 2nd element
    for row in read:
        if row[1:] == val:
            print(row[0])
            return 0
    # if not found in the csv file then print no match
    print("No match")


if __name__ == "__main__":
    function(argv)