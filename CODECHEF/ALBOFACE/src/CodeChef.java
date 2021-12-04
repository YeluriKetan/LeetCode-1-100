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
        Codechef codechef = new Codechef();
        for (int i = 0; i < num; i++) {
            System.out.println(codechef.answer(sc.nextLong()));
        }
    }

    private String answer(long n) {
        boolean winner = false;
        while (n != 0) {
            winner = !winner;
            if (n % 2 == 0) {
                if (n % 4 == 0) {
                    while (n % 2 == 0) {
                        n /= 2;
                    }
                    if ((n - 1) % 4 != 0) {
                        n *= 2;
                    }
                } else {
                    n /= 2;
                }
            } else {
                n--;
            }
        }
        return winner ? "Alice" : "Bob";
    }
}
