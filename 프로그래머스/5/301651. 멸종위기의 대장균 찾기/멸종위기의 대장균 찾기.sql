-- 코드를 작성해주세요
with recursive gen as (
    select id, 1 as g
    from ecoli_data
    where parent_id is null
    
    union all
    
    select b.id, gen.g+1 as g
    from ecoli_data as b join gen on gen.id = b.parent_id
)
select count(*) as count, g as generation
from gen
where id not in (select parent_id from ecoli_data where parent_id is not null)
group by g
order by g