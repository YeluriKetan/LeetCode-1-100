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
            System.out.println(codechef.answer(sc.nextInt(), sc.nextInt()));
        }
    }

    private String answer(int a, int b) {
        if (b == 1) {
            if (a == 1) {
                return "YES";
            }
            return "NO";
        }
        long A = a;
        long B = b;
        while (true) {
            if (B % A == 0) {
                return "YES";
            } else {
                if (Long.MAX_VALUE / b >= B) {
                    B *= b;
                } else {
                    break;
                }
            }
        }
        return "NO";
    }
}
