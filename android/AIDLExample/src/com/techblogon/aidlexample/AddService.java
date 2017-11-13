package com.techblogon.aidlexample;

import com.techblogon.aidlexample.IAddService;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.os.RemoteException;
import android.util.Log;

/**
 * This AddService class exposes the remote service
 * (functions in AIDL file, which we need to expose
 * to other apps) to the client.
 */
public class AddService extends Service {
  private static final String TAG = "AddService";
  
  @Override
  public void onCreate() {
    super.onCreate();
    Log.i(TAG, "onCreate()");
  }

  // A bound service is an implementation of the Service
  // class that allows other applications to bind to it 
  // and interact with it. To provide binding for a service,
  // you must implement the onBind() callback method. This 
  // method returns an IBinder object that defines the 
  // programming interface that clients can use to interact
  // with the service.
  
  // When you implement your bound service, the most important
  // part is defining the interface that your onBind() callback
  // method returns.

  @Override
  public IBinder onBind(Intent intent) {

    return new IAddService.Stub() {
      /**
       * In the AIDL file we just add the declaration of the function
       * here is the real implementation of the add() function below
       */
      public int add(int ValueFirst, int valueSecond) throws RemoteException {
        Log.i(TAG, String.format("AddService.add(%d, %d)",ValueFirst, valueSecond));
        return (ValueFirst + valueSecond);
      }

      public void setFPS(int fps_in) throws RemoteException {
        Log.i(TAG, String.format("AddService.setFPS(%d)",fps_in));
      }


    };
  }

  @Override
  public void onDestroy() {
    super.onDestroy();
    Log.d(TAG, "onDestroy()");
  }
}
