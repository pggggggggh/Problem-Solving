-- 코드를 입력하세요
SELECT warehouse_id, warehouse_name, address, case when freezer_yn = "Y" then "Y" else "N" end as freezer_yn from food_warehouse where address like "경기도%"