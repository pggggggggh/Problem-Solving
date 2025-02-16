-- 코드를 입력하세요
SELECT apnt_no, pt_name, c.pt_no, c.mcdp_cd, dr_name, apnt_ymd
from appointment as c join patient as a on a.pt_no = c.pt_no
                    join doctor as b on b.dr_id = c.mddr_id
where apnt_cncl_yn = "N" and apnt_ymd like "2022-04-13%"
order by apnt_ymd