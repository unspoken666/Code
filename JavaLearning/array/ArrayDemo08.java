package com.kuang.array;

import java.util.Arrays;

public class ArrayDemo08 {
    public static void main(String[] args) {
        //创建一个二维数组  11*11  0:没有棋子  1:黑棋  0:没有棋子
        int[][] array1 = new int[11][11];
        array1[1][2] = 1;
        array1[2][3] = 2;
        //输入原始的数组
        System.out.println("输出原始的数组");
        for (int[] ints : array1) {
            for (int anInt : ints) {
                System.out.print(anInt+"\t");
            }
            System.out.println();
        }

        System.out.println("====================");

        //转换为稀疏数组保存
        //获取有效值的个数
        int sum = 0;
        for (int i = 0; i < array1.length; i++) {
            for (int j = 0; j < array1[i].length; j++) {
                if(array1[i][j] != 0){
                    sum++;
                }
            }
        }
        System.out.println("有效值的个数"+sum);

        //2.创建一个稀疏数组的数组
        int[][] array2 = new int[sum+1][3];

        array2[0][0] = array1.length;
        array2[0][1] = array1[0].length;
        array2[0][2] = sum;

        //遍历二维数组，将非零的值，存放稀疏数组中
        int count = 0;
        for (int i = 0; i < array1.length; i++) {
            for (int j = 0; j < array1[i].length; j++) {
                if(array1[i][j] != 0){
                    count++;
                    array2[count][0] = i;
                    array2[count][1] = j;
                    array2[count][2] = array1[i][j];

                }
            }
        }
        System.out.println(Arrays.deepToString(array2));

        System.out.println("=====================");
        System.out.println("还原");
        //1.读取稀疏数组
        int[][] arrays3 = new int[array2[0][0]][array2[0][1]];
        for (int i = 1; i < array2.length; i++) {

            arrays3[array2[i][0]][array2[i][1]] = array2[i][2];

        }
        System.out.println(Arrays.deepToString(arrays3));

    }
}