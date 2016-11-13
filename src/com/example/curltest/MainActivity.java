package com.example.curltest;

import org.json.JSONObject;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.telephony.SmsManager;

public class MainActivity extends Activity {
	static {
		System.loadLibrary("curl");
		System.loadLibrary("curlTest");
		System.loadLibrary("NDK_01");
	}

	public native void Init();

	public native void Cleanup();

	public native void TestDownload();

	public native void TestHttpPost();

	public native void SendSMS(Context con, Bundle savedInstanceState);

	public native String getStringFromJNI();

	public native String tranformJson(String jsonString);

	private final String TAG = "gm_ndk_network";

	private void postDispose(String Data) {
		Log.i(TAG, Data);
	}

	@Override
	protected void onCreate(final Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		Init();
		Button btnPost = (Button) findViewById(R.id.main_post);
		Button btnDownload = (Button) findViewById(R.id.main_download);
		Button btnSendSMS = (Button) this.findViewById(R.id.main_sendSMS);

		btnPost.setOnClickListener(new OnClickListener() {

			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				TestHttpPost();
			}
		});
		btnDownload.setOnClickListener(new OnClickListener() {

			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				TestDownload();
			}
		});
		btnSendSMS.setOnClickListener(new OnClickListener() {

			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				// SendSMS(getApplicationContext(), savedInstanceState);

				// String print = getStringFromJNI();
				JSONObject jsonObject = getJsonObject();
				tranformJson(jsonObject.toString());

			}
		});

	}

	private JSONObject getJsonObject() {
		JSONObject jsonObject = new JSONObject();
		try {
			jsonObject.put("name", "张三");
			jsonObject.put("gender", "男");

		} catch (Exception e) {
				e.printStackTrace();
		}
		return jsonObject;
	}

	@Override
	protected void onDestroy() {
		// TODO Auto-generated method stub
		super.onDestroy();
		Cleanup();
	}
}
