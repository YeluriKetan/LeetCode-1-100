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
            System.out.println(ans(sc.nextInt()));
        }
    }
    private static int ans(int x) {
        int max = Integer.highestOneBit(x);
        int a = x - max + 1;
        return Math.max(a, max / 2);
    }
}
