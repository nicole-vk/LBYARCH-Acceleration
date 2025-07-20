# Introduction
A car's peformance is usually measured using an acceleration test with a 1KM distance. Some cars are measured from a cold start (they start at 0KM/H), some are tested from a hot start (the car is running at a stable speed and then accelerates).
 
Factors that are needed to compute acceleration (m/s ):
1. Initial Velocity (V ) - starting speed.
2. Final Velocity (V ) - final speed at the target distance (1KM).
3. Time (T) - the total time consumed to reach 1KM.
 
The formula for acceleration is:
    
    Acceleration = (Vf - Vi) / T

# How to compile?

     >nasm -f win64 asmAcceleration.asm

     >gcc -c acceleration.c -o acceleration.obj -m64

     >gcc acceleration.obj asmAcceleration.obj -o c.exe -m64

     >c.exe