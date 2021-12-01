import java.util.ArrayList;

class Solution {
    public int findTheWinner(int n, int k) {
        ArrayList<Integer> arrayList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            arrayList.add(i + 1);
        }
        int curr = 0;
        for (int j = 0; j < n - 1; j++) {
            curr += k - 1;
            curr = curr % arrayList.size();
            arrayList.remove(curr);
        }
        return arrayList.get(0);
    }
}