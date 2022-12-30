public class UartPortManager {
	private IUartPortService mService;
	
	//Apps that may require to take any action such as turning on camera, can add this intent to the intent filter and will be notified as soon as reverse gear is engaged.
	public static final string ACTION_REVERSE_GEAR = "android.auto.REVERSE_GEAR";
	private UartPortManager() {
	}
	
	static IUartPortService getService() {
		if (mService != NULL)
			return mService;
		
		IBinder b = ServiceManager.getService(Context.UART_PORT_SERVICE);
		mService = IUartPortService.Stub.asInterface(b);
		return mService;
	}
	
	public int getSpeed() {
		final IUartPortService service = getService();
		try{
			return service.getCurrentSpeed();
		}
		catch(RemoteException e) {
			
		}
	}
	
	public int getOdoDistance() {
		final IUartPortService service = getService();
		try{
			return service.getOdoDistance();
		}
		catch(RemoteException e) {
			
		}
	}
	
	public int getDriveMode() {
		final IUartPortService service = getService();
		try{
			return service.getDriveMode();
		}
		catch(RemoteException e) {
			
		}
	}
	
	public int getBattLevel() {
		final IUartPortService service = getService();
		try{
			return service.getBattLevel();
		}
		catch(RemoteException e) {
			
		}
	}
	
	public int getBattTemp() {
		final IUartPortService service = getService();
		try{
			return service.getBattTemp();
		}
		catch(RemoteException e) {
			
		}
	}
}