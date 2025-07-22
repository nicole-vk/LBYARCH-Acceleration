# Members from Group 1 LBYARCH S11A
   - Shi, Nicole Jia Ying
   - Friginal, Roj Aleck Rosal

# Introduction
A car's performance is usually measured using an acceleration test with a 1KM distance. Some cars are measured from a cold start (they start at 0KM/H), some are tested from a hot start (the car is running at a stable speed and then accelerates).
 
Factors that are needed to compute acceleration (m/s ):
1. Initial Velocity (V ) - starting speed.
2. Final Velocity (V ) - final speed at the target distance (1KM).
3. Time (T) - the total time consumed to reach 1KM.
 
The formula for acceleration is:
    
    Acceleration = (Vf - Vi) / T


# Compilation

     >nasm -f win64 asmAcceleration.asm

     >gcc -c acceleration.c -o acceleration.obj -m64

     >gcc acceleration.obj asmAcceleration.obj -o c.exe -m64

     >c.exe

## Test Cases 
   Given sample input :
3
0.0 62.5 10.1
60.0 122.3 5.5
30.0 160.7 7.8

### Input:
Enter number of cars to generate: 3  
Do you want to generate the inputs randomly (Y/N): N
```
0.0 62.5 10.1
60.0 122.3 5.5
30.0 160.7 7.8
```

### Expected Output:
```
2
3
5
```

### Input:
Enter number of cars to generate: 10   
Do you want to generate the inputs randomly (Y/N): Y
```
35.56 88.39 2.79
61.22 146.24 1.76
55.42 150.81 11.40
75.80 77.94 13.06
49.47 87.57 7.89
18.79 50.90 6.12
58.44 128.07 13.61
14.44 144.14 15.57
84.49 177.71 16.37
0.53 121.40 9.86
```

### Expected Output:
```
2
20
20
2
1
1
1
1
1
2
```

## Sample Results
<img width="422" height="691" alt="image" src="https://github.com/user-attachments/assets/c822d18d-927d-4022-b9df-9996b6bbdbb5" />
<img width="426" height="390" alt="image" src="https://github.com/user-attachments/assets/4b9dfc11-33b0-4168-b3b9-447a0e790699" />  




---


# Video Demonstration

Link:    
[Video Demo](https://drive.google.com/file/d/1_MEEIkCmwhHmggro99mRcVGDTFq5eVai/view?usp=sharing)

