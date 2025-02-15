-- 코드를 입력하세요
SELECT a.car_id
from car_rental_company_car as a join car_rental_company_rental_history as b on a.car_id=b.car_id
where car_type = "세단" and a.car_id in (select car_id from car_rental_company_rental_history where month(start_date) = 10)
group by a.car_id
order by a.car_id desc