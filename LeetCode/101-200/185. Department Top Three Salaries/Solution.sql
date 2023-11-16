WITH T AS (
    SELECT DISTINCT
        departmentId,
        name,
        salary,
        DENSE_RANK() OVER W AS ranked
    FROM
        Employee
    WINDOW W AS (PARTITION BY departmentId ORDER BY salary DESC))
SELECT
    D.name AS Department,
    T.name AS Employee,
    T.salary AS Salary
    # T.ranked AS 'Rank'
FROM
    T INNER JOIN Department D
        ON T.departmentId = D.id
WHERE
    T.ranked < 4