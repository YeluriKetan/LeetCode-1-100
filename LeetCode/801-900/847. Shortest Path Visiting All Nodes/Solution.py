class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        def dp(curr_node: int, curr_mask: int) -> int:
            curr_state = (curr_node, curr_mask)
            if curr_state in memo:
                return memo[curr_state]
            memo[curr_state] = 10000000
            for next_node in graph[curr_node]:
                if curr_mask & 1 << next_node:
                    memo[curr_state] = min(memo[curr_state], 1 + dp(next_node, curr_mask), 1 + dp(next_node, curr_mask ^ (1 << curr_node)))
            return memo[curr_state]

        n = len(graph)
        memo = {(i, 1 << i): 0 for i in range(n)}
        final_mask = (1 << n) - 1
        return min(dp(final_node, final_mask) for final_node in range(n))