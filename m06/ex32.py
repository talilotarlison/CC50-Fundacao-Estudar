import csv

# Open the CSV file
with open('phonebook.csv', 'a', newline='') as file:
    writer = csv.writer(file)

    name = input("Enter name: ")
    phone = input("Enter phone: ")

    writer.writerow([name, phone])
