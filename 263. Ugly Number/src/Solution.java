class Solution {
    public static boolean isUgly(int num) {
        int val = num;
        int[] arr5 = {1, 5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125, 244140625, 1220703125};
        int[] arr3 = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907,
                43046721, 129140163, 387420489, 1162261467};
        int[] arr2 = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144,
                524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912,
                1073741824};
        if (true) {
            int low = 0;
            int high = 13;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (low == mid) {
                    if (val % arr5[high] == 0) {
                        val = val/arr5[high];
                    } else {
                        val = val/arr5[mid];
                    }
                    break;
                }
                if (val % arr5[mid] == 0) {
                    low = mid;
                } else {
                    high = mid - 1;
                }
            }
        }
        if (true) {
            int low = 0;
            int high = 19;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (low == mid) {
                    if (val % arr3[high] == 0) {
                        val = val/arr3[high];
                    } else {
                        val = val/arr3[low];
                    }
                    break;
                }
                if (val % arr3[mid] == 0) {
                    low = mid;
                } else {
                    high = mid - 1;
                }
            }
        }
        if (true) {
            int low = 0;
            int high = 30;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (low == mid) {
                    if (val % arr2[high] == 0) {
                        val = val/arr2[high];
                    } else {
                        val = val/arr2[mid];
                    }
                    break;
                }
                if (val % arr2[mid] == 0) {
                    low = mid;
                } else {
                    high = mid - 1;
                }
            }
        }
        return val == 1;
    }
}