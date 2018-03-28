#ifndef SDCARD_H
#define SDCARD_H

#include <FS.h>
#include <Arduino.h>

#include "imu.h"
#include "gps.h"

union timestampSendable_t {
    time_t data;
    uint8_t bytes[sizeof(time_t)];
};

union imuDataSendable_t {
    imuData_t data;
    uint8_t bytes[sizeof(imuData_t)];
};

union gpsDataSendable_t {
    gpsData_t data;
    uint8_t bytes[sizeof(gpsData_t)];
};

class SDCard
{
public:
    SDCard();
    virtual ~SDCard();

    void begin();

    void listDir(fs::FS &fs, const char * dirname, uint8_t levels);

    void toESP32();
    void toExternal();

    void setIMUQueue(QueueHandle_t queue);
    void setGPSQueue(QueueHandle_t queue);

    void startLog();
    void stopLog();

private:
    void startTimestamp();
    void stopTimestamp();
};

#endif
