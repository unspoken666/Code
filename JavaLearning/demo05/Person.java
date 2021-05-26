package com.oop.demo05;

//在Java中，所有的类，都默认直接或者间接继承object
// Person 人 ：父类
public class Person /*extends Object*/{

    public Person() {
        System.out.println("Person无参被执行了");
    }

    protected String name = "kuangshen";
    //私有的东西无法被继承
    public void print(){
        System.out.println("Person");
    }

    //public  可以继承
    //protected
    //default 默认
    //private  不可继承

//    private int money = 10_0000_0000;
//    public void say(){
//        System.out.println("说了一句话");
//    }
//
//    public int getMoney() {
//        return money;
//    }
//
//    public void setMoney(int money) {
//        this.money = money;
//    }
}
