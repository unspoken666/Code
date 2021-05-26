package com.kuang.demo01;

//创建线程方式一：继承Thread类，重写run()方法，调用start开启线程

//总结：注意线程开启不一定立即执行，由CPU调用执行

public class TestThread1 extends Thread{
    @Override
    public void run() {
        //run方法线程体
        for (int i = 0; i < 20; i++) {
            System.out.println("我在看代码---"+i);
        }
    }

    public static void main(String[] args) {
        //main线程，主线程

        //创建一个线程对象
        TestThread1 testThread1 = new TestThread1();

        //调用start()方法开启线程
        testThread1.start();  //start()多条执行路径，主线程和子线程并行交替执行

        //调用run()方法开启线程
//        testThread1.run();  //run()只有主线程一条执行路径，先执行完线程然后主线程


        for (int i = 0; i < 200; i++) {
            System.out.println("我在学习多线程---"+i);
        }
    }
}
