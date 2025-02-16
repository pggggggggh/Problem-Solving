-- 코드를 입력하세요
SELECT year(sales_date) as year, month(sales_date) as month, gender, count(distinct a.user_id) as users
from user_info as a join online_sale as b on a.user_id = b.user_id
where gender is not null
group by year(sales_date), month(sales_date), gender
order by year, month, gender