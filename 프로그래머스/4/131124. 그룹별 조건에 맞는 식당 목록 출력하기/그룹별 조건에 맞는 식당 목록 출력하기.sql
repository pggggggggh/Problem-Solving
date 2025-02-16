-- 코드를 입력하세요
SELECT member_name, review_text, date_format(review_date,"%Y-%m-%d")
from member_profile as a join rest_review as b on a.member_id = b.member_id
where a.member_id = (select member_id from rest_review group by member_id order by count(*) desc limit 1)
order by review_date, review_text