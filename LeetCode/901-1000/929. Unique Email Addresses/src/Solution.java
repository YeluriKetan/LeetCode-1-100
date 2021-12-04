import java.util.HashSet;

class Solution {
    public int numUniqueEmails(String[] emails) {
        HashSet<String> set = new HashSet<>();
        for (int i = 0; i < emails.length; i++) {
            String[] arr = emails[i].split("@");
            arr[0] = arr[0].split("\\+", 2)[0];
            arr[0] = arr[0].replace(".", "");
            set.add(arr[0] + "@" + arr[1]);
        }
        return set.size();
    }
}