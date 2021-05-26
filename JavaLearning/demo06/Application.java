//package com.oop.demo06;
//
//import com.oop.demo06.Person;
//import com.oop.demo06.Student;
//
//
//public class Application {
//    public static void main(String[] args) {
//        //一个对象的实际类型是确定的
//        //new Student();
//        //new Person();
//
//        //可以指向的引用类型就不确定了:父类的引用指向子类
//
//        //Student能调用的方法都是自己的或者继承父类的！
//        Student s1 = new Student();
//        //Person 父类，可以指向子类，但是不能调用子类独有的方法
//        Person s2 = new Student();
//        Object s3 = new Student();
//
//        s1.run();
//        s2.run();//子类重写了父类的方法，执行子类的方法
//        //s2.eat();//对象能执行哪些方法，主要看对象左边的类型，和右边关系不太
//        ((Student)s2).eat();
//        s1.eat();
//
//
//    }
//
//
//}
//
//

//import com.oop.demo06.Person;
//import com.oop.demo06.Student;
//
//public class Applocation {
//    public static void main(String[] args) {
//        //类型之间的转化  ：父与子
//        //  高    低
////        Person obj = new Student();
////        //student 将这个对象转换为Student类型，我们就可以使用Student类型的方法L
////        ((Student) obj) .go();
//
//        //子类转换为父类，可能丢失自己的本来的一些方法！
//        Student student = new Student();
//        student.go();
//        Person person = student;  //低转高
//
//
//
//    }
//}
///*
//1. 父类引用指向子类的对象
//2. 把子类转换为父类，向上转型：（直接转）
//3. 把父类转换为子类，向下转型：强制类型转换
//4. 方便方法的通用，减少重复的代码，简洁
//
//抽象：封装，继承，多态！  抽象类，接口
// */
