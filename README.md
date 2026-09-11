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

<img width="543" height="450" alt="circuitDiagram" src="https://github.com/user-attachments/assets/2283d8de-c883-46a8-a591-49dc535503ad" />
<img width="293" height="450" alt="stripboard" src="https://github.com/user-attachments/assets/98547f24-a68e-4a67-b6eb-ed94f7d3c0a2" />

_Left to Right: KICad circuit diagram, Strip-board circuit_

# System Testing
<img width="1113" height="450" alt="camOutput" src="https://github.com/user-attachments/assets/d5298e85-29d1-40e4-8396-281d0333c8f5" />

_Depth and Colour output produced from Python script_

Two user tests were conducted across 27 participants, both at a "minimum viable product" stage, and a final stage. These tests involved asking users to control the robot arm and carry out a list of tasks of varying difficulty. In addition to user tests, general accuracy tests were conducted, some of which are shown below.

<img width="731" height="788" alt="accuracy tests" src="https://github.com/user-attachments/assets/81bb518c-cada-4714-b8b6-010f45ca1335" />

_Elbow-joint accuracy tests_

<img width="660" height="157" alt="image" src="https://github.com/user-attachments/assets/87cd870e-2c9f-44fb-b696-0ec798a5977c" />

_Elbow-joint accuracy test results_

<img width="725" height="791" alt="image" src="https://github.com/user-attachments/assets/f9283f38-50b7-4bc1-93a7-e412f7471841" />

_Wrist accuracy tests_

<img width="717" height="292" alt="image" src="https://github.com/user-attachments/assets/57909ef9-b92a-4260-a278-a9957ec87323" />

_Basic object grip tests_



