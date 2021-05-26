package com.oop.demo02;

//一个项目应该只有一个main方法
public class Application {

    public static void main(String[] args) {
        Pet dog = new Pet();
        dog.name = "旺财";
        dog.age = 3;
        dog.shout();
        System.out.println(dog.name);
        System.out.println(dog.age);
    }
}
