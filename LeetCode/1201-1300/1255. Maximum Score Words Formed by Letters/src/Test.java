public class Test {
    public static void main(String[] args) {
        Solution sol = new Solution();
        String[] arr1 = {"dog","cat","dad","good"};
        char[] arr2 = {'a','a','c','d','d','d','g','o','o'};
        int[] arr3 = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
        System.out.println(sol.maxScoreWords(arr1, arr2, arr3));
        String[] arr4 = {"xxxz","ax","bx","cx"};
        char[] arr5 = {'z','a','b','c','x','x','x'};
        int[] arr6 = {4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10};
        System.out.println(sol.maxScoreWords(arr4, arr5, arr6));
    }
}
