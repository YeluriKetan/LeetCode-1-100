import java.util.ArrayList;
import java.util.List;

class Solution {

    public List<List<String>> partition(String s) {
        List<List<String>> ans = new ArrayList<>();
        ArrayList<String> currAns = new ArrayList<>();
        dfs(ans, currAns, s, 0);
        return ans;
    }

    private void dfs(List<List<String>> ans, List<String> currAns, String string, int index) {
        if (index == string.length()) {
            ans.add(new ArrayList<>(currAns));
            return;
        }
        for (int i = index; i < string.length(); i++) {
            if (isPalindrome(string, index, i)) {
                currAns.add(string.substring(index, i + 1));
                dfs(ans, currAns, string, i + 1);
                currAns.remove(currAns.size() - 1);
            }
        }
    }

    private boolean isPalindrome(String string, int begin, int end) {
        int low = begin;
        int high = end;
        while (low < high) {
            if (string.charAt(low) == string.charAt(high)) {
                low++;
                high--;
            } else {
                return false;
            }
        }
        return true;
    }
}
