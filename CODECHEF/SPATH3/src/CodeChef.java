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
        int numOfTestCases = sc.nextInt();
        for (int i = 0; i < numOfTestCases; i++) {
            System.out.println(codechef.answer(sc.nextInt() - 1, sc.nextInt() - 1, sc.nextInt(), sc.nextInt()));
        }
    }

    private int answer(int n, int m, int x, int y) {
        int i = x*m - x*n + y*n;
        int j = 2*x - y;

        return -i/j + 1;
    }
}

