# Write your MySQL query statement below
select e.name, b.bonus
from Employee e
left join Bonus b ON b.empId=e.empId
where b.bonus<1000 OR b.bonus is NULL;