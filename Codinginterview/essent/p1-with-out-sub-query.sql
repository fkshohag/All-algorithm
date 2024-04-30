`
In this query:

p1 represents the current day's data.
p2 represents the previous day's data.
p3 represents the next day's data.
We join the prices table three times: once to represent the current day, once to represent the previous day (p2), and once to represent the next day (p3). Then, we compare the prices of the current day with the prices of the previous and next days using the join conditions. Finally, we add additional conditions to exclude the first day and the last day from the result set.

This approach eliminates the need for subqueries and may improve the query's performance, especially on large datasets.
`


SELECT p1.day
FROM prices p1
JOIN prices p2 ON p1.day = p2.day - 1
JOIN prices p3 ON p1.day = p3.day + 1
WHERE p1.price > p2.price
  AND p1.price > p3.price
  AND p1.day != 1
  AND p1.day != (SELECT MAX(day) FROM prices);