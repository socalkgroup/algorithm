params = ((1,0), (0,1), (-1,0), (0,-1))
class Solution:
    def spiralOrder(self, matrix):
        self.output = []
        self.move(0,0, len(matrix[0]), len(matrix), params[0])
        return self.output

    def move(self, x, y, n, m,param):
        if not n or not m:
            return

        tx,ty = x+param[0]*(n-1), y+param[1]*(m-1)

        ret = []
        if not param[0]:
            for i in range(min(y,ty), max(y,ty)+1):
                ret.append(matrix[i][x])
        else:
            ret = matrix[y][min(x,tx):max(x,tx)+1]

        ret = ret if param[0]>=0 and param[1]>=0 else reversed(ret)

        self.output.extend(ret)
        param = params[(params.index(param)+1)%len(params)]
        if param[0]:
            self.move(tx+param[0], ty+param[1], n-1 , m , param)
        else:
            self.move(tx+param[0], ty+param[1], n , m-1 , param)
matrix = [
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
solution = Solution()
output = solution.spiralOrder(matrix)
print(str(output))