// FIXME: your file license if you have one

#include "UartPort.h"

namespace android::hardware::Uart::implementation {


pthread_t mDataReadThread;
list<Callback> mList;
// Methods from ::android::hardware::Uart::V1_0::IUartPort follow.
Return<void> UartPort::initUartPort(const hidl_string& address, int32_t baudrate) {
    // TODO implement
	//Here all the initialization of Uart Port will be performed by opening the device node
    return Void();
}
int32_t readUART() {
	//this function implements the logic of reading data from the fd of device node,
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
		while(receiveLength !=5 ) {
			dataReceived.push_back(readUART());
			receiveLength++;
		}
		
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
