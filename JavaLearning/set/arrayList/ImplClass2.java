package com.set.arrayList;

//实现类不知道接口中方法的参数类型，实现类继续泛下去
public class ImplClass2<T> implements MyInterface<T>{

    @Override
    public void showInfo(T a) {

    }
}
