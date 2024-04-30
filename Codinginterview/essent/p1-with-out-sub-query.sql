SELECT p1.day
FROM prices p1
JOIN prices p2 ON p1.day = p2.day - 1
JOIN prices p3 ON p1.day = p3.day + 1
WHERE p1.price > p2.price
  AND p1.price > p3.price
  AND p1.day != 1
  AND p1.day != (SELECT MAX(day) FROM prices);