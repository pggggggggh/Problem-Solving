-- 코드를 입력하세요
select month(start_date) as month,car_id,count(*) as records
from car_rental_company_rental_history
where car_id in (
    SELECT car_id from car_rental_company_rental_history
    where year(start_date) = 2022 and month(start_date) in (8,9,10)
    group by car_id
    having count(*) >= 5)
and year(start_date) = 2022 and month(start_date) in (8,9,10)
group by month,car_id
order by month, car_id desc