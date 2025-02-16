-- 코드를 작성해주세요
with recursive recur as (
    select a.id,a.parent_id,1 as gen from ecoli_data as a
    where a.parent_id is null
    union all
    select b.id,b.parent_id,recur.gen+1 from recur join ecoli_data as b on recur.id = b.parent_id
)
select count(*) as count,gen as generation from ecoli_data as a join recur as b on a.id=b.id
where a.id not in (select coalesce(parent_id,"") from ecoli_data)
group by gen