SELECT name from people
WHERE people.id in
	(SELECT person_id from stars WHERE movie_id in
     	(SELECT movie_id from stars where stars.person_id =
         	(SELECT people.id from people where name = 'Kevin Bacon' and birth = 1958)))
AND name != 'Kevin Bacon'
