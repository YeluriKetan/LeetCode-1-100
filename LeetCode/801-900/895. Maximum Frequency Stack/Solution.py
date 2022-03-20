from collections import Counter


class FreqStack:
    def __init__(self):
        self.count_map = Counter()
        self.count_stack = [[]]
        self.max_count = 0

    def push(self, val: int) -> None:
        new_count = self.count_map[val] + 1
        self.count_map[val] += 1
        if self.max_count < new_count:
            self.count_stack.append([])
            self.max_count += 1
        self.count_stack[new_count].append(val)

    def pop(self) -> int:
        ans = self.count_stack[self.max_count].pop()
        self.count_map[ans] -= 1
        if not self.count_stack[self.max_count]:
            self.max_count -= 1
        return ans

# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()