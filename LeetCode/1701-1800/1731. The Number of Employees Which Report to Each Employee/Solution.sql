SELECT
    A.employee_id,
    A.name,
    COUNT(B.employee_id) AS reports_count,
    ROUND(AVG(B.age), 0) AS average_age
FROM
    Employees A INNER JOIN Employees B
        ON A.employee_id = B.reports_to
GROUP BY
    A.employee_id
ORDER BY
    A.employee_id