
-- normalizada: separa os dados em tabelas diferentes para evitar redundância e garantir integridade referencial
-- desnormalizada: armazena os dados em uma única tabela, o que pode levar a redundância e inconsistência

CREATE TABLE shows (
    id INTEGER PRIMARY KEY,
    title TEXT NOT NULL
);

CREATE TABLE genres (
    id INTEGER PRIMARY KEY,
    name TEXT NOT NULL
);

CREATE TABLE shows_genres (
    show_id INTEGER NOT NULL,
    genre_id INTEGER NOT NULL,
    PRIMARY KEY (show_id, genre_id),
    FOREIGN KEY (show_id) REFERENCES shows (id),
    FOREIGN KEY (genre_id) REFERENCES genres (id)
);


-- O nome do diagrama para este banco de dados pode ser chamado de "Diagrama de Relacionamento de Entidades (ERD) DIR em portugues".
-- Ele representa as tabelas (entidades) e seus relacionamentos.

-- O diagrama pode incluir as seguintes entidades:
-- 1. Tabela "shows" (programas de TV ou filmes)
-- 2. Tabela "genres" (gêneros)
-- 3. Tabela "shows_genres" (relacionamento entre shows e gêneros)


-- O relacionamento entre as tabelas é do tipo "muitos para muitos", pois um show pode ter vários gêneros e um gênero pode ser associado a vários shows.
