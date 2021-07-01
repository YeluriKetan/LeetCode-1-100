class Solution {
    public int lengthOfLastWord(String s) {
        char[] arr = s.toCharArray();
        int letter = -1;
        for (int i = arr.length - 1; i >= 0 ; i--) {
            if (arr[i] == ' ') {
                if (letter != -1) {
                    return letter - i;
                } else {
                    //
                }
            } else if(letter == -1) {
                letter = i;
            }
        }
        if (letter == -1) {
            return 0;
        } else {
            return letter + 1;
        }
    }
}