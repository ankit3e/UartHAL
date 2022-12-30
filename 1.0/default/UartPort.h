// FIXME: your file license if you have one

#pragma once

#include <android/hardware/Uart/1.0/IUartPort.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

namespace android::hardware::Uart::implementation {

using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;

struct UartPort : public V1_0::IUartPort {
    // Methods from ::android::hardware::Uart::V1_0::IUartPort follow.
    Return<void> initUartPort(const hidl_string& address, int32_t baudrate) override;
    Return<void> startRead() override;
    Return<void> stopRead() override;
    Return<void> closeUartPort() override;
    Return<void> setCallBack(int32_t type, const sp<::android::hardware::Uart::V1_0::IUartPortCallback>& callback) override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.

};

// FIXME: most likely delete, this is only for passthrough implementations
// extern "C" IUartPort* HIDL_FETCH_IUartPort(const char* name);

}  // namespace android::hardware::Uart::implementation
