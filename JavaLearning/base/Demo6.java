package com.kuang.base;

public class Demo6 {
    public static void main(String[] args) {
        int money = 10_0000_0000;
        System.out.println(money);
        int year = 20;
        int sum1 = money*year;
        long sum2 = money*year;
        long sum3 = money*(long)year;
        System.out.println(sum1);
        System.out.println(sum2);
        System.out.println(sum3);
    }




}
