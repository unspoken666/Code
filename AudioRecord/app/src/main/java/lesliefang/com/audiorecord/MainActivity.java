package lesliefang.com.audiorecord;

import android.os.Bundle;
import android.util.Log;

import android.Manifest;
import android.content.pm.PackageManager;
import android.media.AudioFormat;
import android.media.AudioRecord;
import android.media.AudioTrack;
import android.media.MediaRecorder;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.DataOutputStream;
import java.net.Socket;
import java.net.UnknownHostException;

import android.content.Intent;
import android.content.IntentFilter;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "audio";
    EditText editText;
    Button btnStartRecord;
    Button btnStopRecord;
    TextView tvState;
    TextView hint;
    Button btnRegister;
    Button btnLogIn;

    final int sampleRateInHz = 44100;
    final int channelConfig = AudioFormat.CHANNEL_IN_MONO;
    final int audioFormat = AudioFormat.ENCODING_PCM_16BIT;

    boolean isRecording = false;
    AudioRecord audioRecord;

    File pcmFile; // pcm 保存路径
    String wavFile;

    AudioTrack audioTrack;

    private static final int TCP_SERVER_PORT = 9999;//should be same to the server port
    private Socket client;
    private FileInputStream fis;
    private DataOutputStream dos;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // 请开启所有权限，这里没有处理权限回调
        if (ContextCompat.checkSelfPermission(MainActivity.this, Manifest.permission.RECORD_AUDIO) != PackageManager.PERMISSION_GRANTED) {
            requestPermission();
        }
        if (ContextCompat.checkSelfPermission(MainActivity.this, Manifest.permission.WRITE_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED) {
            requestPermission();
        }

        btnStartRecord = findViewById(R.id.start_record);
        btnStopRecord = findViewById(R.id.stop_record);
        tvState = findViewById(R.id.state);
        hint = findViewById(R.id.hint);
        editText = (EditText) findViewById(R.id.edit_text);
        btnRegister = findViewById(R.id.register);
        btnLogIn = findViewById(R.id.log_in);

        pcmFile = new File(getExternalFilesDir(null), "demo.pcm");
        Log.d(TAG, "pcm file path " + pcmFile);

        //new RandomText();
        hint.setText(new RandomText().randomText());

        btnStartRecord.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int bufferSize = AudioRecord.getMinBufferSize(sampleRateInHz, channelConfig, audioFormat);
                audioRecord = new AudioRecord(MediaRecorder.AudioSource.MIC, sampleRateInHz, channelConfig, audioFormat, bufferSize);
                if (audioRecord.getState() == AudioRecord.STATE_INITIALIZED) {
                    audioRecord.startRecording();
                    isRecording = true;
                    tvState.setText("Recording...");

                    new Thread(new RecordRunnable(bufferSize)).start();

                }
            }
        });

        btnStopRecord.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                isRecording = false;
                audioRecord.stop();
                audioRecord.release();
                tvState.setText("Recording completed");

                // PCM格式转为WAV格式
                if (!pcmFile.exists()) {
                    Toast.makeText(MainActivity.this, "PCM 文件不存在", Toast.LENGTH_LONG).show();
                    return;
                }

                wavFile = getExternalFilesDir(null) + File.separator + "demo.wav";
                Log.d(TAG, "wav file path " + wavFile);
                new PcmToWavUtil(sampleRateInHz, channelConfig, audioFormat).pcmToWav(pcmFile.getAbsolutePath(), wavFile);

                //发送文件
                //new Thread(runnable).start();//创建新的进程，申请网络资源

            }
        });



        btnLogIn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //登录监听事件，获取输入的id

                //new Thread(runnable).start();//创建新的进程，申请网络资源

                // 直接跳转到LoginActivity
                Intent intent = new Intent(MainActivity.this,LoginActivity.class);
                startActivity(intent);
                //发送文件
                new Thread(runnable).start();//创建新的进程，申请网络资源

            }
        });

        btnRegister.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //注册监听事件

                //直接跳转到 RegisterActivity
                Intent intent = new Intent(MainActivity.this,RegisterActivity.class);
                startActivity(intent);
            }
        });

    }
    //TCP socket
    Runnable runnable = new Runnable() {
        @Override
        public void run() {
            runTcpClient();
        }
    };

    private void runTcpClient() {
        try {
            Socket s = new Socket("10.0.2.2", TCP_SERVER_PORT);//注意host改成你服务器的hostname或IP地址
            BufferedReader in = new BufferedReader(new InputStreamReader(s.getInputStream()));
            BufferedWriter out = new BufferedWriter(new OutputStreamWriter(s.getOutputStream()));

            //send ID
            String ID = editText.getText().toString();
            out.write(ID);//发送数据
            out.flush();
            Log.i("TcpClient", "sent: " + ID);

            //发送 WAV 文件
            //Log.d("NUM", "Here is a 8");
            File file = new File(wavFile);
            //Log.d("NUM", "Here is a 9");
            if (file.exists()) {
                //Log.d("NUM", "Here is a 7");
                FileInputStream fileInputStream = new FileInputStream(file);
                //Log.d("NUM", "Here is a 6");
                DataOutputStream dataOutputStream = new DataOutputStream(s.getOutputStream());
                //Log.d("NUM", "Here is a 5");
                byte[] bytes = new byte[1024];
                int length = 0;
                long progress = 0;
                while((length = fileInputStream.read(bytes,0,bytes.length)) != -1)
                {
                    dataOutputStream.write(bytes,0,bytes.length);
                    dataOutputStream.flush();
                    progress += length;
                    //Log.d("NUM", "Here is a 4");
                }
            }
//            fis = new FileInputStream(file);
//            dos = new DataOutputStream(client.getOutputStream());
//
//            // 文件名和长度
//            dos.writeUTF(file.getName());
//            dos.flush();
//            dos.writeLong(file.length());
//            dos.flush();
//
//            // 开始传输文件
//            byte[] bytes = new byte[1024];
//            int length = 0;
//            long progress = 0;
//            while((length = fis.read(bytes, 0, bytes.length)) != -1) {
//                dos.write(bytes, 0, length);
//                dos.flush();
//                progress += length;
//            }
//
//            //accept server response
//            String inMsg = in.readLine() + System.getProperty("line.separator");//得到服务器返回的数据
//            Log.i("TcpClient", "received: " + inMsg);
            //close connection
            s.close();
        } catch (UnknownHostException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class RecordRunnable implements Runnable {
        int bufferSize;

        RecordRunnable(int bufferSize) {
            this.bufferSize = bufferSize;
        }

        @Override
        public void run() {
            byte[] data = new byte[bufferSize];
            FileOutputStream out = null;
            try {
                out = new FileOutputStream(pcmFile);
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }

            if (out == null) {
                return;
            }

            try {
                while (isRecording) {
                    int len = audioRecord.read(data, 0, bufferSize);
                    out.write(data, 0, len);
                }
            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                try {
                    out.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    private byte[] file2Bytes() {
        FileInputStream in = null;
        ByteArrayOutputStream out = null;
        byte[] data = null;
        try {
            in = new FileInputStream(pcmFile);
            out = new ByteArrayOutputStream();
            int len;
            byte[] buffer = new byte[1024];
            while ((len = in.read(buffer)) != -1) {
                out.write(buffer, 0, len);
            }

            data = out.toByteArray();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (in != null) {
                    in.close();
                }
                if (out != null) {
                    out.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        return data;
    }

    @Override
    protected void onPause() {
        super.onPause();
        releaseAudioTrack();
    }

    private void releaseAudioTrack() {
        if (audioTrack != null) {
            audioTrack.stop();
            audioTrack.release();
            audioTrack = null;
        }
    }

    private void requestPermission() {
        ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.RECORD_AUDIO, Manifest.permission.WRITE_EXTERNAL_STORAGE}, 100);
    }
}
