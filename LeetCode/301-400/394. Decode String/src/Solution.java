class Solution {

    private int index;

    public String decodeString(String s) {
        index = 0;
        return recurse(s).toString();
    }

    private StringBuilder recurse(String s) {
        StringBuilder sb = new StringBuilder();
        while (index < s.length()) {
            char currChar = s.charAt(index);
            if (currChar == ']') {
                break;
            }
            if (currChar > 96) {
                sb.append(currChar);
            } else {
                int curr = currChar - '0';
                while ((currChar = s.charAt(++index)) < 58) {
                    curr *= 10;
                    curr += currChar - '0';
                }
                index++;
                StringBuilder nestedSb = recurse(s);
                for (int i = 0; i < curr; i++) {
                    sb.append(nestedSb);
                }
            }
            index++;
        }
        return sb;
    }
}
