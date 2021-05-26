package com.oop.demo01;

import java.io.IOException;

public class Demo01 {

    //main方法
    public static void main(String[] args) {

    }


    /**
     * 修饰符 返回值类型 方法名(...){
     *     //方法体
     *     return 返回值;
     * }
     *
     */
    public String sayHello(){
        return "hello,world!";
    }

    //return 结束方法，返回一个结果
    public void hello(){
        return;
    }

    //注意规范，见名知意
    public int max(int a,int b){
        return a>b?a:b;  //三元运算符
    }

    //数组下标越界 ArrayindexoutofBounds
    public void readFile(String file) throws IOException{

    }

}
