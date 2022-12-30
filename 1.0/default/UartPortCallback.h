// FIXME: your file license if you have one

#pragma once

#include <android/hardware/Uart/1.0/IUartPortCallback.h>
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

struct UartPortCallback : public V1_0::IUartPortCallback {
    // Methods from ::android::hardware::Uart::V1_0::IUartPortCallback follow.
    Return<void> onDataUpdate(const ::android::hardware::Uart::V1_0::UartPortEvent& event) override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.

};

// FIXME: most likely delete, this is only for passthrough implementations
// extern "C" IUartPortCallback* HIDL_FETCH_IUartPortCallback(const char* name);

}  // namespace android::hardware::Uart::implementation
