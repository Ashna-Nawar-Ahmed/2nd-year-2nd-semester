/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bisectionmethod;

import java.util.Scanner;

/**
 *
 * @author ashna
 */
public class BisectionMethod {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        double x1 = 0, x2 = 0, E = 0.001, x0, f1 = 1, f2 = 1, f0, root = 1;
         int itr=1;
        Scanner input = new Scanner(System.in);
        while (f1 * f2 > 0) {
            System.out.println("Enter x1,x2:");
            x1 = input.nextDouble();
            x2 = input.nextDouble();

            f1 = f(x1);
            f2 = f(x2);
            if(f1*f2>0)
                System.out.println("Invalid");
        }
        while (root > E) {
            x0 = (x1 + x2) / 2;
            f0 = f(x0);
            System.out.println("Iteration:"+itr+" x1="+x1+" x2="+x2+" x0="+x0+" f1="+f1+" f2="+f2+" f0="+f0);
            itr++;
            if (f0 == 0) {
                root = x0;
                System.out.println("Root:" + root);
                break;
            }
            if (f1 * f0 < 0) {
                x2 = x0;
            } else {
                x1 = x0;
            }
            if (Math.abs((x2 - x1) / x2) < E) {
                root = (x1 + x2) / 2;
                System.out.println("Root:" + root);
                //break;
            }
        }
    }

    public static double f(double x) {
        return (x * x - 4 * x - 10);
    }

}
