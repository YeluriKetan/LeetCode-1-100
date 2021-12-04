public class Test {

    public static void main(String[] args) {
        int[][] graph = {{4,3,1,8,6},{2,4,7},{8,4,6,5,3},{8,6,5,4},{7,6,5,8},{6,7},{7},{8},{}};
        long numOfTests = 10000;

        Solution sol = new Solution();
        sol.allPathsSourceTarget(graph);
        long totalTime = 0;
        long start, end;
        for (int i = 0; i < numOfTests; i++) {
            start = System.nanoTime();
            sol.allPathsSourceTarget(graph);
            end = System.nanoTime();

            totalTime += (end - start);
        }

        totalTime /= numOfTests;

        System.out.println("Average time taken for " + numOfTests + " tests is " + totalTime + " ns");
    }
}
