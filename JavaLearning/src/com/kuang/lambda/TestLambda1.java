package com.kuang.lambda;

/*
推导Lambda表达式
 */
public class TestLambda1 {

    //3.静态内部类
    static class Like2 implements ILike{
        @Override
        public void lambda() {
            System.out.println("I like lambada2");
        }
    }

    public static void main(String[] args) {
        ILike like = new Like();
        like.lambda();

        like = new Like2();
        like.lambda();

        //4.局部内部类
        class Like3 implements ILike{
            @Override
            public void lambda() {
                System.out.println("I like lambada3");
            }
        }

        like = new Like3();
        like.lambda();

        //5.匿名内部类,没有类的名称，必须借助接口或者父类
        like = new ILike() {
            @Override
            public void lambda() {
                System.out.println("I like lambada4");

            }
        };
        like.lambda();

        //6.用lambda简化
        like = ()->{
            System.out.println("I like lambada5");
        };
        like.lambda();

    }
}

//1.定义一个函数式接口
interface ILike{
    void lambda();
}

//2.实现类
class Like implements ILike{
    @Override
    public void lambda() {
        System.out.println("I like lambada");
    }
}