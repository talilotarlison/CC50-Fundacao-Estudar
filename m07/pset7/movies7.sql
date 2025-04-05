
-- Filmes lançados em 2010 e suas classificações, em ordem decrescente por classificação --
-- Para filmes com a mesma classificação, ordene-os em ordem alfabética por título --

SELECT movies.title, ratings.rating
FROM movies JOIN ratings ON movies.id = ratings.movie_id
WHERE movies.year = 2010 AND ratings.rating IS NOT NULL
ORDER BY ratings.rating DESC, movies.title ASC;