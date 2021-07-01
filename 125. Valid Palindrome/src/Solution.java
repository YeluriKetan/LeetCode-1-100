class Solution {
    public boolean isPalindrome(String s) {
        int low = 0;
        int high = s.length() - 1;
        char[] arr = s.toCharArray();
        while (low <= high) {
            if (!valid(arr[low])) {
                low++;
            } else if (!valid(arr[high])) {
                high--;
            } else {
                if (equal(arr[low], arr[high])) {
                    low++;
                    high--;
                } else {
                    return false;
                }
            }
        }
        return true;
    }

    private boolean valid(char curr) {
        return (curr > 47 && curr < 58) || (curr > 64 && curr < 91) || (curr > 96 && curr < 123);
    }

    private boolean equal(char curr1, char curr2) {
        if (curr1 < 58 || curr2 < 58) {
            return curr1 == curr2;
        } else {
            return curr1 == curr2 || curr1 == curr2 - 32 || curr1 - 32 == curr2;
        }
    }
}