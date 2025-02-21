with recursive r as (
    select 0 as hour
    
    union all
    
    select r.hour+1 as hour
    from r
    having hour < 24
)
select hour, count(animal_id) as count
from r left join animal_outs as a on hour(a.datetime) = r.hour
group by hour
order by hour