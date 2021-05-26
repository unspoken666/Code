package com.kuang.struct;

public class ContinueDemo {

    //continue是请假（当前循环结束，执行下一次循环） break是辞职（直接跳出循环）
    public static void main(String[] args) {
        int i = 0;
        while (i<100){
            i++;
            if(i%10==0){
                System.out.println();
                continue;
            }
            System.out.print(i+"\t");
        }
    }
}
