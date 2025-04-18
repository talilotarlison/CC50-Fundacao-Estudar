
-- Pessoas que dirigiram um filme que recebeu uma classificação de pelo menos 9,0 --

SELECT DISTINCT people.name
FROM people JOIN directors ON people.id = directors.person_id
HERE directors.movie_id IN (SELECT movie_id FROM ratings WHERE rating >= 9.0);