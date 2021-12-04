public class Test {
    public static void main(String[] args) {
        int curr = 1;
        System.out.print("{");
        for (int i = 0; i < 32; i++) {
            System.out.print(curr + ", ");
            curr *= 2;
        }
        System.out.print("}");
    }
}
