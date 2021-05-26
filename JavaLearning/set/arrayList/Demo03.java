package com.set.arrayList;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class Demo03 {
    public static void main(String[] args) {
        /**
         * 增 :add/addAll
         * 删 :clear/remove/removeAll/retainAll
         * 改 :
         * 查 :contains/containsAll/isEmpty/equals/size
         * 遍历:iterator
         */

        Set<String> set = new HashSet<String>();
        //1.添加
        boolean r;
        r = set.add("apple");
        System.out.println(r);
        set.add("coco");
        set.add("apple");
        r = set.add("apple");
        System.out.println(r);//没有添加成功  set不能重重复
        System.out.println(set);

        //2.删除
        //set.clear();
        set.remove("coco");
        System.out.println(set);

        //set遍历
        set.add("coco");
        set.add("banana");

        //foreach
        for (String str:set){
            System.out.print(str+" ");
        }
        System.out.println();
        Iterator<String> it = set.iterator();
        while (it.hasNext()){
            System.out.print(it.next()+" ");
        }
    }
}
