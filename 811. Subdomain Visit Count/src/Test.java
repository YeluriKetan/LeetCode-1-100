import java.util.Arrays;

public class Test {
    public static void main(String[] args) {
        Solution sol = new Solution();
        String[] arr = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
        System.out.println(Arrays.toString(arr));
        System.out.println(sol.subdomainVisits(arr));
    }
}
