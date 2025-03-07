-- 코드를 입력하세요
select apnt_no, p.pt_name, p.pt_no, d.mcdp_cd, d.dr_name, apnt_ymd
from appointment as a
    join doctor as d on a.mddr_id = d.dr_id
    join patient as p on p.pt_no = a.pt_no
where apnt_cncl_yn != "Y" and d.mcdp_cd = "CS"and apnt_ymd like "2022-04-13%" 
order by apnt_ymd