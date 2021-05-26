package com.set.treeSet;
/*
需求：把自定义对象按照年龄存入TreeSet中
把自定义对象存入TreeSet中一定要提供比较策略，否则会出现ClassCastException异常
比较策略分为两种，一种是内部比较器，一种是外部比较器
 */
//内部比较器就是实现Comparable接口
public class Student implements Comparable<Student>{
    private String id;
    private String name;
    private int age;

    public String getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

//    @Override
//    public int compareTo(Student o) {
//        //按照年龄比较
//        if(this.getAge() < o.getAge()){
//            return -1;
//        }else if(this.getAge() == o.getAge()){
//            return 0;
//        }else {
//            return 1;
//        }
//
//    }

    //把自定义对象按照年龄升序存入treeset中，如果年龄一样，再按照名字自然升序
    @Override
    public int compareTo(Student o){
        //按照年龄比较
        if(this.getAge() < o.getAge()){
            return -1;
        }else if(this.getAge() == o.getAge()){
            return this.getName().compareTo(o.getName());
        }else {
            return 1;
        }
    }




}
