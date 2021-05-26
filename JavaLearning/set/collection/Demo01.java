package com.set.collection;

import java.util.ArrayList;
import java.util.Collection;

public class Demo01 {
    /**
     * 增  add/addAll
     * 删  clear/remove/removeAll/retainAll
     * 改
     * 查  contains/containsAll/size/isEmpty
     * 其他  equals
     * 遍历  iterator()
     */
    public static void main(String[] args) {
        Collection collection1 = new ArrayList();
        collection1.add("apple");// Object obj = "apple"多态
        collection1.add("purple");
        //注意：Collection 可以添加任意类型的数据，最好添加统一类型的数据方便未来统一访问
        Collection collection2 = new ArrayList();
        collection2.add("peach");
        collection2.add("banana");
        collection1.addAll(collection2);
        System.out.println(collection1);
        System.out.println(collection2);
        collection1.remove("apple");
        collection1.retainAll(collection2);
        collection1.removeAll(collection2);
        //collection1.clear();
        collection2.remove(1);
        System.out.println(collection2.contains("apple"));
        System.out.println(collection2.containsAll(collection1));
        System.out.println(collection2.size());
        System.out.println(collection1.isEmpty());
        System.out.println(collection1.equals(collection2));

    }
}
