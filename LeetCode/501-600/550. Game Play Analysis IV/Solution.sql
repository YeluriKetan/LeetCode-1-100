WITH valid_player_count AS (
    SELECT
        COUNT(*) as count
    FROM
        (SELECT
            player_id,
            MIN(event_date) as min_event_date
        FROM
            Activity
        GROUP BY
            player_id
        ) AS A INNER JOIN Activity B
            ON A.player_id = B.player_id
                AND A.min_event_date = SUBDATE(B.event_date, 1)),
total_player_count AS (
    SELECT
        COUNT(DISTINCT player_id) as count
    FROM
        ACTIVITY)
SELECT
    ROUND(V.count / T.count, 2) as fraction
FROM
    valid_player_count V CROSS JOIN total_player_count T