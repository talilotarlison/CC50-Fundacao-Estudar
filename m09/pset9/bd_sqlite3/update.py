#https://docs.python.org/3/library/sqlite3.html

# https://www.w3schools.com/mysql/mysql_where.asp

# https://www.sqlitetutorial.net/sqlite-where/

# https://pythonclub.com.br/gerenciando-banco-dados-sqlite3-python-parte1.html

import sqlite3
con = sqlite3.connect("usuario.db")
cur = con.cursor()
print('Concexão feita com sucesso.')
#res = cur.execute("SELECT * FROM usuario")
#res = cur.execute("SELECT *  FROM usuario WHERE rowid=1"))


# atualizando dados do banco

cur.execute(
"""
UPDATE usuario
SET nome = 'maik' WHERE rowid=3
""")
con.commit()

print('Registro atualizado com sucesso.')

for row in cur.execute("SELECT rowid, *  FROM usuario"):
    print(row)

#res.fetchall()

con.close()

print('Dados listados com sucesso.')