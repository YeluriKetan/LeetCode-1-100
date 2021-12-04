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
            int currInt = sc.nextInt();
            codechef.answer(currInt);
        }
    }

    private void answer(int currInt) {
        if (currInt != 1 ){
            System.out.print(3);
        }
        for (int i = 1; i < currInt - 1; i++) {
            System.out.print(0);
        }
        System.out.println(3);
    }
}
