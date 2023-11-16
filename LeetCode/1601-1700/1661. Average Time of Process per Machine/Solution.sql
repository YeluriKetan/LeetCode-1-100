SELECT
    A.machine_id,
    ROUND(AVG(ABS(A.timestamp - B.timestamp)), 3) as processing_time
FROM
    Activity A INNER JOIN Activity B
        ON A.machine_id = B.machine_id
            AND A.machine_id = B.machine_id
            AND A.process_id = B.process_id
            AND A.activity_type <> B.activity_type
GROUP BY
    A.machine_id