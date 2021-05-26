package com.oop.demo06;

public class Person {

}


/*
多态注意事项：
1. 多态是方法的多态，属性没有多态
2. 父类和子类，有联系 String Person 类型转换异常 ClassCastException!
3. 存在条件：继承关系，方法需要重写,父类引用指向子类对象！ Father f1 = new Son();

以下方法是不能重写的：
       1. static 方法属于类，它不属于实例
       2. final 常量
       3. private方法
 */

    //Object > String
    //Object > Person > Teacher
    //Object > Person > Student
//        System.out.println(X instanceof Y);//能不能通过编译
//    Object object = new Student();
//        System.out.println(object instanceof Student);//true
//                System.out.println(object instanceof Person);//true
//                System.out.println(object instanceof Object);//true
//                System.out.println(object instanceof Teacher);//False
//                System.out.println(object instanceof String);//False
//                System.out.println("==============================");
//                Person person = new Student();
//                System.out.println(person instanceof Student);//true
//                System.out.println(person instanceof Person);//true
//                System.out.println(person instanceof Object);//true
//                System.out.println(person instanceof Teacher);//False
//                //System.out.println(person instanceof String);//编译报错
//                System.out.println("==============================");
//                Student student = new Student();
//                System.out.println(student instanceof Student);//true
//                System.out.println(student instanceof Person);//true
//                System.out.println(student instanceof Object);//true
////System.out.println(student instanceof Teacher);//编译报错
////System.out.println(student instanceof String);//编译报错