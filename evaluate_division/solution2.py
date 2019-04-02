#equations = [ ["a", "b"], ["b", "c"] ],
#values = [2.0, 3.0],
#queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].
from collections import defaultdict

class Node:
    def __init__(self, n, c):
        self.next = n
        self.cost = c

class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        graph = defaultdict(lambda:{})

        for v, cost in zip(equations, values):
            graph[v[0]][v[0]], graph[v[1]][v[1]]=1,1
            graph[v[0]][v[1]], graph[v[1]][v[0]]=cost,1/cost

        for s in graph:
            for v1 in graph[s]:
                for v2 in graph[s]:
                     graph[v1][v2] = graph[v1][s] * graph[s][v2]

        return [graph[vex[0]].get(vex[1], -1.0) for vex in queries]

equations = [["x1","x2"],["x2","x3"],["x3","x4"],["x4","x5"]]
values = [3.0,4.0,5.0,6.0]
queries = [["x1","x5"],["x5","x2"],["x2","x4"],["x2","x2"],["x2","x9"],["x9","x9"]]

solution = Solution()
print(str(solution.calcEquation(equations, values, queries)))










