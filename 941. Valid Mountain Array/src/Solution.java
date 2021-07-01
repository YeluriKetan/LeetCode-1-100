class Solution {
    public boolean validMountainArray(int[] arr) {
        if (arr.length < 3 || !(arr[0] < arr[1])) {
            return false;
        }
        boolean bool = false;
        for (int i = 0; i < arr.length - 1; i++) {
            if (!bool) {
                if (arr[i] < arr[i + 1]) {
                    //
                } else if (arr[i] == arr[i + 1]) {
                    return false;
                } else {
                    if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]){
                        bool = true;
                    }
                }
            } else {
                if (arr[i] > arr[i + 1]) {
                    //
                } else {
                    return false;
                }
            }
        }
        return bool;
    }
}