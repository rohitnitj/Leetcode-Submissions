# Write your MySQL query statement below
SELECT e1.name
FROM Employee e1
JOIN (SELECT managerId
     FROM Employee
     WHERE managerId IS NOT NULL
     GROUP BY managerId
     HAVING COUNT(*) >= 5) AS mgr
ON e1.id = mgr.managerId;
