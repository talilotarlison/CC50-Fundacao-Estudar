CREATE TABLE usuario (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    nome TEXT NOT NULL,
    email TEXT UNIQUE NOT NULL,
    senha TEXT NOT NULL
);

CREATE TABLE finance (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    Symbol TEXT NOT NULL UNIQUE,
    Name TEXT NOT NULL,
    Shares REAL,
    Price REAL
);


CREATE TABLE logs_transacoes (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    Symbol TEXT NOT NULL UNIQUE,
    Shares REAL,
    Price REAL,
    Data TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

DROP TABLE nome_da_tabela;

DROP TABLE IF EXISTS finance;

-- Criação do banco de dados
CREATE TABLE acoes (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    simbolo TEXT NOT NULL UNIQUE,
    nome_empresa TEXT NOT NULL,
    setor TEXT NOT NULL,
    preco_atual REAL NOT NULL,
    variacao_dia REAL,
    volume INTEGER,
    data_atualizacao TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Inserção de ações (dados baseados em valores reais aproximados)
INSERT INTO acoes (simbolo, nome_empresa, setor, preco_atual, variacao_dia, volume) VALUES
    ('PETR4', 'Petrobras', 'Energia', 32.50, 0.75, 125000000),
    ('VALE3', 'Vale S.A.', 'Mineração', 68.90, -1.20, 98000000),
    ('ITUB4', 'Itaú Unibanco', 'Financeiro', 26.75, 0.30, 85600000),
    ('BBDC4', 'Bradesco', 'Financeiro', 14.20, -0.50, 72300000),
    ('ABEV3', 'Ambev', 'Bebidas', 14.85, 0.15, 65400000),
    ('BBAS3', 'Banco do Brasil', 'Financeiro', 56.30, 0.80, 43200000),
    ('WEGE3', 'WEG', 'Industria', 36.75, 1.25, 32100000),
    ('RENT3', 'Localiza', 'Aluguel de Carros', 46.20, -0.90, 28700000),
    ('SUZB3', 'Suzano', 'Papel e Celulose', 52.60, 0.40, 25600000),
    ('BPAC11', 'BTG Pactual', 'Financeiro', 22.45, 0.55, 19800000),
    ('MGLU3', 'Magazine Luiza', 'Varejo', 2.15, -0.10, 187000000),
    ('CIEL3', 'Cielo', 'Meios de Pagamento', 4.30, 0.05, 14300000),
    ('LREN3', 'Lojas Renner', 'Varejo', 24.80, -0.35, 12600000),
    ('RAIL3', 'Rumo', 'Logística', 17.65, 0.25, 11800000),
    ('HAPV3', 'Hapvida', 'Saúde', 5.90, -0.20, 10700000),
    ('GGBR4', 'Gerdau', 'Siderurgia', 23.40, 0.30, 9800000),
    ('CSAN3', 'Cosan', 'Energia', 17.85, -0.15, 8700000),
    ('ELET3', 'Eletrobras', 'Energia', 42.10, 0.60, 7600000),
    ('BRFS3', 'BRF', 'Alimentos', 12.75, 0.05, 6900000),
    ('EMBR3', 'Embraer', 'Aeroespacial', 16.40, -0.30, 5400000);


SELECT * from finance;

INSERT INTO finance (Symbol,Name,Shares,Price) VALUES
('-','BONUS', 1, 10000.00);

SELECT * from acoes;


INSERT INTO logs_transacoes (Symbol,Shares,Price) VALUES
    ('BONUS', 1, 10000.00);

SELECT * from logs_transacoes;

SELECT * from finance
DELETE FROM finance