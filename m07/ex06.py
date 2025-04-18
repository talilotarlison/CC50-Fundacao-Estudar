import csv

titles = dict()

with open('Favorite TV Shows - From Responses 1.csv', 'r') as file:
    reader = csv.DictReader(file)
    header = next(reader)  # Skip the header row
    for row in reader:
        title =row['title'].strip().lower()# Convert to lowercase to avoid duplicates
        if title not in titles:
            titles[title] = 0
        titles[title] += 1 


for title in sorted(titles,key=lambda title: titles[title],reverse=True):
    print(title, titles[title])
