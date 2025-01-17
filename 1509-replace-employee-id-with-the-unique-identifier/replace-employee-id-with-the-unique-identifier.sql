# Write your MySQL query statement below

SELECT 
    eu.unique_id AS unique_id,  -- Selecting the unique ID from EmployeeUNI table
    e.name AS name              -- Selecting the employee's name
FROM 
    Employees e                 -- Main table
LEFT JOIN 
    EmployeeUNI eu              -- Joining with EmployeeUNI table
ON 
    e.id = eu.id;               -- Matching based on the employee's ID
