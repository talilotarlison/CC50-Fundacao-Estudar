-- sqlite3 songs.db --
-- liste músicas que tenham dançabilidade, energia e valência maior que 0,75 --

SELECT name from songs WHERE (danceability > 0.75 AND energy > 0.75 AND valence > 0.75);