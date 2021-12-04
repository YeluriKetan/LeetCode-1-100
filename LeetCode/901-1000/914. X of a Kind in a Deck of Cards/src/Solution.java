import java.util.Arrays;
import java.util.HashSet;

class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        Arrays.sort(deck);
        int[] countArr = new int[deck.length];
        int countArrPointer = 0;
        int x = deck[0];
        int count = 0;
        for (int i = 0; i < deck.length; i++) {
            if (deck[i] == x) {
                count++;
            } else {
                countArr[countArrPointer] = count;
                countArrPointer++;
                x = deck[i];
                count = 0;
                i--;
            }
        }
        countArr[countArrPointer] = count;
        HashSet<Integer> set = new HashSet<>(countArrPointer + 2, 1);
        for (int i = 0; i < countArr.length; i++) {
            set.add(countArr[i]);
        }
        set.remove(0);
        Integer[] finalArr = set.toArray(new Integer[0]);
        int gcd = finalArr[0];
        for (int i = 1; i < finalArr.length; i++) {
            gcd = egcd(gcd, finalArr[i]);
        }
        if (gcd == 1) {
            return false;
        } else {
            return true;
        }
    }

    public int egcd(int a, int b) {
        if (b != 0) {
            return egcd(b, a % b);
        } else {
            return a;
        }
    }
}

