package com.set.treeSet;

import java.util.Comparator;
import java.util.TreeSet;

public class Demo02 {
    public static void main(String[] args) {
        //外部比较器
        //当开发者不知道添加元素类的源代码时，此时可以使用外部比较策略。
        // 外部比较器就是Compartor接口
        LenCompare lenCompare = new LenCompare();
        TreeSet<String> set = new TreeSet<String>(lenCompare);
        set.add("alex");
        set.add("ben");
        set.add("cocos");
        set.add("scott");
        //需求:按照字符串长度升序
        System.out.println(set);
    }


}
class LenCompare implements Comparator<String>{

    @Override
    public int compare(String o1, String o2) {
        //1. 按名称长度升序
//        System.out.println("o1:"+o1);
//        System.out.println("o2:"+o2);
//        return o1.length() - o2.length();

        //2.先按照名称长度，如果相等，按名称自然顺序
//        if(o1.length() == o2.length()){
//            return o1.compareTo(o2);
//        }
//        return o1.compareTo(o2);

        //3.按照长度降序
        return  o2.length() - o1.length();

    }
}