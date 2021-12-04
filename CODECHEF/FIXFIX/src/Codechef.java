/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
    public static void main (String[] args) throws java.lang.Exception {
        Codechef codechef = new Codechef();
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        for (int i = 0; i < num; i++) {
            codechef.ans(sc.nextInt(), sc.nextInt());
        }
    }

    private void ans(int n, int k) {
        if (n - 1 == k) {
            System.out.println("-1");
            return;
        }
        StringBuilder str = new StringBuilder();
        for (int i = 1; i <= k; i++) {
            str.append(i + " ");
        }
        if (k < n) {
            str.append(n + " ");
            for (int i = k + 1; i < n; i++) {
                str.append(i + " ");
            }
        }
        System.out.println(str);
    }
}
