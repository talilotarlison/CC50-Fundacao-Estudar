import csv

# Open the CSV file
file = open('phonebook.csv', 'a')

name = input("Enter name: ")
phone = input("Enter phone: ")

writer = csv.writer(file)
writer.writerow([name, phone])
file.close()
