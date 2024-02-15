import csv
from cs50 import SQL

db = SQL("sqlite:///roster.db")
with open('students.csv', 'r') as f:
    reader = csv.DictReader(f)
    for row in reader:
        db.execute("INSERT OR IGNORE INTO students(id, student_name) VALUES(?, ?)", row["id"], row["student_name"])
        house_id = db.execute("SELECT id FROM houses WHERE house = ?", row["house"])
        db.execute("INSERT INTO house_assignment(student_id, house_id) VALUES(?, ?)", row["id"], house_id[0]["id"])