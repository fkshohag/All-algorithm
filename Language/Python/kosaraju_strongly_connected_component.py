from collections import defaultdict
from typing import List


class Kosaraju(object):
    def __init__(self, vertex: int) -> None:
        self.vertex = vertex
        self.graph = defaultdict(list)

    def add_edge(self, u: int, v: int) -> None:
        self.graph[u].append(v)

    def dfs(self, node: int, visited_vertex: List[int]) -> None:
        visited_vertex[node] = True
        print(node, end='')
        for connected_node in self.graph[node]:
            if not visited_vertex[connected_node]:
                visited_vertex[connected_node] = True
                self.dfs(connected_node, visited_vertex)

    def fill_order(self, node: int, visited_vertex: List[int], stack: List[int]) -> None:
        visited_vertex[node] = True
        for connected_node in self.graph[node]:
            if not visited_vertex[connected_node]:
                self.fill_order(connected_node, visited_vertex, stack)
        stack.append(node)

    def transpose(self) -> any:
        transpose_graph = Kosaraju(self.vertex)
        for u in self.graph:
            for v in self.graph[u]:
                transpose_graph.add_edge(v, u)
        return transpose_graph

    # Print strongly connected component
    def print_scc(self) -> None:
        stack = []
        visited_vertex = [False] * self.vertex

        for node in range(self.vertex):
            if not visited_vertex[node]:
                self.fill_order(node, visited_vertex, stack)

        gr = self.transpose()
        visited_vertex = [False] * self.vertex

        while stack:
            node = stack.pop()
            if not visited_vertex[node]:
                gr.dfs(node, visited_vertex)
                print('')


k = Kosaraju(8)
k.add_edge(0, 1)
k.add_edge(1, 2)
k.add_edge(2, 3)
k.add_edge(2, 4)
k.add_edge(3, 0)
k.add_edge(4, 5)
k.add_edge(5, 6)
k.add_edge(6, 4)
k.add_edge(6, 7)

print("Strongly Connected Components:")
k.print_scc()
