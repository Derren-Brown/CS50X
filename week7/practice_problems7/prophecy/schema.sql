CREATE TABLE students(
    id INTEGER,
    student_name TEXT,
    PRIMARY KEY(id)
);
CREATE TABLE houses(
    id INTEGER,
    house TEXT,
    head TEXT,
    PRIMARY KEY(id)
);
CREATE TABLE house_assignment(
    student_id INTEGER,
    house_id INTEGER,
    FOREIGN KEY(student_id) REFERENCES students(id),
    FOREIGN KEY(house_id) REFERENCES houses(id),
    PRIMARY KEY(student_id, house_id)
);
INSERT INTO houses(id, house, head)
VALUES (1, 'Slytherin', 'Severus Snape');
INSERT INTO houses(id, house, head)
VALUES (2, 'Ravenclaw', 'Filius Flitwick');
INSERT INTO houses(id, house, head)
VALUES (3, 'Hufflepuff', 'Pomona Sprout');
INSERT INTO houses(id, house, head)
VALUES (4, 'Gryffindor', 'Minerva McGonagall');