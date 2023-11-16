SELECT
    A.name
FROM
    Employee A INNER JOIN Employee B
        ON A.id = B.managerId
GROUP BY
    A.id
HAVING
    COUNT(A.name) > 4