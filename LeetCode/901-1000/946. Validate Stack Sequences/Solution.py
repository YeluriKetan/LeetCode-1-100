class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stack, pushed_pointer, popped_pointer, n = [], 0, 0, len(pushed)
        while popped_pointer < n:
            if stack and stack[-1] == popped[popped_pointer]:
                stack.pop()
                popped_pointer += 1
            else:
                if pushed_pointer >= n: return False
                stack.append(pushed[pushed_pointer])
                pushed_pointer += 1
        return not stack