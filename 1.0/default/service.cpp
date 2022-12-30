#include "UartPort.h"

using android::sp;


using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;
using android::hardware::uart::V1_0::IUart;
using android::hardware::uart::V1_0::implementation::Uart;


int main(int /* argc */, char* /* argv */ []) {
    android::sp<IUart> service = new Uart();

    configureRpcThreadpool(4, true /*callerWillJoin*/);
    status_t status = service->registerAsService();

    if (status == OK) {
        LOGD("SerialPort HAL Ready.");
        service->initUartPort("/dev/uart", 115200);
        service->startRead();
        joinRpcThreadpool();
    }

    LOGD("Failed to register Uart HAL service");
    return 1;
}.h"
