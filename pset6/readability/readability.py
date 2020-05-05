from cs50 import get_string

letter = 0
# in a text there is one more word than the number of spaces if the spaces are exact
word = 1
sentence = 0

text = get_string("Text: ")
for c in text:
    # calculating number of alphabets ie letters
    if c.lower() >= 'a' and c.lower() <= 'z':
        letter += 1
    # calculating num of words
    if c == ' ':
        word += 1
    # every sentence contained one terminating symbol
    if c in ('.', '!', '?'):
        sentence += 1
# calculating letters per 100 words
L = (letter * 100) / word
# calculating sentence per 100 words
S = (sentence * 100) / word

# calculating index using coleman-Liau formula
index = 0.0588 * L - 0.296 * S - 15.8

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {round(index)}")