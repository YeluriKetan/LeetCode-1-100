class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        n = len(costs)//2 + 2
        matrix = [[200001 for i in range(n)] for j in range(n)]
        matrix[0][0] = 0
        for index, person in enumerate(costs):
            up = min(index, n - 2)
            for b in range(up, index - up - 1, -1):
                matrix[b][index - b + 1] = min(matrix[b][index - b + 1], matrix[b][index - b] + person[0])
                matrix[b + 1][index - b] = min(matrix[b + 1][index - b], matrix[b][index - b] + person[1])
        return matrix[n - 2][n - 2]