CREATE TABLE birthdays (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    month TEXT NOT NULL,
    day TEXT NOT NULL
);


INSERT INTO birthdays (name, month, day) VALUES ('Harry', '7', '31');
INSERT INTO birthdays (name, month, day) VALUES ('Ron', '3', '1');
INSERT INTO birthdays (name, month, day) VALUES ('Hermione', '9', '19');

select * from birthdays;

drop table birthdays;

DELETE FROM birthdays WHERE id = 7;
