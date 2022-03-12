class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        row, carry = [poured], 0
        while query_row > 0:
            carry, query_row = 0, query_row - 1
            for i in range(len(row)):
                row[i] = ((row[i] - 1) / 2 if row[i] >= 1 else 0) + carry
                carry = row[i] - carry
            row.append(carry)
        return 1 if row[query_glass] >= 1 else row[query_glass]