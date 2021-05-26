package com.oop.demo05;

//Student is 人  派生类 子类
// 子类继承了父类，就会拥有父亲的全部方法!
public class Student extends Person{

    //Person person;组合
    //Ctrl+H


    public Student() {
        //隐藏代码：调用了父类的无参构造
        super();//调用父类的构造器，必须要在子类构造器的第一行
        System.out.println("Student无参被执行了");
    }

    private String name = "qinjiang";

    public void print(){
        System.out.println("Student");
    }

    public void test1(){
        print();
        this.print();
        super.print();
    }
    public void test(String name){
        System.out.println(name);//秦疆
        System.out.println(this.name);//qinjiang
        System.out.println(super.name);//kuangshen
    }


}
