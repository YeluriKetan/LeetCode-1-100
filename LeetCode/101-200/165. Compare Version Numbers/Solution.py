class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        pointer1, pointer2, val1, val2 = 0, 0, 0, 0
        while pointer1 < len(version1) or pointer2 < len(version2):
            val1, val2 = 0, 0
            while pointer1 < len(version1) and version1[pointer1] != '.':
                val1 *= 10;
                val1 += ord(version1[pointer1]) - ord('0')
                pointer1 += 1
            while pointer2 < len(version2) and version2[pointer2] != '.':
                val2 *= 10;
                val2 += ord(version2[pointer2]) - ord('0')
                pointer2 += 1
            if val1 < val2:
                return -1
            elif val1 > val2:
                return 1
            else:
                pointer1 += 1
                pointer2 += 1
        return 0