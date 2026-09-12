# Mimicry-Based Control System for a Custom 10-DoF Robotic Arm

A low-cost, real-time teleoperation system that allows users to control a custom-built robotic arm by moving their own arm in front of a camera. 

## Project Goals

1. Develop an intuitive, cheap, easy-to-use real-time teleoperation system
2. Build a custom robot arm to run user tests validating that system

The design employs two Human-Computer Interaction principles — **direct interaction** and **embodiment**, helping to reduce layers of abstraction between the user's intent, and controlling the robot's motion.

## Hardware

- **5-DoF robotic arm**: 2 shoulder joints, 1 elbow joint, 2 wrist joints, designed from scratch in Autodesk Fusion
- **5-DoF robotic gripper**: open-source design, modified and assembled for this project
- **Electronics**: 11 servo motors and an Arduino Micro, all wired through a custom strip-board

| | | |
|:---:|:---:|:---:|
| <img src="https://github.com/user-attachments/assets/4a10e985-98c4-481d-9852-8261e2ca47c6" height="400"> | <img src="https://github.com/user-attachments/assets/3d071471-126d-408f-aa27-df0cc25ffb57" height="400"> | <img src="https://github.com/user-attachments/assets/2a1542ab-fe2c-4f61-a7bc-d53b6bac8a5b" height="400"> |
| **Final 3D model** | **Exploded view** | **Assembled open-source gripper** |

| | |
|:---:|:---:|
| <img src="https://github.com/user-attachments/assets/5a73ebd4-476d-4b97-afd9-1959659b870e" height="500"> | <img src="https://github.com/user-attachments/assets/a331ce67-aab0-4d84-996b-e2d2295d5c28" height="500"> |
| **Final robot arm** | **Final robot arm (folded)** |

| | |
|:---:|:---:|
| <img src="https://github.com/user-attachments/assets/2283d8de-c883-46a8-a591-49dc535503ad" height="450"> | <img src="https://github.com/user-attachments/assets/98547f24-a68e-4a67-b6eb-ed94f7d3c0a2" height="450"> |
| **KiCad circuit diagram** | **Assembled strip-board** |

## Control System

| **Stage** | **Description** |
|---|---|
| 1. **Capture** | RGB and depth data streamed from an RGB-D camera to a Python script |
| 2. **Detection** | MediaPipe hand and pose detection locates key landmarks on the user's arm |
| 3. **Estimation** | Vector calculus is used to compute joint angles, distances, and each finger's "open-ness" from obtained landmarks |
| 4. **Data Passing** | These values are received by the C# script stored on the Arduino Micro
| 5. **Smoothing** | The ServoEasing library is used to smoothly interpolate each joint's target position |
| 6. **Actuation** | Final servo values are sent to each servo motor by the Arduino Micro |

<p align="center"><img src="https://github.com/user-attachments/assets/d5298e85-29d1-40e4-8396-281d0333c8f5" width="600"></p>
<p align="center"><i>Depth and colour output from the Python tracking script</i></p>

## Testing & Results

Two rounds of user testing were run across **27 participants** at both an early "minimum viable product" stage and a final stage. During these tests users completed a set of tasks of increasing difficulty, and subsequently filled out a Systems Usability Scale questionnaire. These were supplemented by accuracy tests on individual joints, as shown below.

| | |
|:---:|:---:|
| <img src="https://github.com/user-attachments/assets/81bb518c-cada-4714-b8b6-010f45ca1335" height="500"> | <img src="https://github.com/user-attachments/assets/f9283f38-50b7-4bc1-93a7-e412f7471841" height="500"> |
| **Elbow-joint accuracy test setup** | **Wrist accuracy test setup** |

<p align="center"><img src="https://github.com/user-attachments/assets/87cd870e-2c9f-44fb-b696-0ec798a5977c" height="500"> </p>
<p align="center"> <b>Elbow-joint accuracy results</b> </p>

<p align="center"><img src="https://github.com/user-attachments/assets/57909ef9-b92a-4260-a278-a9957ec87323" height="500"> </p>
<p align="center"> <b>Basic object grip test results</b> </p>
