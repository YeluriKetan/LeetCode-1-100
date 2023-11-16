WITH T AS (
    SELECT
        visited_on,
        SUM(amount) AS total
    FROM
        Customer
    GROUP BY
        visited_on),
F AS (
    SELECT
        visited_on,
        SUM(total) OVER W AS amount,
        AVG(total) OVER W AS average_amount,
        COUNT(total) OVER W AS count_days
    FROM
        T
    WINDOW W AS (ORDER BY visited_on ROWS 6 PRECEDING))
SELECT
    visited_on,
    amount,
    ROUND(average_amount, 2) AS average_amount
FROM
    F
WHERE
    count_days = 7