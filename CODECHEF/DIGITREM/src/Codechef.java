/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        for (int i = 0; i < num; i++) {
            System.out.println(ans(sc.nextInt(), sc.nextInt()));
        }
    }
    private static int ans(int n, int d) {
        String s1 = String.valueOf(n);
        int index = s1.indexOf(d + 48);
        if (index == -1) {
            return 0;
        }
        String s2 = s1.substring(0, index + 1);
        int newN = (Integer.parseInt(s2) + 1) * (int) Math.pow(10, s1.length() - index - 1);
        return ans(newN, d) + newN - n;
    }
}
