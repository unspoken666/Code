package com.kuang.demo02;

//线程创建方式三 ，实现callable方法
/*
callable的好处
1. 可以定义返回值
2. 可以抛出异常
 */

import com.kuang.demo01.TestThread2;
import org.apache.commons.io.FileUtils;

import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.util.concurrent.*;

public class TestCallable implements Callable<Boolean> {
    private String url;  //网络图片地址
    private String name;//保存的文件名

    public TestCallable(String url,String name){
        this.url = url;
        this.name = name;
    }

    //下载图片线程的执行体
    @Override
    public Boolean call() {
       WebDownloader webDownloader = new WebDownloader();
        webDownloader.downloader(url,name);
        System.out.println("下载了文件名为："+name);
        return true;
    }

    public static void main(String[] args) throws ExecutionException, InterruptedException {
        TestCallable t1 = new TestCallable("https://img-blog.csdnimg.cn/img_convert/5cc5668bd760531c47ac28f81f0d5b85.png","1.png");
        TestCallable t2 = new TestCallable("https://img-blog.csdnimg.cn/img_convert/da44df3f9aa90ac2c75d9624bfd3970b.png","2.png");
        TestCallable t3 = new TestCallable("https://img-blog.csdnimg.cn/img_convert/aff4502ef2352f00690286ce6b74cd81.png","3.png");

        //创建执行服务：
        ExecutorService ser = Executors.newFixedThreadPool(3);

        //提交执行
        Future<Boolean> r1 = ser.submit(t1);
        Future<Boolean> r2 = ser.submit(t2);
        Future<Boolean> r3 = ser.submit(t3);

        //获取结果
        boolean rs1 = r1.get();
        boolean rs2 = r2.get();
        boolean rs3 = r3.get();

        //关闭服务
        ser.shutdown();
    }

}

//下载器
class WebDownloader{
    //下载方法
    public void downloader(String url,String name) {
        try {
            FileUtils.copyURLToFile(new URL(url),new File(name));
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("IO异常，downloader方法出现问题");
        }
    }
}

