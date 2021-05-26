package com.kuang.lambda;

public class TestLambda2 {


    public static void main(String[] args) {
        ILove love = null;

        //1.lambda表示简化
        love = (int a)-> {
            System.out.println("I love you->>"+a);
        };

        //简化1.参数类型
        love = (a)-> {
            System.out.println("I love you->>"+a);
        };

        //简化2.简化括号
        love = a -> {
            System.out.println("I love you->>"+a);
        };

        //简化3.去掉大括号
        love = a -> System.out.println("I love you->>"+a);

        //总结：
        //lambda表达式只能有一行代码的情况下才能简化为一行，如果有多行，那么就用代码块包裹，可以去掉大括号是因为代码只有一行
        //前提是接口为函数式接口
        //多个参数也可以去掉参数类型，要去掉就都去掉，必须加上括号

        love.love(521);


    }

}

interface ILove{
    void love(int a);
}


