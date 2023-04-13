def get_largest_number(n):
    result = [0] * (n + 1)
    result[0] = 0
    result[1] = 1
    
    for i in range(1, (n // 2) + 1):
        result[2 * i] = result[i]
        if (2 * i + 1) <= n:
            result[2 * i + 1] = result[i] + result[i + 1]
    return max(result)

r = get_largest_number(7)
print(r)