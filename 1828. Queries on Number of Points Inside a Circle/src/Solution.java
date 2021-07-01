class Solution {
    public int[] countPoints(int[][] points, int[][] queries) {
        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            for (int j = 0; j < points.length; j++) {
                if (check(points[j], queries[i])) {
                    result[i]++;
                }
            }
        }
        return result;
    }

    private boolean check(int[] point1, int[] point2) {
        int dist = (point1[0] - point2[0]) * (point1[0] - point2[0])
                + (point1[1] - point2[1]) * (point1[1] - point2[1]);
        return dist <= point2[2] * point2[2];
    }
}