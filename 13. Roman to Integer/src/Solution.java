import java.util.HashMap;

class Solution {

    private static HashMap<Character, Integer> map;

    public Solution() {
        map = new HashMap<>();
        map.put('I', 1);
        map.put('V', 5);
        map.put('X', 10);
        map.put('L', 50);
        map.put('C', 100);
        map.put('D', 500);
        map.put('M', 1000);
    }

    public int romanToInt(String s) {
        int ans = 0;
        char prev;
        char curr;
        prev = s.charAt(s.length() - 1);
        ans += map.get(prev);
        for (int i = s.length() - 2; i > -1; i--) {
            curr = s.charAt(i);
            ans += map.get(curr);
            if (curr == 'I' && (prev == 'V' || prev == 'X')) {
                ans -= 2;
            } else if (curr == 'X' && (prev == 'L' || prev == 'C')) {
                ans -= 20;
            } else if (curr == 'C' && (prev == 'D' || prev == 'M')) {
                ans -= 200;
            }
            prev = curr;
        }
        return ans;
    }
}
