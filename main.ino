//Author Vishnu Ajay 
//July 2023

#include <Arduino.h>


const int IN1_PIN = 12;  
const int IN2_PIN = 13;  
const int ENA_PIN = 11;  


const int IN3_PIN = 10;  
const int IN4_PIN = 9;   
const int ENB_PIN = 5;   
// Joystick pins
const int Y_PIN = A1;  
const int X_PIN = A0;  

void setup() {
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
  pinMode(ENA_PIN, OUTPUT);
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, LOW);

  pinMode(IN3_PIN, OUTPUT);
  pinMode(IN4_PIN, OUTPUT);
  pinMode(ENB_PIN, OUTPUT);
  digitalWrite(IN3_PIN, LOW);
  digitalWrite(IN4_PIN, LOW);

  // Initialize PWM for motor 
  analogWrite(ENA_PIN, 0);
  analogWrite(ENB_PIN, 0);

  Serial.begin(9600);
  Serial.println("Motor control initialized.");
}

void loop() {
  
  int y_value = analogRead(Y_PIN);
  int x_value = analogRead(X_PIN);

  //(Y-axis)
  int motor_speed_1 = map(y_value, 0, 1023, -255, 255);
  motor_speed_1 = constrain(motor_speed_1, -255, 255);

  //  (X-axis)
  int motor_speed_2 = map(x_value, 0, 1023, -255, 255);
  motor_speed_2 = constrain(motor_speed_2, -255, 255);

  
  if (motor_speed_1 > 0) {
    forward(IN1_PIN, IN2_PIN);
    Serial.println("Motor 1: Forward");
  } else if (motor_speed_1 < 0) {
    backward(IN1_PIN, IN2_PIN);
    Serial.println("Motor 1: Backward");
  } else {
    stopMotor(IN1_PIN, IN2_PIN);
    Serial.println("Motor 1: Stop");
  }


  if (motor_speed_2 > 0) {
    forward(IN3_PIN, IN4_PIN);
    Serial.println("Motor 2: Left");
  } else if (motor_speed_2 < 0) {
    backward(IN3_PIN, IN4_PIN);
    Serial.println("Motor 2: Right");
  } else {
    stopMotor(IN3_PIN, IN4_PIN);
    Serial.println("Motor 2: Stop");
  }


  analogWrite(ENA_PIN, abs(motor_speed_1));
  analogWrite(ENB_PIN, abs(motor_speed_2));
}

void forward(int in1, int in2) {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void backward(int in1, int in2) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void stopMotor(int in1, int in2) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}
