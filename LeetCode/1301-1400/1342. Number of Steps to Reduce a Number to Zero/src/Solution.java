class Solution {
    public int numberOfSteps (int num) {
        char x = 0;
        while (num > 0) {
            if (num % 2 == 0) {
                num/=2;
            } else {
                num--;
            }
            x++;
        }
        return (int) x;
    }
}