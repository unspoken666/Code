package com.set.linkedList;

import java.util.LinkedList;

public class Demo07 {
    public static void main(String[] args) {
        //以双向队列的形式访问
        LinkedList queue = new LinkedList();
        /*
        头 尾
        <--------------------------
        ---------------------------
        apple banana coco
        ---------------------------
        -------------------------->
         */
        queue.addFirst("apple");
        queue.addLast("banana");
        queue.addLast("coco");
//        queue.removeFirst();
//        queue.removeLast();
//        queue.removeLast();
//        //抛出NoSuchElementException
//        queue.removeLast();
        System.out.println(queue);
        System.out.println(queue.getFirst());
        System.out.println(queue.getLast());

    }
}
