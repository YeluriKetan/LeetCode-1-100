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

    private long answer(String line) {
        String[] arr1 = line.split(" ");
        int[] arr2 = Arrays.stream(arr1).mapToInt(Integer::parseInt).toArray();
        long B = arr2[2] + (long) arr2[4] * arr2[1];
        long C = arr2[3] + (long) arr2[5] * arr2[1];
        return (long) arr2[0] / Math.max(B, C);
    }
}
