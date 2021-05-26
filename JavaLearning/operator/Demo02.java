package com.kuang.operator;

public class Demo02 {
    public static void main(String[] args) {
        long a = 12312312131213L;
        int b = 123;
        short c = 10;
        byte d = 8;


        //运算时,如果有一个double就是double类型,如果有一个long,就是long类型
        System.out.println(a+b+c+d);//long
        System.out.println(b+c+d);//int
        System.out.println(c+d);//int  比int精度低,默认返回的是int,否则返回的是高精度的类型

    }
}
