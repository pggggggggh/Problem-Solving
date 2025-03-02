select distinct a.car_id, a.car_type, round(daily_fee * 30 *
(100 -
(select discount_rate from car_rental_company_discount_plan
    where car_type = a.car_type and duration_type = "30일 이상"
)) / 100) as fee
from car_rental_company_car as a join car_rental_company_rental_history as b on a.car_id = b.car_id
where a.car_id not in (
    select distinct car_id from car_rental_company_rental_history
    where
    (start_date <= "2022-11-01" and end_date >= "2022-11-01")
    or
    (start_date <= "2022-11-30" and end_date >= "2022-11-30")
)
having fee >= 500000 and fee <= 2000000
order by fee desc, car_type, car_id desc
