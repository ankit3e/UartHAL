package com.android.server;


import android.hardware.uart.V1_0.IUartPort;
import android.hardware.uart.V1_0.IUartPortCallback;
import android.hardware.uart.V1_0.UartPortEvent;

public class UartPortService extends IUartPortService.stub {
	private context mContext;
	private IUartPort mUartHalService;
	private int sp;
	private int dist;
	private int mode;
	private int batt;
	private int temp;
	enum Mode {
    PARKING,
    DRIVE,
    REVERSE
	}
	public UartPortService(Context context) {
		mContext = context;
		mUartHalService = IUartPort.getService();
		synchronized(this) 
		{
			if(mUartHalService != NULL) {
				mUartHalService.setCallback(new IUartPortCallback.Stub() {
					@Override
					public void onDataUpdate(UartPortEvent event) {
						sp =  event.sp;
						dist = event.dist;
						mode = event.mode;
						batt = event.batt;
						temp = event.temp;
						checkForReverse();
					}
					
				});
			}
		}
	}
	
	public static final class Lifecycle extends SystemService {
		private UartPortService mService;
		
		public Lifecycle(Context context) {
			super(context);
			mService = new UartPortService();
		}
		
		public void onStart() {
			publishBinderService(Context.UART_SERVICE,mService);
		}
	}
	public checkForReverse() {
		if(mode == Mode.REVERSE) {
			sendReverseGearEngagedIntent();
		}
	}
	//To broadcast when revers gear state is changed
	public sendReverseGearEngagedIntent() {
		final Intent intent = new Intent(UartPortManager.ACTION_REVERSE_GEAR);
		intent.putExtra("status", true);
		mContext.sendBroadcast(intent);
	}
	
	public int getSpeed() {
		return sp;
	}
	public int getOdoDistance() {
		return dist;
	}
	public int getDriveMode() {
		return mode;
	}
	public int getBattLevel() {
		return batt;
	}
	public int getBattTemp() {
		return temp;
	}
	
}