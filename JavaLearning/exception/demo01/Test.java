package com.exception.demo01;

public class Test {
    public static void main(String[] args) {

        try {
            new Test().test(1,0);
        } catch (ArithmeticException e) {
            e.printStackTrace();
        }

//        //假设要捕获多个异常，从小到大
//        try {//try监控区域
//            if(b==0){//主动抛出异常  throw throws
//                throw new ArithmeticException();
//            }
//            System.out.println(a/b);
//            //new Test().a();
//        }catch (Error e){//catch(想要捕获的异常类型) 捕获异常
//            System.out.println("Error");
//        }catch (Exception e){
//            System.out.println("Exception");
//        }catch (Throwable t){//Throwable 范围最大 要写在最后面
//            System.out.println("Throwable");
//        }finally {//处理善后工作
//            System.out.println("finally");
//        }
//        //finally 可以不要finally  假设IO 资源 关闭
    }
    public void a(){
        b();
    }

    public void b(){
        a();
    }
    //假设这方法中，处理不了这个异常，方法上抛出异常 throws
    public void test(int a,int b) throws ArithmeticException{
        if(b==0){//主动抛出异常  throw throws
            throw new ArithmeticException();//主动地抛出异常，一般在方法中使用 throw
        }
        //System.out.println(a/b);
    }
}
