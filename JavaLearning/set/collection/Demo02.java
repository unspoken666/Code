package com.set.collection;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;

//iterable表示课遍历的，具备遍历的能力，
//其定义了一个方法iterator用于返回集合上的迭代器，该迭代器用于foreach快速遍历
public class Demo02 {
    public static void main(String[] args) {
        Collection collection1 = new ArrayList();
        collection1.add("apple");
        collection1.add("coco");
        collection1.add("banana");
        /*
        Object表示迭代元素类型
        item表示迭代变量
         */
        //快速遍历
        for (Object item:collection1) {
            System.out.println(item);

        }

        //迭代器遍历
        Iterator it1 = collection1.iterator();//返回集合的迭代器
        while (it1.hasNext()){
            System.out.println(it1.next());
        }

        //写法（更节省内存）
        for (Iterator it2 = collection1.iterator();it2.hasNext();){
            System.out.println(it2.next());
        }
    }
}
