# A Mimicry-Based Control System for a Custom-Built, 10 Degree-of-Freedom Robotic Arm
**There were two main goals for this project:**
1. To develop an intuitive, cheap, easy-to-use real-time teleoperation system
2. To make a custom robot arm to test conduct user tests with this system

In order to achieve this Human-Computer Interaction principles were used: **direct interaction** and **embodiment**. To remove abstraction from the control system, the user is able to control the robot arm by simply moving their arm in front of a camera, and the system would attempt to mimic this motion.

The robotic arm consisted of:
- A 5-DoF robotic arm made up of 2 shoulder joints, an elbow joint, and 2 wrist joints. This was designed entirely from scratch in Autodesk Fusion.
- An open-source 5-DoF robotic gripper that I modified and assembled to fit the purposes of this project.
- 11 servo motors and 1 Arduino Micro all connected through 1 strip-board

The control system consisted of a Python script, a C# script, and an RGB-D camera. A brief explanation of the system is as follows:
- RGB and depth data was streamed from a specialised camera to the Python script.
- The Python script ran MediaPipe's hand and pose tracking to detect the location of important landmarks in the user's arm.
- Vector calculus was used to determine the relative angles and distances between different important landmarks in order to estimate the orientation of the user's arm, wrist, and the "open-ness" of each finger.
- This information was sent periodically to a C# script.
- The C# script utilised a ServoEasing library to smoothly update the position of each of the robot's links.
- These values were then sent to the Arduino Micro.

# Robot Arm and Hardware
<img width="300" height="450" alt="3D model of robot arm" src="https://github.com/user-attachments/assets/4a10e985-98c4-481d-9852-8261e2ca47c6" />
<img width="337.5" height="450" alt="exploded view" src="https://github.com/user-attachments/assets/3d071471-126d-408f-aa27-df0cc25ffb57" />
<img width="300" height="450" alt="Robot hand gripper" src="https://github.com/user-attachments/assets/2a1542ab-fe2c-4f61-a7bc-d53b6bac8a5b" />

_Left to Right: Final 3D model, Exploded Final 3D model, Assembled open-source gripper_

<img width="208.75" height="450" alt="Final robot arm" src="https://github.com/user-attachments/assets/5a73ebd4-476d-4b97-afd9-1959659b870e" />
<img width="305" height="450" alt="Final robot arm (folded)" src="https://github.com/user-attachments/assets/a331ce67-aab0-4d84-996b-e2d2295d5c28" />

_Left to Right: Final robot arm, Final robot arm (Folded)_

<img width="543" height="450" alt="KICad circuit diagram" src="https://github.com/user-attachments/assets/bb6017e2-7ca9-421e-87e0-9ed9251f6420" />
<img width="293" height="450" alt="stripboard" src="https://github.com/user-attachments/assets/98547f24-a68e-4a67-b6eb-ed94f7d3c0a2" />

_Left to Right: KICad circuit diagram, Strip-board circuit_

