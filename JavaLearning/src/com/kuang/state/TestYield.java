package com.kuang.state;

//测试礼让线程
//礼让不一定成功，看CPU心情
public class TestYield {

    public static void main(String[] args) {
        MyYiled myYiled = new MyYiled();

        new Thread(myYiled,"a").start();
        new Thread(myYiled,"b").start();
    }

}

class MyYiled implements Runnable{
    @Override
    public void run() {
        System.out.println(Thread.currentThread().getName()+"线程开始执行");
        Thread.yield();//礼让
        System.out.println(Thread.currentThread().getName()+"线程停止执行");
    }
}
