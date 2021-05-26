package com.kuang.array;

public class ArrayDemo05 {
    public static void main(String[] args) {
        int[][] arrays = {{1,2},{2,3},{3,4},{4,5}};
        printArray(arrays[0]);
        System.out.println(arrays[0][0]);
        for (int i = 0; i < arrays.length; i++) {
            for (int j = 0; j < arrays[i].length; j++) {
                System.out.print(arrays[i][j]+" ");
            }
        }

    }

    //打印数组元素
    public static void printArray(int[] arrays){
        for (int i = 0; i < arrays.length; i++) {
            System.out.print(arrays[i]+" ");
        }
        System.out.println();
    }
}
