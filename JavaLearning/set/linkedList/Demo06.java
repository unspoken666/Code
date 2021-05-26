package com.set.linkedList;

import java.util.LinkedList;

public class Demo06 {
    public static void main(String[] args) {
        //以队列（Queue接口）的方式访问LinkedList
        LinkedList queue = new LinkedList();

        //入队
        /*
        头（出口）<--------尾（入口）
        -------------------
        apple banana coco
        -------------------
         */
        queue.add("apple");
        queue.add("banana");
        queue.add("coco");
        System.out.println(queue);

        //出队
//        queue.remove();
//        queue.remove();
//        queue.remove();
        //抛出NoSuchElementException
        //queue.remove();
        System.out.println(queue);

        //检测元素：获取但不移除此列表的头（第一个元素）
        System.out.println(queue.element());
        System.out.println(queue.element());

        queue.offer("apple");
        queue.offer("banana");
        queue.offer("coco");
        System.out.println(queue);

        queue.poll();
        System.out.println(queue);
        queue.poll();
        queue.poll();
        System.out.println(queue);

        //如果队列为空，返回null
        System.out.println(queue.poll());
        System.out.println(queue);
        System.out.println(queue.peek());

    }
}
