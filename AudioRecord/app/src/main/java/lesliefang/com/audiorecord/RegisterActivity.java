package lesliefang.com.audiorecord;

import android.os.Bundle;
import android.widget.TextView;
import android.support.v7.app.AppCompatActivity;

public class RegisterActivity extends AppCompatActivity {

    TextView hint;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.register);

        hint = findViewById(R.id.hint);

        //finish();
        // 如果注册成功
        if(Boolean.TRUE){
            hint.setText("Register successfully,please return to log in again");

        }
        else{
            hint.setText("Error,please register again");

        }

    }
}
