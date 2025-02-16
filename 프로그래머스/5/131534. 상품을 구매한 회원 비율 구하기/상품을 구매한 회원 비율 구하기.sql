-- 코드를 입력하세요
with x as (
    select * from user_info where year(joined) = 2021
)
SELECT distinct year(sales_date) as year, month(sales_date) as month, 
(select count(distinct user_id) from online_sale where user_id in (select user_id from x) and year(sales_date) = year(a.sales_date) and month(sales_date) = month(a.sales_date)) as purhcased_users,
round((select count(distinct user_id) from online_sale where user_id in (select user_id from x) and year(sales_date) = year(a.sales_date) and month(sales_date) = month(a.sales_date))/(select count(*) from x),1) as purhcased_ratio
from online_sale as a
order by year, month