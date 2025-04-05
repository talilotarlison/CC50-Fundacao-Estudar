notas = []

for i in range(3):
    nota = int(input("Digite a nota: "))
    notas.append(nota)

avg = sum(notas) / len(notas)
print(f"AVG: {avg}")
