class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        r, c = len(matrix), len(matrix[0])
        low, high = 0, r * c - 1
        while low <= high:
            mid = (low + high) // 2
            element = matrix[mid // c][mid % c]
            if element < target: low = mid + 1
            elif element == target: return True
            else: high = mid - 1
        return False