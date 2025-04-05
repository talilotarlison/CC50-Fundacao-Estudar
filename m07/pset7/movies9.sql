
--  Listar os nomes das pessoas que estrelaram um filme lançado em 2004, ordenado por ano de nascimento --

SELECT DISTINCT people.name
FROM people JOIN stars ON people.id = stars.person_id
WHERE stars.movie_id IN (SELECT id FROM movies WHERE year = 2004)
ORDER BY people.birth;