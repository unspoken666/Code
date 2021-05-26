package com.kuang.state;

import com.kuang.demo01.TestThread4;

//模拟网络延时：放大问题的发生性
public class TestSleep implements Runnable{
    //票数
    int ticketNums = 10;

    @Override
    public void run() {
        while (true){
            if(ticketNums<=0){
                break;
            }
            //模拟延时
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println(Thread.currentThread().getName()+"拿到了"+ticketNums--+"票");
        }
    }

    public static void main(String[] args) {
        TestThread4 ticket = new TestThread4();

        new Thread(ticket,"小明").start();
        new Thread(ticket,"老师").start();
        new Thread(ticket,"黄牛党").start();

    }
}
