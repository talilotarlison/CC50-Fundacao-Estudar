##############################################################################
import sqlite3
# Conectar ao banco de dados e verifica se a tabela ja exite
# Conectar ao banco de dados
con = sqlite3.connect("bd.db")

# Verificar se a tabela já existe
cur = con.cursor()
cur.execute("SELECT name FROM sqlite_master WHERE type='table' AND name='usuario'")
tabela_existe = cur.fetchone()


if tabela_existe:
    print('Banco de dados ja existe!')
else:
    cur = con.cursor()
    # Criar a tabela
    cur.execute("CREATE TABLE usuario(nome varchar(50), sobrenome varchar(50), idade int(50), cpf int(15))")
    con.commit()    # Commit the changes to the database
    con.close()
    print('Banco de dados criado com sucesso.')

print('Conexão feita com sucesso.')
##############################################################################
   # deletando dados do banco
def delete_dados():

    # deletando dados do banco
    print('#'*40)
    print('Deletar Usuario.')
    print('#'*40)
    id = int(input('Informe o ID do usuario para Excluir:\n'))
    query = f"DELETE FROM usuario WHERE  rowid={id}"
    cur.execute(query)

    con.commit()

    print(f'Registro {id} excluido com sucesso.')

    #con.close()
##############################################################################

# funcao mostra dados na tela para o usuario
def view_dados():
    # array com dados do usuario do banco
    usuarios = []
    cur = con.cursor()
    # for que copia os dados do banco para array
    for row in cur.execute("SELECT rowid, nome, sobrenome, idade, cpf  FROM usuario"):
        #print(row)
        usuarios.append(row)

    mostrar_dados(usuarios)
    # close conexão com banco
    #con.close()

# função lista dados para usuario na tela
def mostrar_dados(usuarios):
    print('{0: <4} | {1: ^16} | {2: ^16}| {3: ^16}| {4: ^16}'.format('id', 'nome', 'sobrenome', 'idade','cpf'))
    for user in usuarios:
        #print(f"|{user[0]} | {user[1]} |{user[2]} |{user[3]} |")
        print('{0: <4} | {1: ^16} | {2: ^16}| {3: ^16}| {4: ^16}'.format(user[0], user[1], user[2],user[3],user[4]))

# chamada da função mostrar dados
##############################################################################
# Fazer o insert pelo usuario atravez do terminal
def inserir_user():
    # Fazer o insert pelo usuario atravez do terminal
    print('#'*40)
    print('Cadastro de usuario no Banco de Dados.')
    print('#'*40)
    # coleta dados do usuario pelo terminal
    nome = input('Inserir nome:\n')
    sobrenome = input('Inserir sobrenome:\n')
    idade = int(input('Inserir idade:\n'))
    cpf = int(input('Inserir cpf:\n'))
    # faz o insert da informações no banco de dados

    #cur = con.cursor()

    query = f"INSERT INTO usuario VALUES ('{nome}', '{sobrenome}', {idade},{cpf})"

    cur.execute(query)

    con.commit()

    print('#'*40)
    print('Dados inseridos com sucesso')

##############################################################################
## funcção inserir novamente
def inserir_novamente():
    print('#'*40)
    print('inserir dados novamente[s/n]?')
    print('#'*40)
    opcao = input('Escolha uma opção:\n')
    if (opcao.lower() == 's'):
        inserir_user()
    else:
        home()

##############################################################################
# funcão de escolha do usuario
def escolha_user(opcao):
    if(opcao==1):
        view_dados()
        voltar_main()
    elif(opcao==2):
       delete_dados()
       voltar_main()
    elif(opcao==3):
       inserir_user()
       inserir_novamente()
    elif(opcao==4):
        print("Agradecemos por usar nosso program!")
        main()
        con.close()
    else:
        print("Opção invalida tente novamente.4")
        voltar_main()
##############################################################################
## funcção voltar main
def voltar_main():
    print('#'*40)
    print('Voltar para Inicio[s/n]?')
    print('#'*40)
    opcao = input('Escolha uma opção:\n')
    if (opcao.lower() == 's'):
        home()
    else:
        print("Opção invalida tente novamente.")
        voltar_main()
##############################################################################

# Criar texto personalizado no terminal:

# Forum de discurção:
# https://pt.stackoverflow.com/questions/258622/como-criar-desenhos-em-arquivos-escritos-em-batch

# Site de criação:
# https://pt.stackoverflow.com/questions/258622/como-criar-desenhos-em-arquivos-escritos-em-batch


##############################################################################

def logo_programa():
    print(
        """
                            _________             .___                __
        _____ ___.__.\_   ___ \_____     __| _/____    _______/  |________  ____
        /     <   |  |/    \  \/\__  \   / __ |\__  \  /  ___/\   __\_  __ \/  _ \\
        |  Y Y  \___  |\     \____/ __ \_/ /_/ | / __ \_\___ \  |  |  |  | \(  <_> )
        |__|_|  / ____| \______  (____  /\____ |(____  /____  > |__|  |__|   \____/
            \/\/             \/     \/      \/     \/     \/
        """
    )


##############################################################################
# menu principal do programa que chama as funções
def home():
    logo_programa()
    print('#'*40)
    print('Gerenciador de usuario no Banco de Dados.')
    print('[1] - Para ver todos cadastros.')
    print('[2] - Para excluir usuario.')
    print('[3] - Para inserir usuario.')
    print('[4] - Exit.')
    print('#'*40)
    opcao = int(input('Escolha uma opção:\n'))
    escolha_user(opcao)

##############################################################################
## funcção voltar home
def voltar_login():
    print('#'*40)
    print('Tente novamente Login[s/n]?')
    print('#'*40)
    opcao = input('Escolha uma opção:\n')
    if (opcao.lower() == 's'):
        main()
    else:
        print("Opção invalida tente novamente.")
        voltar_login()
##############################################################################
# Tipos de dados em python

# https://www.dio.me/articles/variaveis-e-constantes-em-python-compreendendo-a-fundacao-dos-dados


def main():
    # dados dos usuario
    USER = "talilo"
    SENHA = "123456"

    logo_programa()
    print('#'*40)
    print('Login no Banco de Dados.')
    # User entrada
    # print('Nome do usuario.')
    USER_IN = input('Nome do usuario:\n')
    #Senha entrada
    # print('Enserir senha:')
    SENHA_IN = input('Enserir senha:\n')
    print('#'*40)

    if USER==USER_IN and SENHA == SENHA_IN:
       print('Acesso autorizado ao sistema.')
       home()
    else:
        print('Nome do usuario ou senha incorreto.')
        voltar_login()

# chamada da função principal
main()

