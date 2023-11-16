WITH T AS (VALUES ROW('Low'), ROW('Average'), ROW('High'))
SELECT
    CONCAT(T.column_0, ' Salary') AS category,
    CASE
        WHEN T.column_0 = 'Low' THEN low
        WHEN T.column_0 = 'Average' THEN mid
        ELSE high
    END AS accounts_count
FROM
    T CROSS JOIN
(SELECT
    SUM(IF (income < 20000, 1, 0)) AS low,
    SUM(IF (income >= 20000 AND income <= 50000, 1, 0)) AS mid,
    SUM(IF (income > 50000, 1, 0)) AS high
FROM
    Accounts) AS B