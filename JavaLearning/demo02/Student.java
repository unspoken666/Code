package com.oop.demo02;

public class Student {

    //属性：字段
    String name;
    int age;

    //方法
    public void study(){
        System.out.println(this.name+"在学习");
    }

}

/*
Person--> 身高，体重，年龄，国家
学程序好？对世界进行更好的建模---宅！ 音乐 旅游 出国
 */
/*
    public static void main(String[] args) {
        //类，抽象的，实例化
        //类实例化后会返回一个自己的对象
        //student 对象就是一个Student类的具体实例
        Student xiaoming = new Student();
        Student xiaohong = new Student();

        xiaoming.name = "小明";
        xiaoming.age = 3;

        System.out.println(xiaoming.name);
        System.out.println(xiaoming.age);

        xiaohong.name = "小红";
        xiaohong.age = 3;

        System.out.println(xiaohong.name);
        System.out.println(xiaohong.age);

    }
 */