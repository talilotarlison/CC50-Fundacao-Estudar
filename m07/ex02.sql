
-- EXEMPLOS DE FUNÇÕES NO SQLITE
-- AVG, COUNT ,DISTINCT , LOWER, MAX, MIN, UPPER

-- AVG: CALCULA A MÉDIA DOS VALORES EM UMA COLUNA
SELECT AVG(idade) AS media_idade FROM tb_pessoa;

-- COUNT: CONTA O NÚMERO DE REGISTROS
SELECT COUNT(*) AS total_pessoas FROM tb_pessoa;

-- DISTINCT: RETORNA VALORES ÚNICOS EM UMA COLUNA
SELECT DISTINCT(cidade) AS cidades_unicas FROM tb_pessoa;
SELECT DISTINCT(UPPER(title)) AS title_unicos FROM shows;

-- LOWER: CONVERTE OS VALORES DE UMA COLUNA PARA LETRAS MINÚSCULAS
SELECT LOWER(nome) AS nome_minusculo FROM tb_pessoa;

-- MAX: RETORNA O MAIOR VALOR EM UMA COLUNA
SELECT MAX(idade) AS idade_maxima FROM tb_pessoa;

-- MIN: RETORNA O MENOR VALOR EM UMA COLUNA
SELECT MIN(idade) AS idade_minima FROM tb_pessoa;

-- UPPER: CONVERTE OS VALORES DE UMA COLUNA PARA LETRAS MAIÚSCULAS
SELECT UPPER(nome) AS nome_maiusculo FROM tb_pessoa;