import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution {

    private static FastScan fs;

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        Solution sol = new Solution();
        fs = new FastScan();

        int total = fs.nextInt();
        for (int i = 1; i <= total; i++) {
            bw.write("Case #" + i + ": " + sol.solve() + "\n");
        }
        bw.flush();
        fs.close();
    }

    private int solve() {
        int n = fs.nextInt();
        ArrayList<int[]> list = new ArrayList<>();
        int[] currArr = new int[2];
        int prevInt = fs.nextInt();
        int currInt = fs.nextInt();
        currArr[0] = currInt - prevInt;
        prevInt = currInt;
        currArr[1] = 2;
        for (int i = 2; i < n; i++) {
            currInt = fs.nextInt();
            if (currInt - prevInt == currArr[0]) {
                currArr[1]++;
            } else {
                list.add(currArr);
                currArr = new int[2];
                currArr[0] = currInt - prevInt;
                currArr[1] = 2;
            }
            prevInt = currInt;
        }
        list.add(currArr);
        int max = helper(list);
        ArrayList<int[]> revList = new ArrayList<>();
        for (int i = list.size() - 1; i > -1; i--) {
            revList.add(list.get(i));
        }
        max = Math.max(max, helper(revList));
        return max;
    }

    private int helper(ArrayList<int[]> list) {
        int max = 2;
        for (int i = 0; i < list.size(); i++) {
            int[] currArr = list.get(i);
            if (i + 1 < list.size()) {
                if (list.get(i + 1)[1] > 2) {
                    max = Math.max(max, currArr[1] + 1);
                    continue;
                }
            } else {
                max = Math.max(max, currArr[1]);
                continue;
            }
            if (i + 2 < list.size()) {
                if (list.get(i + 2)[0] + list.get(i + 1)[0] != 2 * currArr[0]) {
                    max = Math.max(max, currArr[1] + 1);
                    continue;
                }
                if (list.get(i + 2)[1] > 2) {
                    max = Math.max(max, currArr[1] + 2);
                    continue;
                }
            } else {
                max = Math.max(max, currArr[1] + 1);
                continue;
            }
            if (i + 3 < list.size()) {
                if (list.get(i + 3)[0] == currArr[0]) {
                    max = Math.max(max, currArr[1] + 1 + list.get(i + 3)[1]);
                } else {
                    max = Math.max(max, currArr[1] + 2);
                }
            } else {
                max = Math.max(max, currArr[1] + 2);
            }
        }
        return max;
    }

    private static class FastScan {
        private BufferedReader br;
        private StringTokenizer st;

        private FastScan() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        private String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException ex) {
                    ex.printStackTrace();
                }
            }
            return st.nextToken();
        }

        private int nextInt() {
            return Integer.parseInt(next());
        }

        private void close() {
            try {
                br.close();
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
    }
}
