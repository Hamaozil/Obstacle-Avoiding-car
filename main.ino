//include servo motor library
#include <Servo.h>

#define RightMotorSpeed 10
#define RightMotorA 5
#define RightMotorB 6

#define LeftMotorSpeed 11
#define LeftMotorA 7
#define LeftMotorB 8

//ultrasonic & servo pin
#define trigPin 2
#define echoPin 3
#define servo_pin 12

#define obstacle 15
Servo servo;
void setup() {
  // put your setup code here, to run once:
  pinMode(RightMotorA, OUTPUT);
  pinMode(RightMotorSpeed, OUTPUT); //speed
  pinMode(RightMotorB, OUTPUT);

  pinMode(LeftMotorA, OUTPUT);
  pinMode(LeftMotorSpeed, OUTPUT); //speed
  pinMode(LeftMotorB, OUTPUT);

  // pinMode of ultrasoinc
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //look_forward(); //turn servo motor to 90 degree so ultrasonic face forward
  servo.write(90);
  servo.attach(servo_pin, 450, 2500); // initialize min 7 max period for PWM

  Serial.begin(9600);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  long int forward_distance = GetDistance();
  Serial.print("forward distance = ");
  Serial.println(forward_distance);
  delay(70);

  if (forward_distance <= obstacle)//compare if there is obstacle or not , if yes
  {
    MakeMove(0, 0);
    Serial.print("found an obstacle at distance = ");
    Serial.println(forward_distance);
    Serial.println("Searching for altrentive way ");
    delay(200);

    Serial.println("looking right ");
    look_right();//turn servo to right
    long int right_distance = GetDistance();//get right distance
    Serial.print("right distance = ");
    Serial.println(right_distance);
    delay(100);

    Serial.println("looking left ");
    look_left();//turn servo to right
    long int left_distance = GetDistance();//get left distance
    Serial.print("left distance = ");
    Serial.println(left_distance);
    delay(100);

    Serial.println("comparing process........");
    delay(100);
    if (right_distance >= left_distance)//compare and move to the largest one
    {
      look_forward();
      MakeMove(100, -100);
      delay(450);
      Serial.println("turning right");
      delay(450);
    }
    else
    {
      look_forward();
      Serial.println("turning left");
      delay(450);
      MakeMove(-100, 100);
      delay(450);
    }
  }
  else
  {
    Serial.println("moving forward");
    MakeMove(155, 1);//move forward
  }

}
long int GetDistance()
{
  long int duration, distance;
  digitalWrite(trigPin, LOW); //set triger pin to low at first  for 2 microsecond
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);//set triger pin to high at first  for 10 microsecond (send waves)
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);//turn it off
  duration = pulseIn(echoPin, HIGH); //read duration
  distance = duration / 57; // now distance

  return distance;
}
// its better to turn servo motor slowly to make percise reads using ultrasonic
void look_forward()
{
  for (int i = 180 ; i >= 90 ; i --)
  {
    servo.write(i);
    delay(15);
  }
}

void look_right()
{
  for (int i = 90 ; i >= 0 ; i --)
  {
    servo.write(i);
    delay(15);
  }
}
void look_left()
{
  for (int i = 0 ; i <= 180 ; i ++)
  {
    servo.write(i);
    delay(15);
  }
}
