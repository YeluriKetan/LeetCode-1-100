SELECT
    S.product_id,
    S.year as first_year,
    quantity,
    price
FROM (
    SELECT
        product_id,
        MIN(year) as year
    FROM 
        Sales
    GROUP BY
        product_id) AS min_year INNER JOIN Sales S
        ON min_year.product_id = S.product_id
            AND min_year.year = S.year