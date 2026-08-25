# Write your MySQL query statement below
SELECT t.person_name FROM (
    SELECT SUM(weight) OVER (ORDER BY turn) acc_sum, turn, person_name FROM Queue ORDER BY turn
) t
WHERE t.acc_sum <= 1000
ORDER BY t.turn DESC
LIMIT 1;