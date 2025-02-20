-- 코드를 입력하세요
select car_id, car_type,
round(
    30 * daily_fee * (100 - (select discount_rate from CAR_RENTAL_COMPANY_DISCOUNT_PLAN as c where a.car_type = c.car_type and duration_type = "30일 이상")) / 100
) as fee
from car_rental_company_car as a
where
    car_type in ("세단","SUV")
and
    not exists
    (
        select * from CAR_RENTAL_COMPANY_RENTAL_HISTORY 
        where car_id = a.car_id and start_date <= "2022-11-30" and end_date >= "2022-11-01"
    )
having 500000 <= fee and fee <= 2000000
order by fee desc, car_type, car_id desc;