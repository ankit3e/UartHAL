package android.os.uartport;


interface IUartPortService {
	int getCurrentSpeed();
	int getOdoDistance();
	int getDriveMode();
	int getBattLevel();
	int getBattTemp();
};

