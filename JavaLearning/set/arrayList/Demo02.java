package com.set.arrayList;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;

public class Demo02 {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<String>();
        list.add("apple");
        list.add("banana");
        list.add("coco");

        //需求：在遍历的过程中，添加元素
        Iterator<String> it = list.iterator();
        while (it.hasNext()){
            String item = it.next();
            if(item.equals("banana")){
                //list.add("test");
//                Exception in thread "main" java.util.ConcurrentModificationException
//                at java.base/java.util.ArrayList$Itr.checkForComodification(ArrayList.java:1013)
//                at java.base/java.util.ArrayList$Itr.next(ArrayList.java:967)
                //当遍历一个集合时，不能对集合进行添加操作，可能会出现并发修改异常。
                //如果要对其进行添加操作，需要使用ListIterator接口

            }
        }
        System.out.println(list);

        ListIterator<String> it2 = list.listIterator();
        while (it2.hasNext()){
            String item = it2.next();
            if(item.equals("banana")){
                it2.add("test2");
            }
        }
        System.out.println(list);

    }
}
