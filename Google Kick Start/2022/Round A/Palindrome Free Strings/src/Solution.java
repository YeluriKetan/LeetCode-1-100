import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
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

    private String solve() {
        int len = fs.nextInt();
        char[] sArr = fs.next().toCharArray();
        return dfs(sArr, 0) ? "POSSIBLE" : "IMPOSSIBLE";
    }

    private boolean dfs(char[] sArr, int index) {
        if (index == sArr.length) {
            return !containsPalindrome(sArr);
        }
        if (sArr[index] != '?') {
            return dfs(sArr, index + 1);
        }
        sArr[index] = '0';
        if (dfs(sArr, index + 1)) {
            return true;
        }
        sArr[index] = '1';
        if (dfs(sArr, index + 1)) {
            return true;
        }
        sArr[index] = '?';
        return false;
    }

    private boolean containsPalindrome(char[] sArr) {
        int left, right;
        for (int i = 2; i < sArr.length - 3; i++) {
            left = i - 2;
            right = i + 2;
            while (left < right) {
                if (sArr[left] != sArr[right]) {
                    break;
                } else {
                    left++;
                    right--;
                }
            }
            if (left == right) {
                return true;
            }
            left = i - 2;
            right = i + 3;
            while (left < right) {
                if (sArr[left] != sArr[right]) {
                    break;
                } else {
                    left++;
                    right--;
                }
            }
            if (left > right) {
                return true;
            }
        }
        if (sArr.length - 5 > 0) {
            left = sArr.length - 5;
            right = sArr.length - 1;
            while (left < right) {
                if (sArr[left] != sArr[right]) {
                    break;
                } else {
                    left++;
                    right--;
                }
            }
            return left == right;
        }
        return false;
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
