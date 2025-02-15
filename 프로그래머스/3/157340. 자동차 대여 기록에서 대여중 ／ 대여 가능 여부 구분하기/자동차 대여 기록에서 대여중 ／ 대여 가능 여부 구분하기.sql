-- 코드를 입력하세요
SELECT distinct(car_id),
case
when exists (select * from car_rental_company_rental_history as b where
            b.car_id = a.car_id and b.start_date <= '2022-10-16' and b.end_date >= '2022-10-16') then "대여중"
else "대여 가능"
end as availability
from car_rental_company_rental_history as a
order by car_id desc