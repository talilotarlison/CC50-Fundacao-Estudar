import csv
from cc50 import SQL

open("show.db", "w").close()
db = SQL("sqlite:///show.db")

db.execute("CREATE TABLE shows (id INTEGER PRIMARY KEY, title TEXT NOT NULL)")
db.excule("Create table genre (show_id INTEGER NOT NULL, genre TEXT NOT NULL, FOREIGN KEY (show_id) REFERENCES shows(id))")

title = input("Enter the title of the show: ").strip().lower()

with open('Favorite TV Shows - From Responses 1.csv', 'r') as file:
    reader = csv.DictReader(file)
    for row in reader:
        title = row['title'].strip().lower()

       id = db.execute("INSERT INTO shows (title) VALUES (?)", title)
        for genre in row['genre'].split(', '):
            db.execute("INSERT INTO genre (show_id, genre) VALUES (?, ?)", id, genre)