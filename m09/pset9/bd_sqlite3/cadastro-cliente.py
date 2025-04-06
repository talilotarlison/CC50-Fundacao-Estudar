import sqlite3
con = sqlite3.connect("usuario.db")
cur = con.cursor()

print('Conexão com banco feita com sucesso.')

print('Cadastro de usuario')
print('#'*40)
nome = input('Inserir nome:\n')
sobrenome = input('Inserir sobrenome:\n')
idade = int(input('Inserir idade:\n'))

query = f"INSERT INTO usuario VALUES ('{nome}', '{sobrenome}', {idade})"

cur.execute(query)

con.commit()
print('#'*40)
print('Dados inseridos com sucesso')
con.close()