package com.set.arrayList;

import java.util.Arrays;

public class Teacher {
    public void add(int a,int b){
        System.out.println(a+b);

    }
    public void add(float a,float b){
        System.out.println(a+b);
    }
    public void add(char a,char b){
        System.out.println(a+b);
    }
    public void add(String a,String b){
        System.out.println(a+b);
    }
    public <T> void add(T a,T b){
        System.out.println(a.toString()+b.toString());
    }
    //泛型方法在一定程度上优化了方法重载，不能取代


    //泛型的可变参数
    //方法的可变参数
    public void add(int...args){
        //方法的可变参数在方法调用时，以args数组形式存在于方法中
        System.out.println(Arrays.toString(args));
    }
    public <T> void add(T...args){
        //泛型的可变参数方法进一步优化了方法重载，不能完全取代
        System.out.println(Arrays.toString(args));
    }
}
