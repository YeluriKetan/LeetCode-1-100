class Solution {
    public int myAtoi(String s) {
        int result = 0;
        boolean sign = true;
        char counter = 0;
        while (counter < s.length()) {
            if (s.charAt(counter) == 32) {
                counter++;
            } else {
                break;
            }
        }
        while (counter < s.length()) {
            if (s.charAt(counter) == 45) {
                sign = false;
                counter++;
            } else if (s.charAt(counter) == 43) {
                counter++;
            }
            break;
        }
        while (counter < s.length()) {
            if (s.charAt(counter) < 58 && s.charAt(counter) > 47) {
                if (result > 214748364) {
                    if (sign) {
                        return Integer.MAX_VALUE;
                    } else {
                        return Integer.MIN_VALUE;
                    }
                } else if (result == 214748364 && s.charAt(counter) > 54) {
                    if (sign) {
                        return Integer.MAX_VALUE;
                    } else {
                        if (s.charAt(counter) > 55) {
                            return Integer.MIN_VALUE;
                        } else {
                            result = (result * 10) + 7;
                        }
                    }
                } else {
                    result = (result * 10) + (s.charAt(counter) - 48);
                }
            } else {
                break;
            }
            counter++;
        }
        if (sign) {
            return result;
        } else {
            return -1 * result;
        }
    }
}