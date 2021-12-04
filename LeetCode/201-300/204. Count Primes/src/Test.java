import java.time.Duration;
import java.time.Instant;

public class Test {
    public static void main(String[] args) {
        Solution sol = new Solution();

        long start = System.currentTimeMillis();
        Instant startI = Instant.now();

        int ans = sol.countPrimes(9);

        long finish = System.currentTimeMillis();
        Instant finishI = Instant.now();

        double duration = (double) (finish - start) / 1000;
        long timeElapsed = Duration.between(startI, finishI).toMillis();
        double durationI = (double) timeElapsed / 1000;

        System.out.println(ans);
        System.out.println(duration);
        System.out.println(durationI);
    }
}
