-- 코드를 입력하세요
select date_format(sales_date,"%Y-%m-%d") as sales_date,product_id,user_id,sum(sales_amount) as sales_amount
from (SELECT * from online_sale
union
select offline_sale_id, NULL as user_id, product_id, sales_amount, sales_date from offline_sale) as a
where sales_date like "2022-03-%"
group by sales_date,product_id,user_id
order by sales_date,product_id,user_id