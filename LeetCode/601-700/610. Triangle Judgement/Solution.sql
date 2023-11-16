SELECT
    *,
    IF(x + y > z && y + z > x && z + x > y, 'Yes', 'No') AS triangle
FROM
    Triangle