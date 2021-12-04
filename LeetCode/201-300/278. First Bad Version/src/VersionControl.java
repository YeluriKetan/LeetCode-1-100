import java.util.Random;

public class VersionControl {

    private static Random rand = new Random();
    private static int check;

    public VersionControl() {}

    public VersionControl(int num) {
        VersionControl.check = rand.nextInt(num);
        System.out.println(check);
    }

    public boolean isBadVersion(int num) {
        return num >= check;
    }

}
