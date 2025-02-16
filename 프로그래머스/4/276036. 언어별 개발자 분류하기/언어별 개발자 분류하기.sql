WITH python AS (
    select id from developers where skill_code | (select code from skillcodes where name="Python") = skill_code
),
csharp as (
    select id from developers where skill_code | (select code from skillcodes where name="C#") = skill_code
),
frontend as (
    select id from developers join skillcodes on category="front end" and skill_code | code = skill_code
)
select
case
when id in (select id from python) and id in (select id from frontend) then "A"
when id in (select id from csharp) then "B"
when id in (select id from frontend) then "C"
else null
end as grade,
id,
email
from developers
having grade is not null
order by grade,id