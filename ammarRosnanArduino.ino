#include <ServoEasing.hpp>
// #include <Servo.h>

ServoEasing base;           // pin 13
ServoEasing shoulderLeft;   // pin 18
ServoEasing shoulderRight;  // pin 12
ServoEasing mainWrist;            // pin 10
ServoEasing subWrist;       // pin 8
ServoEasing elbow;          // pin 11
ServoEasing thumb;          // pin 23 - none
ServoEasing index;          // pin 22 - red
ServoEasing middle;         // pin 21 - mix
ServoEasing ring;           // pin 20 - blue
ServoEasing pinky;          // pin 19 - orange

void setup() {
  // Pinout Values
  Serial.begin(115200);
  base.attach(13, 500, 2500);
  shoulderLeft.attach(18, 500, 2500);
  shoulderRight.attach(12, 500, 2500);

  elbow.attach(11, 500, 2500);
  mainWrist.attach(10, 500, 2500);
  subWrist.attach(8, 500, 2500);

  thumb.attach(23, 500, 2500);
  index.attach(22, 900, 2500);
  middle.attach(21, 500, 2500);
  ring.attach(20, 500, 2500);
  pinky.attach(19, 500, 2500);

  // Servo Easing Parameters
  base.setEasingType(EASE_CUBIC_IN_OUT);
  shoulderLeft.setEasingType(EASE_CUBIC_IN_OUT);
  shoulderRight.setEasingType(EASE_CUBIC_IN_OUT);

  elbow.setEasingType(EASE_CUBIC_IN_OUT);
  mainWrist.setEasingType(EASE_CUBIC_IN_OUT);
  subWrist.setEasingType(EASE_CUBIC_IN_OUT);

  thumb.setEasingType(EASE_CUBIC_IN_OUT);
  index.setEasingType(EASE_CUBIC_IN_OUT);
  middle.setEasingType(EASE_CUBIC_IN_OUT);
  ring.setEasingType(EASE_CUBIC_IN_OUT);
  pinky.setEasingType(EASE_CUBIC_IN_OUT);

  setSpeedForAllServos(200);
}

void loop() {
  if (Serial.available() > 0) {
    String line = Serial.readStringUntil('\n');
    
    int firstComma = line.indexOf(',');
    int secondComma = line.indexOf(',', firstComma + 1);
    int thirdComma = line.indexOf(',', secondComma + 1);
    int fourthComma = line.indexOf(',', thirdComma + 1);
    int fifthComma = line.indexOf(',', fourthComma + 1);
    int sixthComma = line.indexOf(',', fifthComma + 1);
    int seventhComma = line.indexOf(',', sixthComma + 1);
    int eigthComma = line.indexOf(',', seventhComma + 1);
    int ninthComma = line.indexOf(',', eigthComma + 1);
    int tenthComma = line.indexOf(',', ninthComma + 1);
    
    if (firstComma != -1 && secondComma != -1) {
      int leftShoulderVal = line.substring(0, firstComma).toInt();
      int rightShoulderVal = line.substring(firstComma + 1, secondComma).toInt();
      int elbowVal = line.substring(secondComma + 1, thirdComma).toInt();
      int baseVal = line.substring(eigthComma + 1, ninthComma).toInt();

      int thumbVal = line.substring(thirdComma + 1, fourthComma).toInt();
      int indexVal = line.substring(fourthComma + 1, fifthComma).toInt();
      int middleVal = line.substring(fifthComma + 1, sixthComma).toInt();
      int ringVal = line.substring(sixthComma + 1, seventhComma).toInt();
      int pinkyVal = line.substring(seventhComma + 1, eigthComma).toInt();

      int subWristVal = line.substring(ninthComma + 1, tenthComma).toInt();
      int mainWristVal = line.substring(tenthComma + 1).toInt();

      base.startEaseTo(baseVal);
      shoulderLeft.startEaseTo(leftShoulderVal);
      shoulderRight.startEaseTo(rightShoulderVal);

      elbow.startEaseTo(elbowVal);
      mainWrist.startEaseTo(mainWristVal);
      subWrist.startEaseTo(subWristVal);

      thumb.startEaseTo(thumbVal); 
      index.startEaseTo(indexVal); 
      middle.startEaseTo(middleVal);
      ring.startEaseTo(ringVal);
      pinky.startEaseTo(pinkyVal);
    }
  }
  delay(10);
}