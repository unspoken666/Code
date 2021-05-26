package com.oop.demo01;

public class Demo02 {
    public static void main(String[] args) {

        //静态方法 static
//            Student.say();
        //非静态方法
        //实例化这个类 new
        //对象类型 对象名=对象值

        Student student = new Student();
        student.say();



    }
    //和类一起加载的
    public void a(){
        b();
    }

    //类实例化以后才存在
    public static void b(){
        //a();
    }

}
