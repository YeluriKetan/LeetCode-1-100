class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        def score(pointer: int):
            if s[pointer + 1] == ")":
                return (pointer + 2, 1)
            else:
                curr_score, pointer = 0, pointer + 1
                while s[pointer] != ")":
                    child = score(pointer)
                    curr_score, pointer = curr_score + child[1], child[0]
                return (pointer + 1, 2 * curr_score)
        curr_score, pointer = 0, 0
        while pointer < len(s):
            child = score(pointer)
            curr_score, pointer = curr_score + child[1], child[0]
        return curr_score