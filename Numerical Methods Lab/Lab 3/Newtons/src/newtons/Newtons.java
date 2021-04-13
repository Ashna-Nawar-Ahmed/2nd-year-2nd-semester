/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package newtons;

import java.util.Scanner;

/**
 *
 * @author ashna
 */
public class Newtons {

    /**
     * @param args the command line arguments
     */
    static double[] coef;
    static double[] tempArray;
    static int degree;

    public static double horner(double value) {
        double result = coef[0];
        for (int i = 1; i <= degree; ++i) {
            result = result * value + coef[i];
        }
        return result;

    }

    public static void deflation(double root, int toStart) {
        for (int i = 0; i < toStart; i++) {
            tempArray[i] = 0;
        }
        for (int i = toStart; i < tempArray.length; i++) {
            tempArray[i] = coef[i - 1] + tempArray[i - 1] * root;
        }
        for (int i = 0; i < tempArray.length; i++) {
            coef[i] = tempArray[i];
        }
    }

    public static double derivative(double x) {
        int tempDegree = degree;
        double result = 0;
        for (int i = 0; i < degree; i++) {
            if (coef[i] != 0) {
                double tempResult = java.lang.Math.pow(x, (tempDegree - 1));

                tempResult *= tempDegree;
                result += tempResult;
                tempDegree -= 1;
            }
        }
        return result;
    }

    public static double error(double x1, double x0) {
        return java.lang.Math.abs((x1 - x0) / x0);
    }

    public static void main(String[] args) {
        // TODO code application logic here
        System.out.println("Enter the degree of the equation: ");

        Scanner sc = new Scanner(System.in);
        degree = sc.nextInt();
        coef = new double[degree + 1];
        tempArray = new double[degree + 1];
        System.out.println("Enter the coeffeceients from highest degree:");
        for (int i = 0; i <= degree; i++) {
            coef[i] = sc.nextInt();
        }
        double x0 = 0;
        double f0 = 0;
        double fprime = 0;
        double x1 = sc.nextDouble();
        double error = 0.001;
        double determinedError = 1;
        int n = degree;
        int start = 1;
        while (n > 1) {
            determinedError = 1;
            while (determinedError > error) {
                x0 = x1;
                f0 = horner(x0);
                fprime = derivative(x0);
                x1 = x0 - (f0 / fprime);
                determinedError = error(x1, x0);
            }
            System.out.println("root is " + x0);
            n -= 1;
            deflation(x1, start);
            start += 1;
        }
        double constant = coef[degree];
        double last = coef[degree - 1];
        System.out.println("constant is " + constant + " and last is " + last);
        System.out.println("root is " + (constant / last) * (-1));

    }

}
