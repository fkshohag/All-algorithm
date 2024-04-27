from collections import deque
from typing import List


def countnumberofships(b : List[List[int]]) -> List[int]:
    num_rows = len(b)
    num_cols = len(b[0])
    res = []
    def get_neighbour(coord):
        row, col= coord
        delta_row = [-1,0,1,0]
        delta_col = [0,1,0,-1]
        res= []
        for i in range(len(delta_row)):
            row_neighbour = row + delta_row[i]
            col_neighbour = col + delta_col[i]
            if 0 <= row_neighbour < num_rows and 0<= col_neighbour < num_cols:
                res.append((row_neighbour, col_neighbour))
        return res
    def getsize(start):
        queue = deque([start])
        r, c  = start
        b[r][c] = 0
        size = 0
        while len(queue) > 0:
            node = queue.popleft() #when_we are poping we can increase the size to get the size of an island
            size += 1
            for neighbour in get_neighbour(node):
                r, c = neighbour
                if b[r][c] == 0:
                    continue
                queue.append(neighbour)
                b[r][c] = 0
        return size
    res = [0] * 3
    for i in range(num_rows):
        for j in range(num_cols):
            if b[i][j] == 0:
                continue
            size =getsize((i, j))
            if size <= 3:
                res[size -1] += 1
    return res
#replacing_the '.' with '0' and '#' with '1'
#now_it becomes a number of islands problem (but to get the size of island)
b = ['.##.#','#.#..','#...#','#.##.']
for i in range(len(b)):
    b[i] = b[i].replace('.','0').replace('#','1')
    b[i] = [int(x) for x in str(b[i])]
print(countnumberofships(b))