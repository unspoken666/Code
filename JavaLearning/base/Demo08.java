package com.kuang.base;

public class Demo08 {

    //类变量 static
    static double salary = 2500;


    //属性:变量
    //实例变量:从属于对象; 如果不自行初始化,这个类型的默认值  0  0.0
    //布尔值默认是false
    //除了基本类型,其余的默认值都是null;
    String name;
    int age;

    //main方法
    public static void main(String[] args) {

        //局部变量:必须声明和初始化值
        int i = 10;
        System.out.println(i);

        //变量类型  变量名字
        Demo08 demo08 = new Demo08();
        System.out.println(demo08.age);
        System.out.println(demo08.name);

        System.out.println(salary);


    }

    //其他方法
    public void add(){

    }
}
