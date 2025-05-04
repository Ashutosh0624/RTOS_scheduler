#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

#include "SensorType.h"
#include "TaskScheduler.h"
using namespace std::chrono;

int main() {
    RPMSensor rpm;
    TempSensor temp;

    std::vector<SensorTask> tasks = {
        {
            .interface = {read_rpm, status_rpm, &rpm},
            .period_ms = 1000,
            .last_executed = std::chrono::steady_clock::now()
        },
        {
            .interface = {read_temp, status_temp, &temp},
            .period_ms = 1500,
            .last_executed = std::chrono::steady_clock::now()
        }
    };

    std::cout << "[RTOS Scheduler Started...]\n";

    while (true) {
        auto now = std::chrono::steady_clock::now();

        for (auto& task : tasks) {
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - task.last_executed).count();
            if (elapsed >= task.period_ms) {
                std::cout << task.interface.read(task.interface.self) << std::endl;
                std::cout << task.interface.status(task.interface.self) << std::endl;
                std::cout << "----" << std::endl;
                task.last_executed = now;
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
