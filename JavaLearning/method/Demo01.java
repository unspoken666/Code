package com.kuang.method;

public class Demo01 {
    //main方法
    public static void main(String[] args) {

        //实际参数：实际调用传递给他的参数
        int sum = add(1,2);
        System.out.println(sum);
        //test();
    }

    //加法
    //形式参数，用来定义作用的
    public static int add(int a,int b){
        return a+b;
    }

    //加法
    public static double add(double a,double b){
        return a+b;
    }

    //加法
    public static float add(float a,float b){
        return a+b;
    }

    //加法
    public static int add(int a,int b,int c){
        return a+b+c;
    }

    //加法
    public static double add(double a,double b,double c){
        return a+b+c;
    }

    //加法
    public static float add(float a,float b,float c){
        return a+b+c;
    }



    public static void test(){
        for (int i = 0; i <= 1000; i++) {
            if(i%5 == 0){
                System.out.print(i+"\t");
            }
            if(i%15 == 0){
                System.out.println();
            }
        }
    }
}
