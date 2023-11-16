SELECT
    T.person_name
FROM
    (SELECT
        person_name,
        SUM(weight) OVER W as total
    FROM
        Queue
    WINDOW W AS (ORDER BY turn ROWS UNBOUNDED PRECEDING)
    ORDER BY
        total DESC) AS T
WHERE
    T.total <= 1000
LIMIT 1