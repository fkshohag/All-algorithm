Select seller_id
FROM Sales
GROUP BY seller_id
HAVING sum(price) =
(
    SELECT sum(price)
    FROM Sales
    group by seller_id
    order by sum(price) desc
    limit 1
)