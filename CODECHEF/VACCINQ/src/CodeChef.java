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
            codechef.answer(sc);
        }
        sc.close();
    }

    private void answer(Scanner sc) {
        int n, p, x, y, t = 0;
        n = sc.nextInt();
        p = sc.nextInt();
        x = sc.nextInt();
        y = sc.nextInt();
        for (int i = 0; i < p; i++) {
            if (sc.nextInt() == 0) {
                t += x;
            } else {
                t += y;
            }
        }
        System.out.println(t);
    }
}
