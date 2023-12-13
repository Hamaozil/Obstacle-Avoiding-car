# Obstacle-Avoiding-car
simple obstacle avoiding car using an Arduino , Ultrasonic and Servo motor.

# What is Obstacle Avoiding ?
It is a car or robot equipped with sensors to detect and avoid obstacles, like the "Ultrasonic" sensor I utilized. The Ultrasonic sensor detects the distance between the car and the obstacle using ultrasound waves. If the car is within about 10cm of the obstacle, it will begin to search for an alternative path by looking right and left.

## Hardware used :
1. Arduino nano
2. Motor driver `l298n`
3. Small breadboard
4. Ultrasoinc
5. Servo motor
6. Yellow DC motors
7. 4*Li Batteries
8. jumpers
9. switch
10. Booster

# Hardware Connections
![obstacle avoiding_bb](https://github.com/Hamaozil/Obstacle-Avoiding-car/assets/115914652/07743750-0b1b-449e-bf24-db5a8692afc7)

# Code:
I have created 2 files: one for the movements function, and the other for the main program.
- In the movements file, I have created a function called `MakeMove` with 2 parameters for the left and right motor speeds. If the speed is negative, it means the motor has to move backward, and I multiplied it by -1 to make it positive; otherwise, the motor will go forward normally.
- In the main file, I have defined my pins and created an object from the `Servo` library which I named servo and attached servo_pin to it. In the setup, I defined the pins mode and initialized the baud rate for Serial monitor. In the loop, start by calculating the forward distance if it's not smaller or equal to 10 it will move forward else it will stop for awhile and search for an alternative path by looking right and left and move to the one which has larger space.

