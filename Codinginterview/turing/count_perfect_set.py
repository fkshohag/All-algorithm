def count_perfect_sets(balls, x, y, z):
    n = len(balls)
    count = 0
    
    for i in range(n):
        for j in range(i+1, n):
            for k in range(j+1, n):
                if abs(balls[i] - balls[j]) <= x \
                and abs(balls[j] - balls[k]) <= y \
                and abs(balls[i] - balls[k]) <= z:
                    count += 1
    return count
print(count_perfect_sets([3, 0, 1, 1, 9, 7], 7, 2, 3))