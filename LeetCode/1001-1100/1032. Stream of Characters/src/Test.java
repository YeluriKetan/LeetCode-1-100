public class Test {
    public static void main(String[] args) {
        String[] arr = {"cd", "f", "kl"};
        StreamChecker streamChecker = new StreamChecker(arr);
        System.out.println("Expected: false" + ", Actual: " + streamChecker.query('a'));
        System.out.println("Expected: false" + ", Actual: " + streamChecker.query('b'));
        System.out.println("Expected: false" + ", Actual: " + streamChecker.query('c'));
        System.out.println("Expected: true" + ", Actual: " + streamChecker.query('d'));
        System.out.println("Expected: false" + ", Actual: " + streamChecker.query('e'));
        System.out.println("Expected: true" + ", Actual: " + streamChecker.query('f'));
        System.out.println("Expected: false" + ", Actual: " + streamChecker.query('g'));
        System.out.println("Expected: false" + ", Actual: " + streamChecker.query('h'));
        System.out.println("Expected: false" + ", Actual: " + streamChecker.query('i'));
        System.out.println("Expected: false" + ", Actual: " + streamChecker.query('j'));
        System.out.println("Expected: false" + ", Actual: " + streamChecker.query('k'));
        System.out.println("Expected: true" + ", Actual: " + streamChecker.query('l'));
    }
}
