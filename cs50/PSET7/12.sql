select DISTINCT(title) from movies
INNeR join stars on movies.id = stars.movie_id
INNER join people on stars.person_id = people.id
WHERE name in ('Johnny Depp','Helena Bonham Carter')
GROUP by movie_id
having COUNT(distinct person_id) = 2
