package com.kuang.struct;

public class BreakDemo {
    public static void main(String[] args) {
        int i = 0;
        while(i<100){
            i++;
            System.out.println(i);
            if(i==30){
                break;
            }
        }
        System.out.println("123");
    }
}
