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
            System.out.println(codechef.ans(sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt()));
        }
    }
    private int ans(int a, int b, int c, int d) {
        int space = d - c;
        int total = 3;
        if (b <= space) {
            total--;
            space -= b;
        }
        if (a <= space) {
            total--;
        }
        if (total == 3 && a + b <= d) {
            total--;
        }
        return total;
    }
}
