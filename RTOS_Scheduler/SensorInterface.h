#pragma once 
#include<string>

struct SensorInterface{
    std::string (*read)(void *self);
    std::string (*status)(void *self);
    void *self;
};