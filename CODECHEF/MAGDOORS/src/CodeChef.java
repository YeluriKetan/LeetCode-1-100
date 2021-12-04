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
        sc.nextLine();
        for (int i = 0; i < num; i++) {
            System.out.println(codechef.answer(sc.nextLine()));
        }
    }

    private int answer(String str) {
        boolean flip = false;
        int t = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '0') {
                if (!flip) {
                    flip = true;
                    t++;
                }
            } else {
                if (flip) {
                    flip = false;
                    t++;
                }
            }
        }
        return t;
    }
}
