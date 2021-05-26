package com.kuang.struct;

public class ForDemo01 {
    public static void main(String[] args) {
        int a = 1;//初始化条件

        while(a<=100){//条件判断
            System.out.println(a);
            a +=2;//迭代

        }
        System.out.println("while循环结束！");
        //初始化//条件判断//迭代
        for(int i=1;i<=100;i++){
            System.out.println(i);
        }
        System.out.println("for循环结束");


        /**
         * 关于 for循环的几点说明：
         * 最先执行初始化步骤，可以声明一种类型，但可初始化一个或多个循环控制变量，也可以是空语句
         * 执行一次循环后，更新循环控制变量（迭代银子控制循环变量的增减）
         * 再次尖刺不二表达式。循环执行上面的过程
         */

        //死循环
        for (; ; ) {
            
        }
        
    }
}
