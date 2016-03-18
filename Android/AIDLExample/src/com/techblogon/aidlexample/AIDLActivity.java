package com.techblogon.aidlexample;

import com.techblogon.aidlexample.IAddService;
import com.techblogon.aidlexample.R;

import android.os.Bundle;
import android.os.IBinder;
import android.os.RemoteException;
import android.app.Activity;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.util.Log;
import android.view.Menu;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.Button;
import android.view.View.OnClickListener;

public class AIDLActivity extends Activity {

	  private static final String TAG = "AIDLExample";

	  IAddService service; // the actual service interface. Service funcs are in here.

	  AddServiceConnection connection; 

	  /**
	   * This is the class which represents the actual service-connection.
	   * It type casts the bound-stub implementation of the service class to our AIDL interface.
	   */
	  
	  class AddServiceConnection implements ServiceConnection
	  {

	  	// this event callback function gets called when we connect
	  	// to the bound service.

	    public void onServiceConnected(ComponentName name, IBinder boundService)
	    {
	      service = IAddService.Stub.asInterface((IBinder) boundService);
	      Log.i(TAG, "onServiceConnected(): Connected");
	      Toast.makeText(AIDLActivity.this, "AIDLExample Service connected", Toast.LENGTH_LONG).show();

	      // Test the service
		  
		  int n1 =10, n2 =15, res = -1;
		  try
		  {
		   res = service.add(n1, n2);
		   service.setFPS(n1);
		  } 
		  catch (RemoteException e) {
		   Log.i(TAG, "Data fetch failed with: " + e);
		   e.printStackTrace();
		  }
		   Log.d(TAG, "Final result: " + res);

	    }

	    public void onServiceDisconnected(ComponentName name) {
	      service = null;
	      Log.i(TAG, "onServiceDisconnected(): Disconnected");
	      Toast.makeText(AIDLActivity.this, "AIDLExample Service Connected", Toast.LENGTH_LONG).show();
	    }
	  }
	  
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_aidl);
		initServiceConnection();
	}
	
	  // This is our function which binds our activity(MainActivity)
	  // to our service(AddService).

	  private void initServiceConnection()
	  {
		Log.i(TAG, "initServiceConnection()" );
		connection = new AddServiceConnection();
	    Intent i = new Intent();
	    i.setClassName("com.techblogon.aidlexample", com.techblogon.aidlexample.AddService.class.getName());
	    
	    boolean ret = bindService(i, connection, Context.BIND_AUTO_CREATE);
	    
	    Log.i(TAG, "initServiceConnection() bound value: " + ret);
	  }

	  /** This is our function to un-binds this activity from our service. */
	  private void releaseService()
	  {
	    unbindService(connection);
	    connection = null;
	    Log.d(TAG, "releaseService(): unbound.");
	  }
	
	@Override
	protected void onDestroy()
	{
		super.onDestroy();
		releaseService();
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
}