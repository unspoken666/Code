package com.kuang.struct;

import java.util.Scanner;

public class IfDemo03 {
    public static void main(String[] args) {
        //考试分数大于60分就是及格，小于60分就不及格
        Scanner scanner = new Scanner(System.in);


        /**
         * if 语句至多有1个 else 语句，else语句在所有的 else if 语句之后
         * if 语句可以有若干个 else if 语句，它们必须在else 语句之前
         * 一旦其中一个 else if 语句检测为 true,其他的 else if 以及 else 语句都将跳过执行
         */

        System.out.println("请输入成绩：");
        int score = scanner.nextInt();


        if(score==100){
            System.out.println("恭喜满分");
        }else if(score<100 && score>=90){
            System.out.println("A级");
        }else if(score<90 && score>=80){
            System.out.println("B级");
        }else if(score<80 && score>=70){
            System.out.println("C级");
        }else if(score<70 && score>=60){
            System.out.println("D级");
        }else if(score<60 && score>=0){
            System.out.println("不及格");
        }else{
            System.out.println("成绩不合法");

        }

        scanner.close();
    }
}
