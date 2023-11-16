(WITH C AS (
    SELECT
        user_id,
        COUNT(rating) AS movie_count
    FROM
        MovieRating
    GROUP BY
        user_id)
SELECT
    U.name AS results
FROM
    C INNER JOIN Users U
        ON C.user_id = U.user_id
WHERE
    C.movie_count = (SELECT MAX(C.movie_count) FROM C)
ORDER BY
    U.name
LIMIT 1)

UNION

(WITH R AS (
    SELECT
        movie_id,
        AVG(rating) as avg_rating
    FROM
        MovieRating
    WHERE
        MONTH(created_at) = 2
            AND YEAR(created_at) = 2020
    GROUP BY
        movie_id)
SELECT
    M.title AS results
FROM
    R INNER JOIN Movies M
        ON R.movie_id = M.movie_id
WHERE
    R.avg_rating = (SELECT MAX(avg_rating) FROM R)
ORDER BY
    M.title
LIMIT 1)