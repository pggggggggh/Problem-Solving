-- 코드를 작성해주세요
select id,
case
when per <= 0.25 then "CRITICAL"
when per <= 0.5 then "HIGH"
when per <= 0.75 then "MEDIUM"
else "LOW" end as colony_name
from (
    select
    *,
    percent_rank() over (order by size_of_colony desc) as per
    from ecoli_data
) as a
order by id