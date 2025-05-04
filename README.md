![image](https://github.com/user-attachments/assets/4f87d6e6-2281-4f22-8c8c-38b5ed0bc6d2)# 🕹️ RTOS-Style Sensor Task Scheduler (Embedded Simulation Project)

This project simulates a lightweight **RTOS-style sensor task scheduler** using **C++**. It mimics how embedded real-time systems (like automotive ECUs or avionics flight computers) manage sensor polling and modular task execution — without using a full-fledged RTOS like FreeRTOS.

---

## 🧠 Core Concepts Demonstrated

- ✅ **Function Pointer Interfaces** (like virtual functions in OOP, but lower level)
- ✅ **Generic `void*` based interfaces** for sensor abstraction
- ✅ **Task Control Block (TCB) simulation**
- ✅ **Time-triggered task scheduling using `std::chrono`**
- ✅ **Scalable task list using `std::vector`**
- ✅ Designed in the spirit of **RTOS / ARINC-653 scheduling**

---

## 📦 Folder Structure

RTOS_Scheduler_Project/
│

├── SensorType.h # RPM & Temperature Sensor structs + functions

├── TaskScheduler.h # SensorTask definition (interface + timing)

├── main.cpp # Scheduler logic (loop, task invocation)

├── README.md # Project documentation



---

## ⚙️ How It Works

- Each sensor implements:
  - `read(void* self)` – returns sensor reading as string
  - `status(void* self)` – returns health status
- These functions are connected using a **function pointer-based interface**
- A **`SensorTask`** holds:
  - Function pointers
  - Period of execution
  - Last executed timestamp
- A loop runs infinitely:
  - Every 100ms, it checks all tasks
  - If their period has elapsed, it triggers `read()` and `status()` functions

---

## 🔁 Sample Console Output

[RTOS Scheduler Started...]
RPM: 3000
RPM Sensor Status: OK
Temperature: 36.5 C
Temp Sensor Status: OK


![image](https://github.com/user-attachments/assets/3e93ce9d-28c5-4f66-846f-0a6f5bac8297)



---

## 🚀 Features & Extensibility

| Feature              | Description |
|----------------------|-------------|
| 🎯 Modular Design     | Add new sensors easily by writing 2 functions and plugging into the task list |
| ⏱️ Real-Time Simulation | Uses `chrono` to simulate RTOS-like periodic task scheduling |
| 🧪 Fault Injection Ready | Extend `status()` to simulate sensor failures |
| 📓 Logging (Pluggable)  | Can integrate Singleton Logger pattern for structured logging |
| 🔌 Future Extension     | Add CAN/AFDX interface layer as communication task |
| ⚡ Optional Threading   | Extend using `std::thread` to simulate parallel RTOS tasks |

---

## 👨‍💻 Skills & Concepts Practiced

- `struct`-based system design
- Function pointers and callback handling
- `void*` abstraction with `static_cast`
- Time difference calculation (`std::chrono`)
- Infinite loop control with scheduling logic
- Scalable sensor/task list using `std::vector`
- Clean separation of logic, interface, and data

---

## 📚 Ideal For:

- 🔧 Embedded system engineers practicing real-time task scheduling
- 🧠 Students preparing for RTOS interviews (Qualcomm, Airbus, Bosch, etc.)
- 🧪 C++ learners exploring low-level function pointers and hardware-like abstraction
- 🛫 Avionics/automotive control system designers simulating scheduler behavior

---

## 📌 Next Steps

- [ ] Add `PressureSensor` with different polling period
- [ ] Integrate a `Logger` singleton class
- [ ] Simulate fault status in `status()` function
- [ ] Implement `CommInterface` (CAN/AFDX) to send sensor data

---

## 🛠️ Requirements

- C++11 or later
- Linux, Windows, or WSL terminal
- g++ or clang++ (for compilation)

---

## 🧪 Compile & Run

```bash
g++ main.cpp -o rtos_scheduler -std=c++11
./rtos_scheduler

