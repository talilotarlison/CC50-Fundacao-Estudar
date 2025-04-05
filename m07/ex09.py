import csv

title = input("Title: ").strip().upper()

with open("Favorite TV Shows - Form Responses 1.csv", "r") as file:
   reader = csv.DictReader(file)

   counter = 0
   for row in reader:
      if row["title"].strip().upper() == title:
         counter += 1

print(counter)

# O SQL oferece suporte a muitas funções que podemos usar para contar e resumir dados:
# AVG
# COUNT
# DISTINCT , para obter valores distintos sem duplicatas
# LOWER
# MAX
# MIN
# UPPER