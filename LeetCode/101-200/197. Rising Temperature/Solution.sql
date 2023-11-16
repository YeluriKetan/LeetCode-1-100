SELECT
    A.id
FROM
    Weather A INNER JOIN Weather B
        ON A.recordDate = ADDDATE(B.recordDate, 1)
            AND A.temperature > B.temperature