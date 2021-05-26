package com.kuang.array;

import java.util.Arrays;

public class ArrayDemo07 {
    public static void main(String[] args) {

        int[] a = {6,5,4,3,2,1};
        int[] b = bubbleSort(a);
        System.out.println(Arrays.toString(a));
        System.out.println(Arrays.toString(b));
    }

    //冒泡排序
    //1.比较数组中，两个相邻的元素，如果第一个数比第二个数大，我们就交换他们的位置
    //2.每一次比较，都会产生出一个最大或者最小的数字
    //3.下一轮可以少一次排序
    //4.依次循环，直到结束

    public static int[] bubbleSort(int[] arrays){

        int tmp = 0;

        //外层循环，判断我们这个要走多少次
        for (int i = 0; i < arrays.length-1; i++) {

            boolean flag = false;//通过flag标识位减少没有意义的比较

            //内层循环，比较判断两个数，如果第一个数比第二个数大，则交换位置
            for (int j = 0; j < arrays.length-1-i; j++) {
                if(arrays[j]>arrays[j+1]){
                    tmp = arrays[j];
                    arrays[j] = arrays[j+1];
                    arrays[j+1] = tmp;
                    flag = true;
                }
            }
            if(flag==false){
                break;
            }
        }
        return arrays;
    }

}
