public class Test {
    private static final long mod = Long.parseLong("1164778184719273153");

    public static void main(String[] args) {
        long num = Long.parseLong("57404694283573197");
        System.out.println(num);
        long mod1 = mod % num;
        System.out.println(mod1);
        long mod2 = (mod - mod1 - 1) % num;
        System.out.println(mod2);
        System.out.println(mod2 + 1);
    }
}
