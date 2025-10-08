

SELECT c1.name as Customers
FROM Customers AS c1
LEFT JOIN Orders AS c2
  ON c1.id = c2.customerId
WHERE c2.customerId IS NULL;
