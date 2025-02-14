-- 코드를 입력하세요
SELECT mcdp_cd as 진료과코드, count(*) as 5월예약건수
from appointment
where month(apnt_ymd) = 5
group by 진료과코드
order by 5월예약건수, 진료과코드