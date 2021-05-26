package com.set.arrayList;

//当泛型接口中的方法类型(返回值、形参）不太确定，可以使用泛型接口
public interface MyInterface<T> {
    public void showInfo(T a);
}
