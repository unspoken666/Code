package com.kuang.struct;

public class ForDemo04 {
    public static void main(String[] args) {
        //打印9*9乘法表
        for (int i = 1; i < 10; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(j+"*"+i+"="+i*j+"\t");
            }
            System.out.println();
        }

    }
}
