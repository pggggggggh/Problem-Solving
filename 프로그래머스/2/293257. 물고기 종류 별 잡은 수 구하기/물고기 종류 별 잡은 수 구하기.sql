-- 코드를 작성해주세요
select count(*) as fish_count, (select fish_name from fish_name_info where fish_info.fish_type = fish_name_info.fish_type) as fish_name
from fish_info
group by fish_type
order by fish_count desc