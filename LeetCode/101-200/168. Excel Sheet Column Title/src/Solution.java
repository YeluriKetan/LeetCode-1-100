class Solution {
    public String convertToTitle(int columnNumber) {
        StringBuilder sol = new StringBuilder();
        int num = columnNumber;
        int curr;
        while(num > 0) {
            curr = num % 26;
            if (curr == 0) {
                sol.append((char) 90);
                num/=26;
                num--;
            } else {
                sol.append((char) (curr + 64));
                num/=26;
            }

        }
        sol.reverse();
        return sol.toString();
    }
}