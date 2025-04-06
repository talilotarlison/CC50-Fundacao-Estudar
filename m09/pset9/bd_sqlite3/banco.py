# https://docs.python.org/3/library/sqlite3.html
# criar texto personalizado no terminal:
# https://pt.stackoverflow.com/questions/258622/como-criar-desenhos-em-arquivos-escritos-em-batch
# https://pt.stackoverflow.com/questions/258622/como-criar-desenhos-em-arquivos-escritos-em-batch

import sqlite3
con = sqlite3.connect("usuario.db")

cur = con.cursor()

cur.execute("CREATE TABLE usuario(nome varchar(50), sobrenome varchar(50), idade int(50))")

cur.execute()

print('Concexão feita com sucesso.')