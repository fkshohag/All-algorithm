from ast import List
import math
from collections import defaultdict

class Solution:
    def dfs(self, node: int, parent: int) -> int:
        representative: int = 1
        for childNode in self.citys[node]:
            if childNode != parent:
                representative += self.dfs(childNode, node)
        if node != 0:
            self.fuel += math.ceil(representative / self.seats)
        return representative

    def minimumFuelCost(self, roads: List[List[int]], seats: int) -> int:
        self.seats = seats
        self.citys = defaultdict(list)
        self.fuel = 0

        for road in roads:
            self.citys[road[0]].append(road[1])
            self.citys[road[1]].append(road[0])
        self.dfs(0, -1)
        return self.fuel
