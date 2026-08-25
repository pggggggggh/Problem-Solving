# Write your MySQL query statement below
SELECT t2.person_name
FROM (
    SELECT LAG(t.acc_sum,1) OVER (ORDER BY turn) prev_acc_sum, t.acc_sum, t.person_name, t.turn FROM (
        SELECT SUM(weight) OVER (ORDER BY turn) acc_sum, turn, person_name FROM Queue ORDER BY turn
    ) t
) t2
WHERE t2.acc_sum <= 1000
ORDER BY t2.turn DESC
LIMIT 1;