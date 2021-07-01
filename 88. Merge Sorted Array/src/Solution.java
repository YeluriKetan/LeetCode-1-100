class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        if (n == 0) {
            return ;
        } else if (m == 0) {
            for (int i = 0; i < m + n; i++) {
                nums1[i] = nums2[i];
            }
            return ;
        }
        int[] newArr = new int[m + n];
        int pointer1 = 0;
        int pointer2 = 0;
        for (int i = 0; i < m + n; i++) {
            if ((pointer2 < n) && (nums1[pointer1] > nums2[pointer2] || (pointer1 >= m))) {
                newArr[i] = nums2[pointer2];
                pointer2++;
            } else {
                newArr[i] = nums1[pointer1];
                pointer1++;
            }
        }
        for (int i = 0; i < m + n; i++) {
            nums1[i] = newArr[i];
        }
    }
}
