import java.util.Arrays;

class Solution {
    public int[][] diagonalSort(int[][] mat) {
        int[] initArr = new int[mat.length];
        for (int i = 0; i < initArr.length; i++) {
            initArr[i] = 101;
        }
        int pointer;
        int x;
        int y;
        int[] tempArr = new int[mat.length];
        for (int i = 0; i < mat.length; i++) {
            System.arraycopy(initArr,0, tempArr,0, initArr.length);
            pointer = y = 0;
            x = i;
            while (x < mat.length && y < mat[0].length) {
                tempArr[pointer] = mat[x][y];
                x++;
                y++;
                pointer++;
            }
            Arrays.sort(tempArr);
            while (pointer > 0) {
                x--;
                y--;
                pointer--;
                mat[x][y] = tempArr[pointer];
            }
        }
        for (int j = 1; j < mat[0].length; j++) {
            System.arraycopy(initArr,0, tempArr,0, initArr.length);
            pointer = x = 0;
            y = j;
            while (x < mat.length && y < mat[0].length) {
                tempArr[pointer] = mat[x][y];
                x++;
                y++;
                pointer++;
            }
            Arrays.sort(tempArr);
            while (pointer > 0) {
                x--;
                y--;
                pointer--;
                mat[x][y] = tempArr[pointer];
            }
        }
        return mat;
    }
}