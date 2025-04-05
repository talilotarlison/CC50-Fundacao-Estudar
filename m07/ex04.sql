CREATE TABLE shows (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    title TEXT NOT NULL,
    data TEXT NOT NULL,
    local TEXT NOT NULL
);
--  insert into tb_pessoa (nome, idade, cidade) values
INSERT INTO shows (title, data, local) VALUES 
('Breaking Bad', '2008-01-20', 'USA'),
('Stranger Things', '2016-07-15', 'USA'),
('Dark', '2017-12-01', 'Germany'),
('The Crown', '2016-11-04', 'UK');

-- tipos de dados sqlite

-- INTEGER: NÚMEROS INTEIROS    
-- REAL: NÚMEROS DECIMAIS
-- TEXT: TEXTO
-- BLOB: DADOS BINÁRIOS
-- NULL: VALOR NULO


-- not null: não pode ser nulo
-- unique: não pode ser repetido
-- default: valor padrão