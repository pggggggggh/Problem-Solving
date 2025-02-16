-- 코드를 입력하세요
select distinct cart_id
from cart_products as b
where exists (select * from cart_products as a where b.cart_id = a.cart_id and a.name="Yogurt") and
exists (select * from cart_products as a where b.cart_id = a.cart_id and a.name="Milk") 
order by cart_id