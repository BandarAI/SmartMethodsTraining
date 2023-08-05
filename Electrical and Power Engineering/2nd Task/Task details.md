# Task Brief
The task goal is to design and code a servo motor and DC motor

# Task Execution Details

## Servo Motor Arduino Design
Desingin the servo motor sing Arduino is simple. Connect the ground to the ground, the power to 5V and the singal pin to any pin on the Arduino. As shown below

![Servo Motor Arduino Design](https://github.com/BandarAI/SmartMethodsTraining/blob/Tasks/Electrical%20and%20Power%20Engineering/2nd%20Task/Servo%20motor%20design.png "Servo Motor Arduino Design")

## Servo Motor Code Implementation
To keep the servo motor moving constantly, all the code will be within the loop block. The initial position of the servo is 0, and it starts rotating from 0 to 180 degree by increasing 1 degree until it reaches 180. Then, it will start decreasing by 1 from 180 to 0 degrees.

![Servo Motor Full Code](https://github.com/BandarAI/SmartMethodsTraining/blob/Tasks/Electrical%20and%20Power%20Engineering/2nd%20Task/Servo%20motor%20code.ino "Servo Servo Motor Full Code")

```
  // theta = 180
  for (pos = 0; pos <= theta; pos += 1) 
  {
    servo_9.write(pos);
    delay(15); 
  }
  for (pos = theta; pos >= 0; pos -= 1)
  {
    servo_9.write(pos);
    delay(15); 
  }
```
## DC Motor Arduino Design
DC motors require a high amount of current, and linking the DC motor directly to the Arduino pins may cause damage to the Arduino circuit. To prevent this, I used a transistor to control the current from the Arduino pins to the DC motor

![DC Motor Arduino Design](https://github.com/BandarAI/SmartMethodsTraining/blob/Tasks/Electrical%20and%20Power%20Engineering/2nd%20Task/DC%20motor%20design.png "DC Motor Arduino Design")

## DC Motor Arduino Code Implementation
For the code implementation, it doesn't require coding but defining the pinMode to control the DC motor

![DC Motor Full Code](https://github.com/BandarAI/SmartMethodsTraining/blob/Tasks/Electrical%20and%20Power%20Engineering/2nd%20Task/DC%20motor%20code.ino "Servo DC Motor Full Code")
