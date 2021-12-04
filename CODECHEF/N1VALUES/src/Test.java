public class Test {
    public static void main(String[] args) {
        long a = 1;
        System.out.print("{1, ");
        for (int i = 1; i < 61; i++) {
            a *= 2;
            System.out.print(a + ", ");
        }
        System.out.println("}");
    }
}
