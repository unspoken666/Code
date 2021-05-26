package com.oop.demo07;

//被final修饰就不能被继承了 即断子绝孙  因为final是最后一代
public final class Person {
    {
        //代码块（匿名代码块）
    }
    static {
        //静态代码块
    }

    //2  ：赋初始值
    {
        System.out.println("匿名代码块");
    }

    //1  ：只执行一次
    static {
        System.out.println("静态代码块");
    }

    //3
    public Person() {
        System.out.println("构造方法");
    }

    public static void main(String[] args) {
        Person person1 = new Person();
        System.out.println("=========================");
        Person person2 = new Person();

    }
}
