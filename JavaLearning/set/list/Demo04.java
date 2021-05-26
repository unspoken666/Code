package com.set.list;

import java.util.LinkedList;
import java.util.List;

public class Demo04 {
    public static void main(String[] args) {
        List list1 = new LinkedList();
        //1.添加
        list1.add("apple");
        list1.add("banana");
        list1.add("coco");
        System.out.println(list1);

        //2.删除
        list1.remove("apple");

        //3.修改
        list1.set(0,"banana x");
        System.out.println(list1);

        //4.查看
        System.out.println(list1.get(0));


    }
}
