```markdown
# Flask: Criando Aplicações Web

## Introdução ao Flask

Usaremos Python e a biblioteca Flask para criar nosso próprio servidor web. O Flask é um framework que organiza o código de maneira específica, com a seguinte estrutura:

```
application.py
requirements.txt
static/
templates/
```

- **application.py**: Contém o código Python do servidor web.
- **requirements.txt**: Lista de bibliotecas necessárias.
- **static/**: Diretório para arquivos estáticos (CSS, JS).
- **templates/**: Diretório para arquivos HTML.

O Flask segue o padrão de design **MVC (Model-View-Controller)**:
- **Controller**: Lógica do aplicativo (código Python).
- **View**: Interface do usuário (HTML, CSS).
- **Model**: Dados do aplicativo (banco de dados, arquivos).

---

## Exemplo Básico

```python
from flask import Flask

app = Flask(__name__)

@app.route("/")
def index():
    return "hello, world"
```

- `@app.route("/")`: Define a rota para a página inicial.
- `flask run`: Inicia o servidor.

---

## Renderizando HTML

```python
from flask import Flask, render_template

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")
```

- Crie um arquivo `templates/index.html` com o conteúdo HTML desejado.

---

## Trabalhando com Argumentos

```python
from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html", name=request.args.get("name", "world"))
```

- Use `{{ name }}` no HTML para exibir o valor do argumento.

---

## Formulários e Métodos HTTP

### GET
```html
<form action="/greet" method="get">
    <input name="name" type="text">
    <input type="submit">
</form>
```

### POST
```html
<form action="/greet" method="post">
    <input name="name" type="text">
    <input type="submit">
</form>
```

```python
@app.route("/greet", methods=["POST"])
def greet():
    return render_template("greet.html", name=request.form.get("name", "world"))
```

---

## Layouts e Templates

### layout.html
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <title>hello</title>
    </head>
    <body>
        {% block body %}{% endblock %}
    </body>
</html>
```

### index.html
```html
{% extends "layout.html" %}
{% block body %}
    <form action="/greet" method="post">
        <input name="name" type="text">
        <input type="submit">
    </form>
{% endblock %}
```

---

## Aplicação Frosh IMs

### Estrutura
- **SPORTS**: Lista de esportes.
- **REGISTRANTS**: Dicionário para armazenar registros.

### Código
```python
from flask import Flask, render_template, request

app = Flask(__name__)

SPORTS = ["Dodgeball", "Soccer", "Volleyball"]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/register", methods=["POST"])
def register():
    name = request.form.get("name")
    sport = request.form.get("sport")
    if not name or sport not in SPORTS:
        return render_template("failure.html")
    return render_template("success.html")
```

### index.html
```html
<form action="/register" method="post">
    <input name="name" type="text">
    <select name="sport">
        {% for sport in sports %}
            <option value="{{ sport }}">{{ sport }}</option>
        {% endfor %}
    </select>
    <input type="submit">
</form>
```

---

## Banco de Dados com SQLite

### Configuração
```python
from cs50 import SQL

db = SQL("sqlite:///froshims.db")
```

### Inserção e Consulta
```python
@app.route("/register", methods=["POST"])
def register():
    db.execute("INSERT INTO registrants (name, sport) VALUES(?, ?)", name, sport)

@app.route("/registrants")
def registrants():
    registrants = db.execute("SELECT * FROM registrants")
    return render_template("registrants.html", registrants=registrants)
```

---

## Sessões e Cookies

### Configuração
```python
from flask import Flask, session
from flask_session import Session

app = Flask(__name__)
app.config["SESSION_TYPE"] = "filesystem"
Session(app)
```

### Uso
```python
@app.route("/login", methods=["POST"])
def login():
    session["name"] = request.form.get("name")
    return redirect("/")

@app.route("/logout")
def logout():
    session.clear()
    return redirect("/")
```

---

## AJAX com JavaScript

### Backend
```python
@app.route("/search")
def search():
    shows = db.execute("SELECT * FROM shows WHERE title LIKE ?", "%" + request.args.get("q") + "%")
    return jsonify(shows)
```

### Frontend
```html
<script>
    let input = document.querySelector('input');
    input.addEventListener('keyup', function() {
        $.get('/search?q=' + input.value, function(shows) {
            let html = '';
            for (let show of shows) {
                html += `<li>${show.title}</li>`;
            }
            document.querySelector('ul').innerHTML = html;
        });
    });
</script>
```
