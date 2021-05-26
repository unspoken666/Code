package com.kuang.method;

import java.util.Arrays;

public class Demo04 {
    public static void main(String[] args) {
        Demo04 demo04 = new Demo04();
        demo04.test(1,2,3,4,5);
        //调节可变参数的方法
        printMax(34,3,3,2,56.5);
        printMax(new double[]{1,2,3});

    }

    public static void printMax(double... numbers){
        if(numbers.length ==0){
            System.out.println("No argument passed");
            return;
        }
        double result = numbers[0];

        //遍历！
        for (int i = 1; i < numbers.length; i++) {
            if(numbers[i] > result){
                result = numbers[i];
            }
        }
        System.out.println("The max value is " + result);
    }

    public void method(){}
    public void method(int i){}
    public void method(int i,int i2){}
    public void method(int i,double i2){}

    public void test(int... i){
        System.out.println(Arrays.toString(i));
    }

}
