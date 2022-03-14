class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = deque()
        for curr in path.split("/"):
            if len(curr) == 0 or curr == ".": continue
            if curr == "..":
                if len(stack) > 0: stack.pop() 
            else:
                stack.append(curr)
        return "".join([("/" + a) for a in stack]) if len(stack) > 0 else "/"