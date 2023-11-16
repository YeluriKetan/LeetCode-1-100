WITH VALID_2015 AS (
    SELECT
        tiv_2015
    FROM
        Insurance
    GROUP BY
        tiv_2015
    HAVING
        COUNT(tiv_2016) > 1),
VALID_LL AS (
    SELECT
        lat,
        lon
    FROM
        Insurance
    GROUP BY
        lat, lon
    HAVING
        COUNT(pid) = 1
)
SELECT
    ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM
    Insurance
WHERE
    tiv_2015 IN (SELECT * FROM VALID_2015)
        AND (lat, lon) IN (SELECT * FROM VALID_LL)