class Solution:
    def frequencySort(self, s: str) -> str:
        return "".join([letter*count for letter, count in Counter(s).most_common()])