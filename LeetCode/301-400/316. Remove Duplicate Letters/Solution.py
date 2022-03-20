class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        final_map, stack, done = {char:index for index, char in enumerate(s)}, [], set()
        for index, char in enumerate(s):
            if char in done: continue
            while stack and stack[-1] > char and final_map[stack[-1]] > index:
                done.remove(stack.pop())
            stack.append(char)
            done.add(char)
        return "".join(stack)