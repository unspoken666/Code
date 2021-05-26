package com.oop.demo04;

import com.oop.demo04.Student;

/*
1. 提高程序的安全性，保护数据
2. 隐藏代码的实现细节
3. 统一接口
4. 系统的可维护性
 */

public class Application {
    public static void main(String[] args) {

        Student s1 = new Student();
        s1.setName("秦疆");
        System.out.println(s1.getName());

        s1.setAge(70);//不合法
        System.out.println(s1.getAge());
    }
}
