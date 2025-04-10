-- CRIAÇÃO DE TABELA NO SQL LITE

-- COMANDO CRIA A TABELA tb_pessoa COM OS CAMPOS ID, NOME, IDADE E CIDADE
-- ID É A CHAVE PRIMÁRIA E AUTOINCREMENTA O VALOR
CREATE TABLE IF NOT EXISTS tb_pessoa (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    nome TEXT NOT NULL,
    idade INTEGER NOT NULL,
    cidade TEXT NOT NULL
);

CREATE TABLE shows (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    title TEXT NOT NULL,
    data TEXT NOT NULL,
    local TEXT NOT NULL
);

-- COMANDO SELECIONA PARA VERIFICAR SE A TABELA FOI CRIADA
SELECT * FROM tb_pessoa;
SELECT * FROM shows;

SELECT nome FROM shows;
SELECT nome FROM tb_pessoa;

SELECT nome FROM tb_pessoa WHERE nome LIKE 'A%';
SELECT nome FROM tb_pessoa WHERE nome LIKE '%A%';

