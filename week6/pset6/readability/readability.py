from cs50 import get_string

text = get_string("Text: ")

# set the counter variables
letters, words, sentences = 0, 1, 0

# loop through the text and count
for i in text:
    if i >= 'A' and i <= 'z':
        letters += 1
    if i == ' ':
        words += 1
    if i == '.' or i == '!' or i == '?':
        sentences += 1

# calculate avgerage letters and sentences
avgletters = (letters / words) * 100
avgsentences = (sentences / words) * 100

# calculate the Coleman-Liau index
grade = 0.0588 * avgletters - 0.296 * avgsentences - 15.8

# print the grades
if grade < 1:
    print('Before Grade 1')
elif grade > 16:
    print("Grade 16+")
else:
    print(f"Grade {round(grade)}")