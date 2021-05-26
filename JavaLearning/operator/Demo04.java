package com.kuang.operator;

public class Demo04 {
    public static void main(String[] args) {
        //++ -- 自增,自减
        int a = 3;
        int b = a++;//执行完这行代码之后,先给b赋值,再自增
        int c = ++a;//执行完这行代码之前,先自增,再给b赋值

        System.out.println(a);
        System.out.println(b);
        System.out.println(c);

        //幂运算  很多运算我们会使用一些工具类来操作
        double pow = Math.pow(2,3);
        System.out.println(pow);

    }
}
