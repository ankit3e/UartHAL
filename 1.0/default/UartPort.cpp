// FIXME: your file license if you have one

#include "UartPort.h"
#include "termios.h"

namespace android::hardware::Uart::implementation {


pthread_t mDataReadThread;
list<Callback> mList;
// Methods from ::android::hardware::Uart::V1_0::IUartPort follow.
Return<void> UartPort::initUartPort(const hidl_string& address, int32_t baudrate) {
    // TODO implement
	//Here all the initialization of Uart Port will be performed by opening the device node
	int fd = open("/dev/ttyS1",O_RDONLY);
	if(fd == -1) {
		cout<<"Error:\n";
		return Void();
	}
	struct termios SerialPortSettings;
	tcgetattr(fd, SerialPortSettings);
	cfsetispeed(&SerialPortSettings, /*baudrate her*/);
	/*Set flags here to control data bits, stop bits, parity bits
	SerialPortSettings.c_cflag |= CS8;
	*/
	if((tcsetattr(fd, TCSANOW, &SerialPortSettings)) != 0) {
		cout<<"\n Error setting the attributes\n";
	}
	else {
		cout<<"Setting attribute completed\n";
	}
	tcflush(fd, TCIFLUSH);
	close(fd);
    return Void();
}
vector<int_32> getArrayFromChar(char *dataread,int level) {
    char *cp = strtok(dataread, ", ");
	vector<int_32> output;
	int converted = 0 ;
	char* tok = dataread ;
	int i = 0 ;
	int temp = 0;
	do
	{
		converted = sscanf( tok, "%d", &temp) ;
		output.push_back(temp);
		tok = strchr( tok, ',' ) + 1 ;
		i++ ;

	} while( tok != NULL && converted != 0 ) ;

	return output;
}
vector<int_32> readUART() {
	//this function implements the logic of reading data from the fd of device node,

	//Assumption made: the data which is being sent by the
	int fd = open("/dev/ttyS1",O_RDONLY);

	if (fd == -1) {
		cout<<"\n failed opening the serial device";
		return -1;
	}
	else {
		cout<<"\n Opened serial device successfully";
	}

	char readBuf;
	char sData[32]; //stores comma separated data
	int bytesRead =0;
	int count = 255;
	while(count--){
		bytesRead = read(fd, &readBuf, 1);
		if(bytesRead>0) {
			if(readBuf == "$") {
				bytesRead = read(fd, &sData, 32);
				close(fd);
				return atoi(readBuf);
			}
		}
	}
	//Not data being sent
	return -1; 

}

void parseData(vector<int32_t> dataReceived) {
	if(dataReceived.size() >0) {
		UartPortEvent event;
		event.sp = dataReceived[0];
		event.dist = dataReceived[1];
		event.mode = dataReceived[2];
		event.batt = dataReceived[3];
		event.temp = dataReceived[4];
		for(auto itr:list) { 
			if((*itr)!= nullptr) {
				(*itr)->onDataUpdate(event);
			}
		}
	}
}
void *runDataRead() {
	vector<int_32> dataReceived;
	int receiveLength;
	while(1) {
		dataReceived.clear();
		receiveLength = 0;
		dataReceived = readUART();
		parseData(dataReceived);
		usleep(1000);
	}
}
Return<void> UartPort::startRead() {
    // TODO implement
	pthread_create(&mDataReadThread, nullptr, runDataRead, &read);
    return Void();
}

Return<void> UartPort::stopRead() {
    // TODO implement
    return Void();
}

Return<void> UartPort::closeUartPort() {
    // TODO implement
	//to close the fd for the device node.
    return Void();
}

Return<void> UartPort::setCallBack(int32_t type, const sp<::android::hardware::Uart::V1_0::IUartPortCallback>& callback) {
    // TODO implement
	mList.push_back(callback)
    return Void();
}


// Methods from ::android::hidl::base::V1_0::IBase follow.

//IUartPort* HIDL_FETCH_IUartPort(const char* /* name */) {
    //return new UartPort();
//}
//
}  // namespace android::hardware::Uart::implementation
