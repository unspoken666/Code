package lesliefang.com.audiorecord;

import android.os.Bundle;
import android.widget.TextView;

import android.support.v7.app.AppCompatActivity;



public class LoginActivity extends AppCompatActivity {

    TextView hint;
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.login);
        hint = findViewById(R.id.hint);

        //finish();
        // 如果登录成功
        if(Boolean.TRUE){
            hint.setText("Login Successful");

        }
        else{
            hint.setText("ID or Voiceprint Error");

        }


    }
}
