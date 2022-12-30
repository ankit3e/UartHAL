# UartHAL

Assumptions:
1. The device opening/reading/closing operations are omitted from the HAL code, and assumed that the function would be returning an integer on reading.
2. Package names in Java/AIDL, were set with respect to locations of file, here the files are placed all in single place.
3. For UartPortService, an entry needs to be added in SystemServer.java, which is not added here.
