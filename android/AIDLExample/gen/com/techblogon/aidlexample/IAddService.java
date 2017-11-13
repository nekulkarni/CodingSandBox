/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: /home/nathan/Desktop/temp/AIDLExample/src/com/techblogon/aidlexample/IAddService.aidl
 */
package com.techblogon.aidlexample;
// Declare the communication interface which holds all of our exposed functions.

public interface IAddService extends android.os.IInterface
{
/** Local-side IPC implementation stub class. */
public static abstract class Stub extends android.os.Binder implements com.techblogon.aidlexample.IAddService
{
private static final java.lang.String DESCRIPTOR = "com.techblogon.aidlexample.IAddService";
/** Construct the stub at attach it to the interface. */
public Stub()
{
this.attachInterface(this, DESCRIPTOR);
}
/**
 * Cast an IBinder object into an com.techblogon.aidlexample.IAddService interface,
 * generating a proxy if needed.
 */
public static com.techblogon.aidlexample.IAddService asInterface(android.os.IBinder obj)
{
if ((obj==null)) {
return null;
}
android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
if (((iin!=null)&&(iin instanceof com.techblogon.aidlexample.IAddService))) {
return ((com.techblogon.aidlexample.IAddService)iin);
}
return new com.techblogon.aidlexample.IAddService.Stub.Proxy(obj);
}
@Override public android.os.IBinder asBinder()
{
return this;
}
@Override public boolean onTransact(int code, android.os.Parcel data, android.os.Parcel reply, int flags) throws android.os.RemoteException
{
switch (code)
{
case INTERFACE_TRANSACTION:
{
reply.writeString(DESCRIPTOR);
return true;
}
case TRANSACTION_add:
{
data.enforceInterface(DESCRIPTOR);
int _arg0;
_arg0 = data.readInt();
int _arg1;
_arg1 = data.readInt();
int _result = this.add(_arg0, _arg1);
reply.writeNoException();
reply.writeInt(_result);
return true;
}
case TRANSACTION_setFPS:
{
data.enforceInterface(DESCRIPTOR);
int _arg0;
_arg0 = data.readInt();
this.setFPS(_arg0);
reply.writeNoException();
return true;
}
}
return super.onTransact(code, data, reply, flags);
}
private static class Proxy implements com.techblogon.aidlexample.IAddService
{
private android.os.IBinder mRemote;
Proxy(android.os.IBinder remote)
{
mRemote = remote;
}
@Override public android.os.IBinder asBinder()
{
return mRemote;
}
public java.lang.String getInterfaceDescriptor()
{
return DESCRIPTOR;
}
// WE can pass values ALONG WITH in, out, or inout parameters. 
// Android Java Primitive datatypes (such as int,, string, boolean, etc.) can only be passed in.

@Override public int add(int ValueFirst, int valueSecond) throws android.os.RemoteException
{
android.os.Parcel _data = android.os.Parcel.obtain();
android.os.Parcel _reply = android.os.Parcel.obtain();
int _result;
try {
_data.writeInterfaceToken(DESCRIPTOR);
_data.writeInt(ValueFirst);
_data.writeInt(valueSecond);
mRemote.transact(Stub.TRANSACTION_add, _data, _reply, 0);
_reply.readException();
_result = _reply.readInt();
}
finally {
_reply.recycle();
_data.recycle();
}
return _result;
}
@Override public void setFPS(int fps_in) throws android.os.RemoteException
{
android.os.Parcel _data = android.os.Parcel.obtain();
android.os.Parcel _reply = android.os.Parcel.obtain();
try {
_data.writeInterfaceToken(DESCRIPTOR);
_data.writeInt(fps_in);
mRemote.transact(Stub.TRANSACTION_setFPS, _data, _reply, 0);
_reply.readException();
}
finally {
_reply.recycle();
_data.recycle();
}
}
}
static final int TRANSACTION_add = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
static final int TRANSACTION_setFPS = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
}
// WE can pass values ALONG WITH in, out, or inout parameters. 
// Android Java Primitive datatypes (such as int,, string, boolean, etc.) can only be passed in.

public int add(int ValueFirst, int valueSecond) throws android.os.RemoteException;
public void setFPS(int fps_in) throws android.os.RemoteException;
}
