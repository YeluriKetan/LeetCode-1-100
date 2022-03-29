class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        for index, row in enumerate(mat): mat[index] = (sum(row), index)
        mat.sort()
        return [row[1] for row in mat[:k]]