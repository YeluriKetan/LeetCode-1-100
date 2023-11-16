SELECT
    T.customer_id
FROM (
    SELECT
        C.customer_id,
        COUNT(DISTINCT C.product_key) AS count
    FROM
        Product P INNER JOIN Customer C
            ON P.product_key = C.product_key
    GROUP BY
        C.customer_id) AS T CROSS JOIN (SELECT COUNT(*) AS count FROM Product) AS P_C
WHERE
    T.count = P_C.count