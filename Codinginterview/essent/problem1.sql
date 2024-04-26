SELECT p1.day
FROM prices p1
WHERE p1.price > (SELECT price FROM prices WHERE day = p1.day - 1)
  AND p1.price > (SELECT price FROM prices WHERE day = p1.day + 1)
  AND p1.day != 1
  AND p1.day != (SELECT MAX(day) FROM prices);