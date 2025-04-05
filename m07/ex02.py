import csv

with open('Favorite TV Shows - From Responses 1.csv', 'r') as file:
    reader = csv.DictReader(file)
    header = next(reader)  # Skip the header row
    for row in reader:
        print(row[1])  # Print the second column (index 1)
        break  # Remove this line to print all rows