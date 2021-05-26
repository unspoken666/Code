package com.kuang.demo01;

import org.apache.commons.io.FileUtils;

import java.io.File;
import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;

//练习Threa ，实现多线程同步下载图片
public class TestThread2 implements Runnable{

    private String url;  //网络图片地址
    private String name;//保存的文件名

    public TestThread2(String url,String name){
        this.url = url;
        this.name = name;
    }

    //下载图片线程的执行体
    @Override
    public void run() {
        WebDownloader webDownloader = new WebDownloader();
        webDownloader.downloader(url,name);
        System.out.println("下载了文件名为："+name);
    }

    public static void main(String[] args){
        TestThread2 t1 = new TestThread2("https://img-blog.csdnimg.cn/img_convert/5cc5668bd760531c47ac28f81f0d5b85.png","1.png");
        TestThread2 t2 = new TestThread2("https://img-blog.csdnimg.cn/img_convert/da44df3f9aa90ac2c75d9624bfd3970b.png","2.png");
        TestThread2 t3 = new TestThread2("https://img-blog.csdnimg.cn/img_convert/aff4502ef2352f00690286ce6b74cd81.png","3.png");

        new Thread(t1).start();
        new Thread(t2).start();
        new Thread(t3).start();
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
