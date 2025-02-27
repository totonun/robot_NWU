#include <Servo.h>
int R_SPEED = 100;//-500 to 500 (0=STOP)
int L_SPEED = 100;//-500 to 500 (0=STOP)
Servo L_SERVO;
Servo R_SERVO;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  L_SERVO.attach(14,1000,2000);//PORT(A0),MIN,MAX
  R_SERVO.attach(15,1000,2000);//PORT(A1),MIN,MAX
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == 'b') { //Back
    setSpeed(-1, 1, 1);

    } else if (command == 'f') { //Foward
    setSpeed(1, 1, 1);

    } else if (command == 's') { //Stop
    setSpeed(1, 0, 0);

    } else if (command == 'r') { // Right
    setSpeed(1, 0.5, 1.2);

    } else if (command == 'l') { // Left
    setSpeed(1, 1.2, 0.5);
    }
  }
}

void setSpeed(int dir, float aR, float aL){
  L_SERVO.writeMicroseconds(1500 - L_SPEED *dir * aL);
  R_SERVO.writeMicroseconds(1500 + R_SPEED *dir * aR);
}