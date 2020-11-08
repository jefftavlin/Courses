SELECT DISTINCT(name) from people join stars on people.id = stars.person_id join movies on stars.movie_id = movies.id WHERE year = 2004 ORDER BY birth
