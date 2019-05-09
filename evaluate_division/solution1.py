#equations = [ ["a", "b"], ["b", "c"] ],
#values = [2.0, 3.0],
#queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].
from collections import defaultdict

class Node:
    def __init__(self, n, c):
        self.next = n
        self.cost = c

CAN_NOT_FIND_PATH = -1.0

class Solution:
    def calcEquation(self, equations, values, queries):
        self.graph = defaultdict(lambda: {})
        self.visited = defaultdict(lambda: 0)

        for vex, cost in zip(equations, values):
            self.graph[vex[0]][vex[1]], self.graph[vex[1]][vex[0]] = cost, 1/cost
            self.graph[vex[0]][vex[0]], self.graph[vex[1]][vex[1]] = 1.0,1.0

        def calcPaths(s, e, current):
            # calcPaths
            # s -> neighbors -> neighbors of neighbors
            print("s:{}, e:{}, current:{}".format(s,e,current))
            if s in self.graph and e in self.graph[s]:
                return current*self.graph[s][e]

            if self.visited[s] != 0:
                return CAN_NOT_FIND_PATH

            neighbors = self.graph[s]
            for k, v in neighbors.items():
                if k == e:
                    return current*v
                self.visited[s]=1
                val = calcPaths(k, e, current*v)
                self.visited[s]=0
                if val != -1:
                    return val

            return CAN_NOT_FIND_PATH # not found

        return [calcPaths(pt[0], pt[1], 1) for pt in queries]

#equations = [ ["a", "b"], ["b", "c"] ]
#values = [2.0, 3.0]
#queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]
equations = [["x1","x2"],["x2","x3"],["x3","x4"],["x4","x5"]]
values = [3.0,4.0,5.0,6.0]
queries = [["x1","x5"],["x5","x2"],["x2","x4"],["x2","x2"],["x2","x9"],["x9","x9"]]

solution = Solution()
print(str(solution.calcEquation(equations, values, queries)))










