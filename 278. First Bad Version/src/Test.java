import java.util.Random;

public class Test {

    private static Random rand = new Random();

    public static void main(String[] args) {
        int max = Math.abs(rand.nextInt());
        VersionControl vc = new VersionControl(max);
        Solution sol = new Solution();
        System.out.println(sol.firstBadVersion(max));
    }
}
