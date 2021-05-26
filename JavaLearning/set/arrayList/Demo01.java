package com.set.arrayList;

import com.oop.demo02.Pet;

import java.util.ArrayList;

public class Demo01 {
    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        System.out.println(list instanceof ArrayList);
        System.out.println(list instanceof ArrayList<?>);
//        System.out.println(list instanceof ArrayList<Integer>);//error
        //泛型就是程序设计过程中将类型参数化

    }

    //1. 泛型的上限
    public static void print(ArrayList<? extends Pet> list){
        for (Pet pet:list){
            pet.showInfo();
        }
    }
    /*
    <? extends A>表示 ? 必须A的子类，A作为上限已经确定
    ArrayList<? extends A> list 表示声明了一个容器list,list中存储的元素必须是A的子类
     */

    //2. 泛型的下限
    /*
    <? super A>表示 ? 必须A的父类，A作为下限已经确定
    ArrayList<? extends A> list 表示声明了一个容器list,list中存储的元素必须是A的父类
     */

}
