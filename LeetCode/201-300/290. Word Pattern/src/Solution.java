import java.util.Hashtable;

class Solution {
    public boolean wordPattern(String pattern, String s) {
        Hashtable<Character, String> table = new Hashtable<>();
        int low = 0;
        int high = 0;
        int index = 0;
        while(index < pattern.length()) {
            //System.out.println(index);
            while (high < s.length()) {
                if (s.charAt(high) == ' ') {
                    break;
                } else {
                    high++;
                }
            }
            //System.out.println(low + "," + high);
            if (high == s.length() && index != pattern.length() - 1) {
                //System.out.println("A");
                return false;
            }
            String str = s.substring(low, high);
            //System.out.println(str);
            char curr = pattern.charAt(index);
            //System.out.println(curr);
            if (table.containsKey(curr)) {
                //System.out.println("B");
                if (table.get(curr).equals(str)) {
                    low = ++high;
                } else {
                    return false;
                }
            } else {
                //System.out.println("C");
                if (table.containsValue(str)) {
                    return false;
                } else {
                    table.put(curr, str);
                    low = ++high;
                }
            }
            index++;
        }
        //System.out.println(high == s.length() + 1);
        return high == s.length() + 1;
    }
}