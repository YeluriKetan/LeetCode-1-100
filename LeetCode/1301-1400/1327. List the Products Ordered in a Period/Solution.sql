WITH T AS (
    SELECT
        product_id,
        SUM(unit) AS summed
    FROM
        Orders
    WHERE
        MONTH(order_date) = 2
            AND YEAR(order_date) = 2020
    GROUP BY
        product_id
    HAVING
        summed > 99)
SELECT
    P.product_name,
    T.summed AS unit
FROM
    T INNER JOIN Products P
        ON T.product_id = P.product_id