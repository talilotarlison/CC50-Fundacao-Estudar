-- sqlite3 songs.db --
-- lista os nomes das músicas que apresentam feat --

SELECT name FROM songs WHERE name LIKE "%feat.%";