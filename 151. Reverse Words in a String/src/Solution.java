import java.util.Arrays;

class Solution {
    public String reverseWords(String s) {
        String[] arr = s.trim().split("\\s+");
        System.out.println(Arrays.toString(arr));
        StringBuilder sb = new StringBuilder();
        for (int i = arr.length - 1; i > -1; i--) {
            sb.append(arr[i] + " ");
        }
        if (sb.charAt(sb.length() - 1) == ' ') {
            sb.deleteCharAt(sb.length() - 1);
        }
        return sb.toString();
    }
}
