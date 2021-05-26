package com.kuang.struct;

public class WhileDemo03 {
    public static void main(String[] args) {
        //计算1+2+...+100=?
        int i = 0;
        int sum = 0;

        while (i < 100){
            i++;
            sum += i;

        }

        System.out.println(sum);

    }
}
