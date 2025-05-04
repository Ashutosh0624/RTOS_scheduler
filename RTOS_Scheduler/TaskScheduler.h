#pragma once
#include<chrono>
#include"SensorInterface.h"

struct SensorTask{
    SensorInterface interface;
    int period_ms;
    std::chrono::steady_clock::time_point last_executed;
};
