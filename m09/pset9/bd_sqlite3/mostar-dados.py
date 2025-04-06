
# Referência para estudos de manipulação de string com python
# https://www.w3schools.com/python/python_arrays.asp
# https://cienciaprogramada.com.br/2022/03/formatacao-strings-python/

# conexão com banco
import sqlite3
con = sqlite3.connect("usuario.db")
cur = con.cursor()

print('Concexão feita com sucesso.')

#res = cur.execute("SELECT * FROM usuario")
#res = cur.execute("SELECT *  FROM usuario WHERE rowid=1"))

# array com dados do usuario do banco
usuarios = []

# for que copia os dados do banco para array
for row in cur.execute("SELECT rowid, nome, sobrenome, idade  FROM usuario"):
    #print(row)
    usuarios.append(row)

# função lista dados para usuario na tela
def mostrar_dados():
    print('{0: <4} | {1: ^16} | {2: ^16}| {3: ^16}'.format('id', 'nome', 'sobrenome', 'idade'))
    for user in usuarios:
        #print(f"|{user[0]} | {user[1]} |{user[2]} |{user[3]} |")
        print('{0: <4} | {1: ^16} | {2: ^16}| {3: ^16}'.format(user[0], user[1], user[2],user[3]))

# chamada da função mostrar dados
mostrar_dados()

# close conexão com banco
con.close()

print('Dados listado com sucesso.')