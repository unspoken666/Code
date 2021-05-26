package com.kuang.struct;

public class TestDemo {
    public static void main(String[] args) {
        //打印三角形
        for (int i = 1; i < 6; i++) {
            for (int j = 5; j >= i; j--) {
                System.out.print(" "+"\t");
            }
//            for (int j = 1; j <= i; j++) {
//                System.out.print("*"+"\t");
//            }
//            for (int j = 1; j < i; j++) {
//                System.out.print("*"+"\t");
//            }
            for (int j = 0; j < 2*i-1; j++) {
                System.out.print("*"+"\t");
            }

            System.out.println();
        }
    }
}
