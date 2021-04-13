/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pkg16.pkg02.pkg04.pkg024_offline_9_lcs;

import static java.lang.Integer.max;
import java.util.Scanner;

/**
 *
 * @author USER
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner sc = new Scanner(System.in);
        String s1, s2;
        System.out.println("Enter the first string:");
        s1 = sc.next();
        System.out.println("Enter the second string:");
        s2 = sc.next();
        int m = s1.length();
        int n = s2.length();
        int cost[][] = new int[200][200];
        char x[] = new char[m + 5];
        char y[] = new char[n + 5];
        for (int i = 0; i < m; i++) {
            x[i] = s1.charAt(i);
        }
        for (int j = 0; j < n; j++) {
            y[j] = s2.charAt(j);
        }
        for (int i = 0; i <= m; i++) {
            cost[i][0] = 0;
            //x[i]=s1.charAt(i);
        }
        for (int j = 0; j <= n; j++) {
            cost[0][j] = 0;
            //y[j]=s2.charAt(j);
        }
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    cost[i][j] = 0;
                } else if (x[i] == y[j]) {
                    cost[i][j] = cost[i - 1][j - 1] + 1;
                } else {
                    int a = max(cost[i - 1][j], cost[i][j - 1]);
                    cost[i][j]=a;
                }
            }
        }
        int lastPos = cost[m][n];
        char lcs[] = new char[lastPos + 1];
        lcs[lastPos] = '\0';
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (x[i - 1] == y[j - 1]) {
                lcs[lastPos - 1] = x[i - 1];
                i--;
                j--;
                lastPos--;
            } else if (cost[i - 1][j] > cost[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        System.out.println("LCS is:");
        for (int k = 0; k < lcs.length; k++) {
            System.out.print(lcs[k]);
        }
        System.out.println("");
        //char lc = lcs[lastVal];

    }

}
