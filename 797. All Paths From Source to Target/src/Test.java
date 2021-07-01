public class Test {
    public static void main(String[] args) {
        int[][] graph = {{1,2},{3},{3},{}};
        Solution sol = new Solution();
        System.out.println(sol.allPathsSourceTarget(graph));
    }
}
