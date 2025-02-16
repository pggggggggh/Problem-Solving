-- 코드를 입력하세요
SELECT flavor
from ((select * from first_half) union (select * from july)) as a
group by flavor
order by sum(total_order) desc
limit 3