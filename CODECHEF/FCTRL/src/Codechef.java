/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Codechef codechef = new Codechef();
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        for (int i = 0; i < num; i++) {
            System.out.println(codechef.answer(sc.nextInt()));
        }
        sc.close();
    }

    private int answer(int n) {
        int curr = 5;
        int total = 0;
        while (curr <= n) {
            total += n / curr;
            if (Integer.MAX_VALUE / 5 >= curr) {
                curr *= 5;
            } else {
                break;
            }
        }
        return total;
    }
}
