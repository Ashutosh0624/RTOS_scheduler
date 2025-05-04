#pragma once
#include"SensorInterface.h"
#include<string>

// RPM sensor 
struct RPMSensor{
    int rpm = 3000;
};

// define the functions which we have to implement through interface 
std::string read_rpm(void *self){
    RPMSensor *rpms = static_cast<RPMSensor*>(self);
    return "rpm speed : " + std::to_string(rpms->rpm);
}

std::string status_rpm(void *self){
    return "Sensor status : Okay";
}

// Temperature sensor 
struct TempSensor{
    float temp = 36.5;
};

std::string read_temp(void *self){
    TempSensor *tSensor = static_cast<TempSensor*>(self);
    return "Temperature : " + std::to_string(tSensor->temp);
}

std::string status_temp(void *self){
    return "Status of temperature sensor : Okay";
}