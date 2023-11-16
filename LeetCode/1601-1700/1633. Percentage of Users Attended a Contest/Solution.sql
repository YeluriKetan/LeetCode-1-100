WITH
    TOTAL AS (SELECT COUNT(*) AS total_count FROM USERS),
    REGISTERED AS (
        SELECT
            contest_id,
            COUNT(user_id) as registered_count
        FROM
            Register
        GROUP BY
            contest_id
    )
SELECT
    contest_id,
    ROUND(registered_count * 100 / total_count, 2) AS percentage
FROM
    REGISTERED CROSS JOIN TOTAL
ORDER BY
    percentage DESC, contest_id