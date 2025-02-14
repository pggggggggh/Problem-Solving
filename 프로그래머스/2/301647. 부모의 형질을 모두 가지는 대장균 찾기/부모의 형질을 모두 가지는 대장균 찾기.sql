-- 코드를 작성해주세요
select e1.id,e1.genotype,e2.genotype as parent_genotype
from ecoli_data as e1 join ecoli_data as e2 on e1.parent_id = e2.id
where e1.genotype | e2.genotype = e1.genotype
order by id