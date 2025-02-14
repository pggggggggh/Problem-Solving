-- 코드를 작성해주세요
select count(*) as fish_count from fish_info as a join fish_name_info as b on a.fish_type=b.fish_type
where fish_name = "BASS" or fish_name="SNAPPER"