-- Para ordenar os resultados de uma consulta SQL em ordem decrescente com base em uma coluna específica, você pode usar a cláusula ORDER BY seguida do nome da coluna e da palavra-chave DESC.

SELECT *
FROM sua_tabela
ORDER BY sua_coluna DESC;

-- Se você tiver uma tabela chamada vendas e quiser ordenar os resultados pela coluna quantidade em ordem decrescente, a consulta seria:

Copy code
SELECT *
FROM vendas
ORDER BY quantidade DESC;