-- sqlite3 songs.db --
--  retorne a energia média das músicas de Drake --

SELECT AVG(energy) from songs where artist_id = (SELECT id FROM artists where name = "Drake");