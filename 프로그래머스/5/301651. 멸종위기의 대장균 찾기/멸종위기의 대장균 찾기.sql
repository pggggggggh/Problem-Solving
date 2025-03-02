with recursive recur as (
    select id, 1 as generation
    from ecoli_data
    where parent_id is null
    
    union all
    
    select cur.id, past.generation+1 as generation
    from recur as past join ecoli_data as cur on past.id = cur.parent_id
)
select count(*) as count, generation
from recur
where id not in (select distinct a.id from recur as a join ecoli_data as b where a.id = b.parent_id)
group by generation
order by generation