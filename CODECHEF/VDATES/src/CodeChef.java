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
        int numOfTest = sc.nextInt();
        Codechef codechef = new Codechef();
        for (int i = 0; i < numOfTest; i++) {
            System.out.println(codechef.answer(sc.nextInt(), sc.nextInt(), sc.nextInt()));
        }
    }

    private String answer(int d, int l, int r) {
        if (d < l) {
            return "Too Early";
        } else if (d > r) {
            return "Too Late";
        } else {
            return "Take second dose now";
        }
    }
}
