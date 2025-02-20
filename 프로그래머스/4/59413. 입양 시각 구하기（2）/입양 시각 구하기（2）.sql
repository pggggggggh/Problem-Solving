with recursive r as (
    select 0 as hour
    
    union all
    
    select r.hour+1 as hour
    from r
    having hour < 24
)
select hour,
(
    select count(*) from animal_outs where hour(datetime) = r.hour
) as count
from r
group by hour
order by hour