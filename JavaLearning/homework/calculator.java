package com.kuang.homework;

import java.util.Scanner;

public class calculator {

    public static int add(int... numbers){
        int result = numbers[0];
        for (int i = 1;i<numbers.length;i++) {
            result += numbers[i];
        }
        return result;
    }
    public static double add(double... numbers){
        double result = numbers[0];
        for (int i = 1;i<numbers.length;i++) {
            result += numbers[i];
        }
        return result;
    }

    public static int subtract(int... numbers){
        int result = numbers[0];
        for (int i = 1;i<numbers.length;i++) {
            result -= numbers[i];
        }
        return result;
    }
    public static double subtract(double... numbers){
        double result = numbers[0];
        for (int i = 1;i<numbers.length;i++) {
            result -= numbers[i];
        }
        return result;
    }

    public static int mutiply(int... numbers){

        int result = numbers[0];
        for (int i = 1;i<numbers.length;i++) {
            result *= numbers[i];
        }
        return result;
    }
    public static double mutiply(double... numbers){

        double result = numbers[0];
        for (int i = 1;i<numbers.length;i++) {
            result *= numbers[i];
        }
        return result;
    }

    public static int divide(int... numbers){
        int result = numbers[0];
        for (int i = 1;i<numbers.length;i++) {
            result /= numbers[i];
        }
        return result;
    }
    public static double divide(double... numbers){
        double result = numbers[0];
        for (int i = 1;i<numbers.length;i++) {
            result /= numbers[i];
        }
        return result;
    }

    public static void main(String[] args) {
        System.out.println("加法" + add(1,2,3));
        System.out.println("减法" + subtract(1,2,3));
        System.out.println("乘法" + mutiply(1,2,3));
        System.out.println("除法" + divide(1,2,3));
        System.out.println("加法" + add(1.0,2.0,3.0));
        System.out.println("减法" + subtract(1.0,2.0,3.0));
        System.out.println("乘法" + mutiply(1.0,2.0,3.0));
        System.out.println("除法" + divide(1.0,2.0,3.0));

    }
}
