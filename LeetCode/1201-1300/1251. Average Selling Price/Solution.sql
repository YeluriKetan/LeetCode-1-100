SELECT
    P.product_id,
    IFNULL(ROUND(SUM(P.price * IFNULL(U.units, 0)) / SUM(IFNULL(U.units, 0)), 2), 0) AS average_price
FROM
    Prices P LEFT JOIN UnitsSold U
        ON P.product_id = U.product_id
            AND U.purchase_date BETWEEN P.start_date AND P.end_date
GROUP BY
    P.product_id