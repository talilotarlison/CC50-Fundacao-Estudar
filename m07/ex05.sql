-- normalização: processo de organização dos dados em um banco de dados para reduzir a redundância e melhorar a integridade dos dados
-- desnormalização: processo de combinação de tabelas para melhorar o desempenho em consultas, mas pode levar a redundância e inconsistência

CREATE TABLE shows (
    id INTEGER PRIMARY KEY,
    title TEXT NOT NULL
);

CREATE TABLE genres (
    show_id INTEGER,
    genre TEXT NOT NULL,
    FOREIGN KEY (show_id) REFERENCES shows (id)
);

INSERT INTO shows (id, title) VALUES
(1, 'Breaking Bad'),
(2, 'Stranger Things'),
(3, 'The Office');

INSERT INTO genres (show_id, genre) VALUES
(1, 'Drama'),
(1, 'Crime'),
(2, 'Sci-Fi'),
(2, 'Horror'),
(3, 'Comedy');

-- join: combina dados de duas ou mais tabelas com base em uma condição relacionada entre elas
-- inner join: retorna apenas os registros que têm correspondência em ambas as tabelas
-- left join: retorna todos os registros da tabela da esquerda e os registros correspondentes da tabela da direita
-- right join: retorna todos os registros da tabela da direita e os registros correspondentes da tabela da esquerda
SELECT 
    shows.id, 
    shows.title, 
    genres.genre
FROM 
    shows
JOIN 
    genres 
ON 
    shows.id = genres.show_id;

-- select: seleciona dados de uma tabela
select * from shows; -- seleciona todos os dados da tabela shows

-- exemplo de inner join
SELECT 
    shows.title, 
    COUNT(genres.genre) AS genre_count
FROM 
    shows
JOIN 
    genres 
ON 
    shows.id = genres.show_id
GROUP BY 
    shows.title;

-- droptable: exclui uma tabela ou banco de dados
drop table shows

-- ver esquema do banco de dados
.schema shows


select title from shows where id in (select show_id from genres where genre = 'Drama');
select title from shows where id in (select show_id from genres where genre = 'Drama' and genre = 'Crime');

-- criar um índice para melhorar a busca no banco
CREATE INDEX idx_genres_show_id ON genres (show_id);

-- b-tree: estrutura de dados em árvore balanceada que permite buscas eficientes em grandes conjuntos de dados. é usada para armazenar dados em bancos de dados relacionais e sistemas de arquivos.
-- hash: estrutura de dados que usa uma função hash para mapear chaves a valores. é usada para buscas rápidas em conjuntos de dados pequenos a médios, mas não é adequada para buscas ordenadas.
-- bitmap: estrutura de dados que usa um vetor de bits para representar a presença ou ausência de valores em um conjunto de dados. é usada para consultas analíticas em grandes conjuntos de dados, mas não é adequada para atualizações frequentes.
-- clustered index: índice que determina a ordem física dos dados em uma tabela. é usado para melhorar o desempenho de consultas que acessam dados em ordem.
-- non-clustered index: índice que não determina a ordem física dos dados em uma tabela. é usado para melhorar o desempenho de consultas que acessam dados em qualquer ordem.
-- full-text index: índice que permite buscas eficientes em grandes conjuntos de dados de texto. é usado para melhorar o desempenho de consultas que acessam dados de texto.
-- spatial index: índice que permite buscas eficientes em grandes conjuntos de dados espaciais. é usado para melhorar o desempenho de consultas que acessam dados espaciais.
-- hash index: índice que usa uma função hash para mapear chaves a valores. é usado para buscas rápidas em conjuntos de dados pequenos a médios, mas não é adequado para buscas ordenadas.
