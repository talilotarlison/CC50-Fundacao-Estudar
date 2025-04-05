import csv

title = input("Enter the title of the show: ").strip().lower()

with open('Favorite TV Shows - From Responses 1.csv', 'r') as file:
    reader = csv.DictReader(file)
    counter = 0
    for row in reader:
        if row['title'].strip().lower() == title:
            counter += 1
print(f"{title} was mentioned {counter} times.")
# The code reads a CSV file containing favorite TV shows and counts how many times a specific show was mentioned by the user.
