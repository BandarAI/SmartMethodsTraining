# Task Brief
The task goal is to connect two arduino together.

# Task Execution Details
For this task, I connected two arduino devices to make a push button LED work.
One Arduino has a push button, and the other has LED light. When the button is pressed, it sends a signal to the second arduino, making the LED light up.

![](https://github.com/BandarAI/SmartMethodsTraining/blob/Tasks/IoT/2nd%20Task/IoT%20Task%202.png "")

# Task Implementation
To implement this task, I used #include <Wire.h> library. It uses I2C protocol to let the arduino communicate with other devices.

![Push Button Arduino Implementation](https://github.com/BandarAI/SmartMethodsTraining/blob/Tasks/IoT/2nd%20Task/iot_task_21.ino "Push Button Arduino Implementation")

![LED light Arduino Implementation](https://github.com/BandarAI/SmartMethodsTraining/blob/Tasks/IoT/2nd%20Task/iot_task_22.ino "LED light Arduino Implementation")




