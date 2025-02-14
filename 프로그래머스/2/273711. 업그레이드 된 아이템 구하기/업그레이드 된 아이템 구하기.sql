-- 코드를 작성해주세요
select b.item_id, (select item_name from item_info as x where b.item_id=x.item_id) as item_name,
(select rarity from item_info as y where b.item_id=y.item_id) as rarity
from (select * from item_info where rarity="RARE") as a
join (select * from item_tree) as b on b.parent_item_id = a.item_id
order by item_id desc