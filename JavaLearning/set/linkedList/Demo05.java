package com.set.linkedList;

import java.util.LinkedList;

public class Demo05 {
    public static void main(String[] args) {
        //以栈的形式访问
        LinkedList stack1 = new LinkedList();

        //入栈
        stack1.push("apple");
        stack1.push("banana");

        //出栈
        System.out.println(stack1.pop());
        System.out.println(stack1.pop());

        //如果栈中没有元素，抛出NoSuchElementException
        //System.out.println(stack1.pop());



    }


}
