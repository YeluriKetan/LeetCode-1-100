SELECT
    ROUND(AVG(IF (D.order_date = D.customer_pref_delivery_date, 100, 0)), 2) as immediate_percentage
FROM (
    SELECT
        customer_id,
        MIN(order_date) as min_order_date
    FROM
        Delivery
    GROUP BY
        customer_id
) AS M INNER JOIN Delivery D
    ON M.customer_id = D.customer_id
        AND M.min_order_date = D.order_date