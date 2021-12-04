public class Test {
    public static void main(String[] args) {
        String str1 = "110";
        String str2 = "100000";
        StringBuilder stringBuilder = new StringBuilder("0123456");
        System.out.println(stringBuilder.replace(0, 100, "999").length());
//        System.out.println(str1.compareTo(str2));
    }
}
