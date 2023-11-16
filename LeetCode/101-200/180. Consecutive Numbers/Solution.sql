SELECT
    DISTINCT num AS ConsecutiveNums
FROM
    (SELECT
        id,
        num,
        MIN(num) OVER W AS min,
        MAX(num) OVER W AS max,
        COUNT(num) OVER W AS count
    FROM
        Logs
    WINDOW W AS (ROWS BETWEEN 1 PRECEDING AND 1 FOLLOWING)) AS T
WHERE
    min = max
        AND count = 3