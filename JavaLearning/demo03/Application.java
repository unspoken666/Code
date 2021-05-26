package com.oop.demo03;

import com.oop.demo03.Pet;

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

/*
1. 类与对象
    类是一个模板，抽象，对象是一个具体的实例
2. 方法
    定义、调用
3. 对应的引用
    引用类型：基本类型（8）
    对象是通过引用（地址）来操作的：栈-->堆
4. 属性：字段Field 成员变量
    默认初始化：
        数字：0  0.0
        char；u0000
        boolean:false
        引用：null
    修饰符 属性类型 属性名=属性值！
5.对象的创建和使用
    必须使用new 关键字创建对象 构造器 Person kuangshen = new Person();
    对象的属性 kuangshen.name
    对象的方法 kuangshen.sleep()
6. 类：
    静态的属性 属性
    动态的行为 方法


    封装、继承、多态
 */
