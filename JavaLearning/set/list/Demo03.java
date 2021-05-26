package com.set.list;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;

/**
 * 增  add(index,e)/addAll(index,c)/add(e)/addAll(c)
 * 删  remove(index)/clear()/remove(e)/removeAll(c)/retainAll(c)
 * 改  set(index,e)
 * 查  get(index)/indexOf(e)/lastIndexOf(e)/contains/containsAll/size/isEmpty
 * 其他  equals
 * 遍历  iterator()/listIterrator()
 */

public class Demo03 {
    public static void main(String[] args) {

        List list1 = new ArrayList();

        //1. 添加
        //追加
        list1.add("apple");
        list1.add("banana");
        //在指定index位置添加元素coco
        list1.add(0,"coco");
        List list2 = new ArrayList();
        list2.add(1);
        list2.add(2);
        list1.addAll(0,list2);
        System.out.println(list1);
        System.out.println(list2);

        //2.移除
        list1.remove(0);
        System.out.println(list1);

        //3.修改
        list1.set(0,100);
        System.out.println(list1);

        //4.查看元素 可能产生IndexOutOfBoundsException
        //System.out.println(list1.get(6));
        System.out.println(list1.indexOf(200));

        list1.add(2);
        System.out.println(list1.lastIndexOf(2));

        //List接口遍历
        /*
        List接口中提供了一个listIterator方法，返回列表的列表迭代器，
        属于ListIterator接口，提供以任意方向（正向、逆向）遍历列表，同时在遍历列表的
        过程中还可以操作列表
         */

        //List集合的遍历
        List list = new ArrayList();
        list.add("apple");
        list.add("banana");
        list.add("coco");

        //1. for循环
        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i)+" ");
        }
        System.out.println();

        //2. 快速遍历
        for (Object item:list){
            System.out.print(item+" ");
        }
        System.out.println();

        //3. iterator
        Iterator it1 = list.iterator();
        while (it1.hasNext()){
            System.out.print(it1.next()+" ");
        }
        System.out.println();


        //4. listIterator获取列表的迭代器
        ListIterator it2 = list.listIterator();
        //正向遍历(A)
        while (it2.hasNext()){
            System.out.print(it2.next()+" ");
        }
        System.out.println();

        //逆向遍历(B)
        while (it2.hasPrevious()){
            System.out.print(it2.previous()+" ");
        }
        System.out.println();



        //5. 从指定的位置开始迭代(C)
        System.out.println("--listIterator(index)--");
        ListIterator it3 = list.listIterator(1);
        while (it3.hasNext()){
            System.out.print(it3.next()+" ");
        }
        System.out.println();



    }
}
