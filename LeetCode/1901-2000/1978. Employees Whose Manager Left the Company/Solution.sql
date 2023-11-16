SELECT
    A.employee_id
FROM
    Employees A LEFT JOIN Employees B
        ON A.manager_id = B.employee_id
WHERE
    A.manager_id IS NOT NULL
    AND B.employee_id IS NULL
    AND A.salary < 30000
ORDER BY
    A.employee_id