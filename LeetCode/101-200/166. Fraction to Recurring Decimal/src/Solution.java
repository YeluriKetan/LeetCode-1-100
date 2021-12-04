import java.util.HashMap;

class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        StringBuilder str = new StringBuilder();
        HashMap<Long, Integer> map = new HashMap<>();
        long num = numerator;
        long den = denominator;
        int sign = 1;
        if (num < 0) {
            num *= -1;
            sign *= -1;
        }
        if (den < 0) {
            den *= -1;
            sign *= -1;
        }
        str.append(num / den);
        num = num % den;
        if (num != 0) {
            str.append('.');
        }
        while (num != 0) {
            if (num * 10 < den) {
                str.append(0);
                num *= 10;
            } else {
                if (map.containsKey(num)) {
                    str.insert(map.get(num), "(");
                    str.append(')');
                    break;
                } else {
                    map.put(num, str.length());
                    str.append((num * 10) / den);
                    num = (num * 10) % den;
                }
            }
        }
        if (sign == -1) {
            str.insert(0, '-');
        }
        return str.toString();
    }
}