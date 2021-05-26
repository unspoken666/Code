package com.exception.demo01;

public class Test2 {
    public static void main(String[] args) {
        int a = 1;
        int b = 0;

        //Ctrl + Alt + T
        try {
            if(b==0){//主动抛出异常  throw throws
                throw new ArithmeticException();
            }
            System.out.println(a/b);
        } catch (Exception e) {
            e.printStackTrace();//打印错误的栈信息
            System.exit(1);//程序结束
        } finally {
        }
    }

}
