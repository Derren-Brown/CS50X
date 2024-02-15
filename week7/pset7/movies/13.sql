SELECT DISTINCT(name) FROM people
JOIN stars ON stars.person_id = people.id
WHERE person_id IN (
    SELECT DISTINCT(person_id) FROM stars
    WHERE stars.movie_id IN (
        SELECT stars.movie_id FROM stars
        JOIN people ON people.id = stars.person_id
        WHERE people.name = 'Kevin Bacon'
        AND people.birth = 1958
    )
)
AND stars.person_id != (SELECT id FROM people WHERE name = "Kevin Bacon");