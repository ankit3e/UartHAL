// FIXME: your file license if you have one

#include "UartPortCallback.h"

namespace android::hardware::Uart::implementation {

// Methods from ::android::hardware::Uart::V1_0::IUartPortCallback follow.
Return<void> UartPortCallback::onDataUpdate(const ::android::hardware::Uart::V1_0::UartPortEvent& event) {
    // TODO implement
    return Void();
}


// Methods from ::android::hidl::base::V1_0::IBase follow.

//IUartPortCallback* HIDL_FETCH_IUartPortCallback(const char* /* name */) {
    //return new UartPortCallback();
//}
//
}  // namespace android::hardware::Uart::implementation
