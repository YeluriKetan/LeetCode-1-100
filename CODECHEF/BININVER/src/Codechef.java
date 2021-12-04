/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
    private static Codechef codechef;
    private static Scanner sc;

    public static void main (String[] args) throws java.lang.Exception {
        codechef = new Codechef();
        sc = new Scanner(System.in);
        int num = sc.nextInt();
        for (int i = 0; i < num; i++) {
            codechef.ans();
        }
        sc.close();
    }

    private void ans() {
        int total = sc.nextInt();
        int[] arr = new int[total];
        for (int i = 0; i < total; i++) {
            arr[i] = sc.nextInt();
        }
        int curr = 0;
        while (true) {
            for (int j = 0; j < total; j++) {
                if (arr[j] % 2 != 0) {
                    System.out.println(curr);
                    return;
                } else {
                    arr[j] /= 2;
                }
            }
            curr++;
        }

    }
}
