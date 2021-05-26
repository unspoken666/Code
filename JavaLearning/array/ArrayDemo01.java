package com.kuang.array;

public class ArrayDemo01 {
    public static void main(String[] args) {
        //变量类型 变量名 = 变量值

        int[] nums;//1.定义
        int[] nums2 = new int[10];
        int Num = 10;
        nums = new int[Num];//2. 创建一个数组
        //3. 给数组元素赋值
        for (int i = 0; i < nums.length; i++) {
            nums[i] = i+1;
        }
        System.out.println(nums[9]);//若不赋值 则默认是零

        //计算所有元素的和
        int sum = 0;
        //获取数组长度 arrays.length

        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
        }
        System.out.println("总和为：" + sum);
    }
}
