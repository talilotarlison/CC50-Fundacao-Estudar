-- comandos usados:
-- https://www.w3schools.com/sql/sql_ref_keywords.asp


-- Tipos de dados mais comuns no SQLite:

-- 1. INTEGER: Usado para armazenar números inteiros. eles podem ser positivos ou negativos.
-- 2. REAL: Usado para armazenar números de ponto flutuante.
-- 3. TEXT: Usado para armazenar strings de texto. eles podem ser de qualquer comprimento. varchar(255) é um exemplo.

-- 4. BLOB: Usado para armazenar dados binários, como imagens ou arquivos.
-- 5. NULL: Representa um valor nulo ou ausente.

-- Observação: SQLite é tipicamente dinâmico com tipos de dados e utiliza "type affinity" para determinar como armazenar valores.

SELECT UPPER(TRIM(title)), COUNT(title) FROM shows GROUP BY UPPER(TRIM(title)) ORDER BY COUNT(title) DESC LIMIT 10;

SELECT UPPER(title), COUNT(title) FROM shows GROUP BY UPPER(title) ORDER BY COUNT(title) DESC LIMIT 10;

SELECT UPPER(title), COUNT(title) FROM shows GROUP BY UPPER(title) ORDER BY COUNT(title);

SELECT UPPER(title), COUNT(title) FROM shows GROUP BY UPPER(title);

SELECT DISTINCT(UPPER(title)) FROM shows ORDER BY UPPER(title);

SELECT title FROM shows WHERE title LIKE "%Office%";

SELECT title FROM shows WHERE genres LIKE "%Comedy%";

INSERT INTO shows (Timestamp, title, genres) VALUES("now", "The Muppet Show", "Comedy, Musical"); 

DELETE FROM shows WHERE title LIKE "Friends";

-- Acontece que o SQL também tem seus próprios tipos de dados para otimizar a quantidade de espaço usado para armazenar dados, que precisaremos especificar ao criar uma tabela manualmente:

-- BLOB, para "Objeto binário grande", dados binários brutos que podem representar arquivos

-- INTEGER

-- NUMERIC, como um número, mas não exatamente um número, como uma data ou hora

-- REAL, para valores de ponto flutuante

-- TEXT, como strings

-- As colunas também podem ter atributos adicionais:

-- NOT NULL, que especifica que deve haver algum valor

-- UNIQUE, o que significa que o valor dessa coluna deve ser único para cada linha da tabela

-- PRIMARY KEY, como a coluna id acima, que será usada para identificar de forma única cada linha

-- FOREIGN KEY, como a coluna show_id acima que se refere a uma coluna em alguma outra tabela

 SELECT title FROM shows WHERE id IN (SELECT show_id FROM genres WHERE genre = "Musical");

 SELECT DISTINCT(genre) FROM genres WHERE show_id IN (SELECT id FROM shows WHERE title = "THE OFFICE") ORDER BY genre;

--  Acontece que também existem subtipos para uma coluna, que podemos ser ainda mais específicos com:

-- INTEGER

-- smallint , com menos bits

-- integer

-- bigint , com mais bits

-- NUMERIC

-- boolean

-- date

-- datetime

-- numeric(scale, precision) , com um número fixo de dígitos

-- time

-- timestamp

-- REAL

-- real

-- double precision , com o dobro de bits

-- TEXTO

-- char(n) , um número fixo de caracteres

-- varchar(n) , um número variável de caracteres, até algum limite n

-- text, uma string sem limite

-- SQL Commands are mainly categorized into five categories: 
-- https://www.geeksforgeeks.org/sql-ddl-dql-dml-dcl-tcl-commands/

-- DDL – Data Definition Language
-- DQL – Data Query Language
-- DML – Data Manipulation Language
-- DCL – Data Control Language
-- TCL – Transaction Control Language