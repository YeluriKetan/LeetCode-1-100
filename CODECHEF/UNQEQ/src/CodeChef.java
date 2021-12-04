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
            codechef.answer(sc.nextInt());
        }
    }

    private void answer(int n) {
        if (n % 4 != 0) {
            System.out.println("NO");
            return;
        }

        System.out.println("YES");
        for (int i = 1; i <= n/4; i++) {
            System.out.print(2 * i - 1 + " ");
        }
        for (int i = n/4 + 1; i <= n/2; i++) {
            System.out.print(2 * i + " ");
        }
        System.out.println("");
        for (int i = 1; i <= n/4; i++) {
            System.out.print(2 * i + " ");
        }
        for (int i = n/4 + 1; i <= n/2; i++) {
            System.out.print(2 * i - 1 + " ");
        }
    }
}
