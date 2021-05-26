package com.kuang.state;

//观察测试线程的状态
public class TestState {

    public static void main(String[] args) throws InterruptedException {
        Thread thread = new Thread(()->{
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("////////////");
        });

        //观察状态
        Thread.State state = thread.getState();
        System.out.println(state);    //NEW


        //观察启动后
        thread.start();  //启动线程
        state = thread.getState();
        System.out.println(state);   //Run

        while (state != Thread.State.TERMINATED){
            //只要线程不终止，就一直输出状态
            Thread.sleep(100);
            state = thread.getState();//更新线程的状态
            System.out.println(state);//输出状态
        }
        //thread.start();  线程不能启动两次，死亡之后的线程不能再启动


    }

}
