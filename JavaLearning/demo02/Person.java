package com.oop.demo02;

public class Person {

    //一个类即使什么也不写，也会有一个构造类，也会存在一个fangfa
    //显示的定义构造器
    String name;
    int age;

    //实例化初始值
    //1.使用new关键字，必须要有构造器，本质是在调用构造器
    //2.用来初始化值
    //无参构造
    public Person(){

    }

    //有参构造：一旦定义了有参构造，无参就必须显示定义
    public Person(String name){
        this.name = name;
    }

    //alt + insert


    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
}
/**
 * 构造器
 * 1.和类名相同
 * 2.没有返回值
 * 作用：
 * 1.new本质在调用构造方法
 * 2.初始化对象的值
 * 注意点：
 * 1.定义有参构造之后，如果想要使用无参构造，显示定义一个无参的构造
 *
 * alt+insert
 * 自动创建构造器
 */
//public static void main(String[] args) {
//
//    //new 实例化了一个对象
//    Person person = new Person("kuangshen");
//    System.out.println(person.name);
//}

