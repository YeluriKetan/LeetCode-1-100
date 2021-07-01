public class Test {
    public static void main(String[] args) {
        String str = "https://leetcode.com/problems/design-tinyurl";
        Codec cod = new Codec();
        System.out.println(cod.encode(str));
        System.out.println(cod.encode(str));
        System.out.println(cod.decode("http://tinyurl.com/!"));
    }
}
