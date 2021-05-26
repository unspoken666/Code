package com.kuang.array;

import java.lang.reflect.Array;
import java.util.Arrays;

public class ArrayDemo06 {
    public static void main(String[] args) {
        int[] a = {1,2,3,4,9090,31231,543,21,3,23};

        //System.out.println(a);//[I@10f87f48
        //打印数组元素
        //System.out.println(Arrays.toString(a));
        //printArray(a);

        Arrays.sort(a);//数组进行排序  升序
        System.out.println(Arrays.toString(a));

        Arrays.fill(a,2,4,0);
        System.out.println(Arrays.toString(a));

    }

    public static void printArray(int[] a){
        System.out.print("[");
        for (int i = 0; i < a.length; i++) {
            if(i==a.length-1){
                System.out.print(a[i]+"]");
            }else{
                System.out.print(a[i]+", ");
            }
        }
    }
}
