/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.stream.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
    public static void main (String[] args) throws java.lang.Exception
    {

        Scanner sc = new Scanner(System.in);
        int total = sc.nextInt();
        int num = sc.nextInt();
        int[] arr = new int[num];
        while (num > 0) {
            arr[num - 1] = sc.nextInt();
            num--;
        }
        sc.close();
        Arrays.sort(arr);

        long startTime = System.currentTimeMillis();
        
        IntStream stream = IntStream.range(1, total);
        for (int i = 0; i < arr.length; i++) {
            int currIndex = i;
            stream = stream.filter((curr) -> curr % arr[currIndex] != 0);
        }
        
        long ans = stream.count();
        long endTime = System.currentTimeMillis();
        System.out.println(((double) (endTime - startTime)) / 1000);
        System.out.println(ans);
    }
}
