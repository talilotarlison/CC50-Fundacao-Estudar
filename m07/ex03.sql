
-- EXEMPLOS DE COMANDOS SQL NO SQLITE
--  WHERER, LIKE, ORDER BY, LIMIT, GROUP BY EM SQL LITE

-- WHERE: FILTRA OS REGISTROS COM BASE EM UMA CONDIÇÃO
SELECT * FROM tb_pessoa WHERE idade > 30;
SELECT title FROM shows WHERE title title = "THE WALKING DEAD";
SELECT title FROM shows WHERE title = "THE WALKING DEAD";
SELECT title FROM shows WHERE title = "THE WALKING DEAD" AND data = "2023-10-01";


-- LIKE: FILTRA OS REGISTROS COM BASE EM UM PADRÃO
SELECT * FROM tb_pessoa WHERE nome LIKE 'J%';
SELECT title FROM shows WHERE title LIKE "%WALKING%";

-- ORDER BY: ORDENA OS REGISTROS POR UMA OU MAIS COLUNAS
SELECT * FROM tb_pessoa ORDER BY idade DESC;

-- LIMIT: LIMITA O NÚMERO DE REGISTROS RETORNADOS
SELECT * FROM tb_pessoa ORDER BY idade DESC LIMIT 5;

-- GROUP BY: AGRUPA OS REGISTROS POR UMA OU MAIS COLUNAS
SELECT cidade, COUNT(*) AS total_pessoas FROM tb_pessoa GROUP BY cidade;
selec upper(title), count(title) from shows group by title;
SELECT title, COUNT(*) AS total_shows FROM shows GROUP BY title desc limit 15;  
SELECT title, COUNT(*) AS total_shows FROM shows GROUP BY title HAVING COUNT(*) > 1;