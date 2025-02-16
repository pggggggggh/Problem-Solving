-- 코드를 작성해주세요
select id,email,first_name,last_name from developers
where
id in (
    select id from developers join skillcodes where category = "Front End" and code | skill_code = skill_code
)
order by id
