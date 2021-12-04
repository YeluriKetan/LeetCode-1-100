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
        int numOfTestCases = sc.nextInt();
        Codechef codechef = new Codechef();
        for (int i = 0; i < numOfTestCases; i++) {
            System.out.println(codechef.answer(sc.nextLong(), sc.nextLong()));
        }
    }

    private long answer(long l, long r) {
        return (r / 3) - ((l - 1) / 3);
    }
}
