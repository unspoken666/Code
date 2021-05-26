package com.set.treeSet;

import java.util.TreeSet;
/*
TreeSet是Set接口的实现类，底层数据结构是二叉树，按照自然升序存储
TreeSet是实现线程不安全的
 */

public class Demo01 {
    public static void main(String[] args) {
        TreeSet<Integer> set = new TreeSet<Integer>();
        set.add(2);
        set.add(3);
        set.add(1);
        set.add(4);
        set.add(3);
        System.out.println(set);
/*
当向TreeSet存入一个元素时，
1. 把待添加的元素T和根节点比较，如果T小于根节点，T存入左子树；
   如果T大于根节点，T存入右子树
2. 一旦确定子树后，T元素要和子树根节点比较，重复1中步骤，如果需要相等，丢弃T

 */
    }
}
