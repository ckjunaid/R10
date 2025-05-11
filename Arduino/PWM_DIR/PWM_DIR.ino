#include <CytronMotorDriver.h>

// Motor Driver Configuration
// motor1 = Left motor (PWM=3, DIR=4), motor2 = Right motor (PWM=1, DIR=2)
CytronMD motor1(PWM_DIR, 3, 4);
CytronMD motor2(PWM_DIR, 1, 2);

void setup() {
  Serial.begin(9600);
  Serial.println("Cytron Teleoperation Ready!");
  motor1.setSpeed(0);
  motor2.setSpeed(0);
}

void loop() {
  if (Serial.available()) {
    char cmd = Serial.read();
    if (cmd == '\n' || cmd == '\r') return;

    switch (cmd) {
      case 'f':  // Forward
        motor1.setSpeed(200);
        motor2.setSpeed(200);
        Serial.println("Forward");
        break;

      case 'r':  // Reverse
        motor1.setSpeed(-200);
        motor2.setSpeed(-200);
        Serial.println("Reverse");
        break;

      case 'l':  // Left turn
        motor1.setSpeed(-150);
        motor2.setSpeed(150);
        Serial.println("Turn Left");
        break;

      case 't':  // Right turn
        motor1.setSpeed(150);
        motor2.setSpeed(-150);
        Serial.println("Turn Right");
        break;

      case 's':  // Stop
        motor1.setSpeed(0);
        motor2.setSpeed(0);
        Serial.println("Stopped");
        break;

      case 'h':  // Help
        Serial.println("Commands:");
        Serial.println("f = forward");
        Serial.println("r = reverse");
        Serial.println("l = turn left");
        Serial.println("t = turn right");
        Serial.println("s = stop");
        break;

      default:
        Serial.println("Invalid command. Use 'h' for help.");
        break;
    }
  }
}
