import java.util.ArrayList;

class Solution {
    public int[][] intervalIntersection(int[][] firstList, int[][] secondList) {
        int firstP = 0;
        ArrayList<int[]> list = new ArrayList<>();
        for (int i = 0; i < secondList.length && firstP < firstList.length; i++) {
            if (firstList[firstP][0] > secondList[i][1]) {
                continue;
            }
            if (firstList[firstP][1] < secondList[i][0]) {
                firstP++;
                i--;
                continue;
            }
            int[] newInterval = new int[2];
            newInterval[0] = Math.max(firstList[firstP][0], secondList[i][0]);
            newInterval[1] = Math.min(firstList[firstP][1], secondList[i][1]);
            if (firstList[firstP][1] > secondList[i][1]) {
                firstList[firstP][0] = secondList[i][1];
            } else {
                if (firstList[firstP][1] != secondList[i][1]) {
                    secondList[i][0] = firstList[firstP][1];
                    i--;
                }
                firstP++;
            }
            list.add(newInterval);
        }
        return list.toArray(new int[list.size()][]);
    }
}
