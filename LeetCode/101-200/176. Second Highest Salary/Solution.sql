WITH T AS (
    SELECT
        DISTINCT salary
    FROM
        Employee
    ORDER BY
        salary DESC
    LIMIT 2)
SELECT
    IF(MIN(salary) = MAX(salary), NULL, MIN(salary)) AS SecondHighestSalary
FROM
    T