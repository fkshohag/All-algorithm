def solution(A):
    m = max(A)
    if m < 0:
        return 1
    A = set(A)
    B = set(range(1, m+1))
    D = B - A
    if len(D) == 0:
        return m+1
    else:
        return min(D)


print(solution([1, 2, 3]))
