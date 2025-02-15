-- 코드를 입력하세요
SELECT user_id,nickname,(
    select sum(price) from used_goods_board as b
    where b.writer_id = a.user_id and b.status = "done"
) as total_sales
from used_goods_user as a
having total_sales >= 700000
order by total_sales