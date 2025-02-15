-- 코드를 입력하세요
SELECT concat("/home/grep/src/",a.board_id,"/",file_id,file_name,file_ext) as file_path
from used_goods_board as a join used_goods_file as b on a.board_id = b.board_id
where views = (select max(views) from used_goods_board)
order by file_id desc