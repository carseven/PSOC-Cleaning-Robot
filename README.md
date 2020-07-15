# PSOC-Cleaning-Robot
The functionality carried out by the PSoC 4 based robot will be that of a sweeper/vacuum cleaner automatic. The robot move forward at a slow speed until it detects
an obstacle less than 6 inches away. When this detection occurs, the robot will carry out the backward-turning to avoid it. This maneuver will consist of the robot emitting a short beep, back up a few inches and make a left turn of approximately 90 degrees at a slow speed and will return to its initial behavior of advancing unlimitedly to a
slow speed. Similarly, when the robot detects that it is approaching a step, it must be able to detect it and perform the reverse-rotation maneuver described above.
The robot have an RGB LED that will indicate the direction of movement by assigning a color different from each of these.
![alt text](https://github.com/carseven/PSOC-Cleaning-Robot/blob/master/Hardware/RobotResult.gif)
## Hardware implementation:
![alt text](https://github.com/carseven/PSOC-Cleaning-Robot/blob/master/Hardware/robot.PNG)
### 1. Motor
  ![alt text](https://github.com/carseven/PSOC-Cleaning-Robot/blob/master/Hardware/motorDiagram.PNG)
## 2. IR Sensor
  ![alt text](https://github.com/carseven/PSOC-Cleaning-Robot/blob/master/Hardware/IR_TCRT5000.PNG)
## 3. Ultrasound Sensor
  ![alt text](https://github.com/carseven/PSOC-Cleaning-Robot/blob/master/Hardware/ultrasound_HC-SR04.PNG)
## 4. Leds
  ![alt text](https://github.com/carseven/PSOC-Cleaning-Robot/blob/master/Hardware/leds.PNG)
## 5. Buzzers
  ![alt text](https://github.com/carseven/PSOC-Cleaning-Robot/blob/master/Hardware/buzzers.PNG)
