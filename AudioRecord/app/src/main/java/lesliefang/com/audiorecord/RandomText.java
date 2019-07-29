package lesliefang.com.audiorecord;

import android.media.AudioFormat;
import android.media.AudioRecord;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class RandomText {

    private String[] strArray = {"两只黄鹂鸣翠柳，一行白鹭上青天。",
                         "抽刀断水水更流，举杯消愁愁更愁。",
                         "近水楼台先得月，向阳花木易为春。",
                         "同是天涯沦落人，相逢何必曾相识。",
                         "梅须逊雪三分白，雪却输梅一段香。",
                         "You can try to say it,'turn on the light'",
                         "You can try to say it,'turn off the TV",
                         "You can try to say it,'start sweeping'",
                         "You can try to say it,'open the door'",
                         "You can try to say it,'washing dishes'"
    };

    private static Integer random(){
        int max = 10,min = 1;
       return (int)(Math.random()*(max-min)+min);
    }

    public String randomText(){
        return strArray[random()];

    }

}
