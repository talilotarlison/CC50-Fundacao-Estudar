-- sqlite3 songs.db --
-- lista os nomes das músicas de Post Malone --

SELECT name FROM songs WHERE artist_id = (SELECT id FROM artists where name = "Post Malone");