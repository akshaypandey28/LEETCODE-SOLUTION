# Write your MySQL query statement below

select today.id from Weather today
CROSS JOIN Weather yesterday

where DATEDIFF(today.recordDate , yesterday.recordDate)=1
and 
today.temperature > yesterday.temperature;
