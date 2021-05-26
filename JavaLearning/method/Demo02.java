package com.kuang.method;

public class Demo02 {
    public static void main(String[] args) {
        int max = max(10,20);
        System.out.println(max);
    }

    //比大小
    public static double max(double num1,double num2){
        double result = num2;
        if(num1==num2){
            System.out.println("num1==num2");
            return 0;
        }
        if(num1>num2){
            result = num1;
        }
        return result;
    }

    //比大小
    public static int max(int num1,int num2){
        int result = num2;
        if(num1==num2){
            System.out.println("num1==num2");
            return 0;
        }
        if(num1>num2){
            result = num1;
        }
        return result;
    }

    //比大小
    public static int max(int num1,int num2,int num3){
        int result = num2;
        if(num1==num2){
            System.out.println("num1==num2");
            return 0;
        }
        if(num1>num2){
            result = num1;
        }
        return result;
    }
}
