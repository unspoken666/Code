package com.kuang.array;

public class ArrayDemo02 {
    public static void main(String[] args) {
        //静态初始化：创建+赋值
        int[] a = {1,2,3,4,5,6,7,8};
        Man[] mans = {new Man(),new Man()};
        System.out.println(a[0]);

        //动态初始化 ：包含默认初始化
        int[] b = new int[10];
        b[0] = 10;

        System.out.println(b[0]);
        System.out.println(b[1]);

        for (int i = 0; i < a.length; i++) {
            System.out.println(a[i]);
        }

    }
}
