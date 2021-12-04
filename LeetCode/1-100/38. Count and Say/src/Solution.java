import java.util.ArrayList;

class Solution {

    private static ArrayList<char[]> list;

    public Solution() {
        list = new ArrayList<>();
        list.add(new char[]{49});
    }

    public String countAndSay(int n) {
        if (list.size() >= n) {
            return String.valueOf(list.get(n - 1));
        }
        StringBuilder stringBuilder;
        char[] prev;
        char curr;
        int count;
        for (int i = list.size(); i < n; i++) {
            stringBuilder = new StringBuilder();
            prev = list.get(i - 1);
            curr = prev[0];
            count = 1;
            for (int j = 1; j < prev.length; j++) {
                if (prev[j] == curr) {
                    count++;
                } else {
                    stringBuilder.append(count + "" + (curr - 48));
                    count = 1;
                    curr = prev[j];
                }
            }
            stringBuilder.append(count + "" + (curr - 48));
            list.add(stringBuilder.toString().toCharArray());
        }
        return String.valueOf(list.get(n - 1));
    }
}
