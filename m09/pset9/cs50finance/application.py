from flask import Flask, render_template, request, redirect, url_for,session,render_template, flash
import sqlite3
import hashlib
import random
from operator import neg

# Importando o módulo Flask
app = Flask(__name__)
app.secret_key = "7cdbf96f878b6816abdecd3f564a897ab393cecds697er3z1680e6r87er2g35g6514"  # Troque por uma chave segura!

# hash para senha
def hash_password(password):
    # Converte a senha para md5
    md5 = hashlib.md5()
    message = password.encode()
    md5.update(message)
    hash_senha_md5 = md5.hexdigest()
    return hash_senha_md5

# rota pagina login no sistema
@app.route('/')
def index():
    if not session.get('usuario_logado'):
            return render_template('index.html')
    else:
         return redirect(url_for('home'))  # Redireciona para a rota 'home'

# funcao verificar permicao login
def validar_login(nome, senha):
    # Converte a senha para md5
    senha_md5 = hash_password(senha)
    # Conectando ao banco de dados
    conn = sqlite3.connect('finance.db')
    cursor = conn.cursor()

    # Query segura (evita SQL Injection)
    cursor.execute("SELECT id FROM usuario WHERE nome = ? AND senha = ?",(nome, senha_md5))

    # Verifica se o usuário e a senha estão corretos
    resultado = cursor.fetchone()  # Retorna None se não encontrar
    conn.close()

    return resultado is not None  # True se login for válido

# adicionar bonus na conta
def fazer_compra_acoes(symbol,name,shares,price):
    conn = sqlite3.connect('finance.db')
    cursor = conn.cursor()
    # Query segura (evita SQL Injection)
    cursor.execute("INSERT INTO finance (Symbol,Name,Shares,Price) VALUES (?,?,?,? )",(symbol,name,shares,price))

    conn.commit() # commit necessário para persistir a alteração
    conn.close()

# adicionar bonus na conta
def add_log(symbol,shares,price):
    conn = sqlite3.connect('finance.db')
    cursor = conn.cursor()
    # Query segura (evita SQL Injection)
    cursor.execute("INSERT INTO logs_transacoes (Symbol,Shares,Price) VALUES (?,?,?)",(symbol,shares,price))

    conn.commit() # commit necessário para persistir a alteração
    conn.close()

# rota para logar usuario
@app.route('/login',methods=['POST'])
def login():
    nome = request.form.get('nome')
    senha = request.form.get('senha')
    # Verifica se o usuário e a senha estão corretos
    # Conectando ao banco de dados
    login_permitido = validar_login(nome, senha)

    if(login_permitido):
        session['usuario_logado'] = nome
        usuario = session.get('usuario_logado')
        dados = todas_transacoes()
        # Calcular o total geral

        total = soma_transacoes(dados)
        # Renderizar o template com os dados

        return render_template('home.html', registros=dados, total_geral=total,usuario=usuario.capitalize())
    else:
        return render_template('index.html', msg_erro="Usuario ou senha Invalidos!!")

# rota pagina criar novo usuario
@app.route('/registerPage')
def registerPage():
      return render_template('register.html')


# verificar se email ja existe
def verificar_email(nome, email):
    conn = sqlite3.connect('finance.db')
    cursor = conn.cursor()
    # Query segura (evita SQL Injection)
    cursor.execute("SELECT id FROM usuario WHERE nome = ? OR email = ?",(nome,email))

    resultado = cursor.fetchone()  # Retorna None se não encontrar
    conn.close()
    return resultado is not None  # True se login for válido

# funcao cria usuario no banco
def criar_usuario(nome, email ,senha):

        conn = sqlite3.connect('finance.db')
        cursor = conn.cursor()
        # Converte a senha para md5
        hash_senha_md5 = hash_password(senha)
        cursor.execute("INSERT INTO usuario (nome, email, senha) VALUES (?,?,?)", (nome,email,hash_senha_md5))
        conn.commit()
        conn.close()

# rota cadastar novo usuario
@app.route('/register',methods=['POST'])
def register():
    # Obtendo dados do formulário
    nome = request.form.get('nome')
    email = request.form.get('email')
    senha = request.form.get('senha')
    senha_confirme = request.form.get('senha_confirme')
    senha_validada = None
    if(senha == senha_confirme):
        senha_validada = senha
        # verificar se email ja existe, caso contrario nao pode ser cadastrado
        usuario_existe = verificar_email(nome,email)
        if(usuario_existe):
            return render_template('register.html', msg_erro="Nome do usuario ou email, ja existe!!")
        else:
            criar_usuario(nome, email ,senha_validada)
            cash = {
                "symbol": f'CASH{random.randint(10000, 99999)}B',
                "name": "CASHBANK",
                "shares": 1,
                "price": 10000
            }

            fazer_compra_acoes(cash["symbol"], cash["name"], cash["shares"], cash["price"])  # Symbol, Name, Shares, Price
            add_log(cash["symbol"], cash["shares"], cash["price"])  # Symbol, Shares, Price
            return render_template('register.html', msg_sucess="Cadastrado com Sucesso!!")
    else:
        return render_template('register.html',msg_erro="Erro ao cadastrar usuario, senha não confere!!")

# funcao que busca todas os logs transacoes
def todos_logs_transacoes():
        conn = sqlite3.connect('finance.db')
        cursor = conn.cursor()
        # Query segura (evita SQL Injection)
        cursor.execute("SELECT * FROM logs_transacoes ORDER BY id DESC")
        # Fetch all rows from the query result
        logs = cursor.fetchall()  # Retorna uma lista de tuplas com todos os registros -> https://pythoniluminado.netlify.app/tuplas
        conn.close()
        return logs


# rota historico de compra de acoes
@app.route('/history')
def history():
    if not session.get('usuario_logado'):
        return render_template('index.html')
    else:
        logs = todos_logs_transacoes()
        return render_template('history.html',registros=logs)

# funcao verificar acoes
def busca_acoes(simbolo):
    conn = sqlite3.connect('finance.db')
    cursor = conn.cursor()
    # Query segura (evita SQL Injection)
    cursor.execute("SELECT * FROM acoes WHERE simbolo = ? ", (simbolo,))
    resultado = cursor.fetchone()  # Retorna None se não encontrar
    conn.close()

    return resultado # True se login for válido

# rota Quote buscar
@app.route('/quoteBusca',methods=['POST'])
def quoteBusca():
    if not session.get('usuario_logado'):
        return render_template('index.html')
    else:
        simbolo = request.form.get('simbolo')
        # verificar se acoes existe
        acao_existe = busca_acoes(simbolo)
        if(acao_existe):
             return render_template('quote.html',  nome=acao_existe[1], company=acao_existe[2],preco=acao_existe[4], msg_sucess="Ação encontrada com sucesso!!")
        else:
            return render_template('quote.html', msg_erro="Ação não existe!!")

# rota Quote
@app.route('/quote')
def quote():
    if not session.get('usuario_logado'):
        return render_template('index.html')
    else:
        return render_template('quote.html')

# rota Buy
@app.route('/buy')
def buy():
    if not session.get('usuario_logado'):
        return render_template('index.html')
    else:
        return render_template('buy.html')

# rota Sell
@app.route('/sell')
def sell():
    if not session.get('usuario_logado'):
        return render_template('index.html')
    else:
        minha_acoes =  todas_transacoes()
        return render_template('sell.html',acoes=minha_acoes)

# funcao que busca todas as transacoes
def todas_transacoes():
        conn = sqlite3.connect('finance.db')
        cursor = conn.cursor()
        # Query segura (evita SQL Injection)
        cursor.execute("SELECT * FROM finance ORDER BY id DESC")
        # Fetch all rows from the query result
        dados = cursor.fetchall()  # Retorna uma lista de tuplas com todos os registros -> https://pythoniluminado.netlify.app/tuplas
        conn.close()
        return dados

# funcao que busca todas as transacoes
def soma_transacoes(dados):
        total = 0
        for row in dados:
                total += row[3] * row[4]
        return total

# rota Home
@app.route('/home')
def home():
    if not session.get('usuario_logado'):
        return render_template('index.html')
    else:
        usuario = session.get('usuario_logado')
        dados = todas_transacoes()
        # Calcular o total geral
        total = soma_transacoes(dados)
        # Renderizar o template com os dados
        return render_template('home.html', registros=dados, total_geral=total,usuario=usuario.capitalize())

# rota LogOut
@app.route('/logout')
def logout():
    session.pop('usuario_logado', None)
    return render_template('index.html')

# funcao traz dados da acoes que vai comprar dpois de verificar se existe
def busca_dados_acao(simbolo):
    conn = sqlite3.connect('finance.db')
    cursor = conn.cursor()
    # Query segura (evita SQL Injection)
    cursor.execute("SELECT * FROM acoes WHERE simbolo = ? ", (simbolo,))
    resultado = cursor.fetchall()  # Retorna None se não encontrar
    conn.close()

    return resultado # retorna os dados da acao buscada

# rota compra de acoes
@app.route('/compraAcoes',methods=['POST'])
def compraAcoes():
     # Obtendo dados do formulário
    simbolo = request.form.get('simbolo')
    quantidade = request.form.get('quantidade')

    # verificar se acoes existe
    acao_existe = busca_acoes(simbolo)
    if(acao_existe):
        dados_acao = busca_dados_acao(simbolo)
        acao_comprada = {
            "symbol": f'{dados_acao[0][1]}{random.randint(10000, 99999)}C',
            "name": dados_acao[0][2],
            "shares": quantidade,
            "price": dados_acao[0][4]
        }

        fazer_compra_acoes(acao_comprada["symbol"], acao_comprada["name"], acao_comprada["shares"], acao_comprada["price"])  # Symbol, Name, Shares, Price
        add_log(acao_comprada["symbol"], acao_comprada["shares"], acao_comprada["price"])  # Symbol, Shares, Price
        return redirect(url_for('home'))  # Redireciona para a rota 'home'
    else:
        return render_template('buy.html', msg_erro="Ação não existe!!")

# funcao traz dados da acoes que vai comprar dpois de verificar se existe
def vender_minha_acao(id):
    conn = sqlite3.connect('finance.db')
    cursor = conn.cursor()
    # Query segura (evita SQL Injection)
    cursor.execute("DELETE FROM finance WHERE id = ? ", (id,))
    conn.commit()  # Commit the transaction to apply the deletion
    conn.close()
    return True  # Indicate successful deletion

# busca dados da acao que vai vender dpois de verificar se existe
def busca_acao_vendida(id):
    conn = sqlite3.connect('finance.db')
    cursor = conn.cursor()
    # Query segura (evita SQL Injection)
    cursor.execute("SELECT * FROM finance WHERE id = ? ", (id,))
    resultado = cursor.fetchall()  # Retorna None se não encontrar
    conn.close()

    return resultado # retorna os dados da acao buscada
    
# rota vender acoes
@app.route('/vender', methods=['POST'])
def vender():
    minha_acoes =  todas_transacoes()
    if request.method == "POST":
        id = request.form.get('id') # Usar request.form.get para dados de formulário em post
        acao_vendida = busca_acao_vendida(id)
        # dados da acao que foi vendida

        dados_acao_vendida = {
            "symbol": f'{acao_vendida[0][1]}V',
            "shares": neg(acao_vendida[0][3]),
            "price": acao_vendida[0][4]
        }

        # print(dados_acao_vendida)
        add_log(dados_acao_vendida["symbol"], dados_acao_vendida["shares"], dados_acao_vendida["price"])
        vender_minha_acao(id)

        return render_template('sell.html', acoes=minha_acoes, msg="Ação vendida com sucesso!!")
    else:
        return render_template('sell.html', msg="Erro ao vender ação!!")

if __name__ == '__main__':
    app.run(debug=True)