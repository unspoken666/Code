package com.kuang.operator;

public class Demo07 {
    public static void main(String[] args) {
        int a = 10;
        int b = 10;

        a+=b;//a=a+b
        a-=b;//a=a-b
        System.out.println(a);

        System.out.println(a+b);

        //字符串连接符 + ,String +号从左到右去算
        System.out.println(""+a+b);
        System.out.println(a+b+"");

    }
}
