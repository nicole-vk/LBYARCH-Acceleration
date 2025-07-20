section .text
bits 64
default rel 
global computeAcceleration
computeAcceleration:
    
    ; Formula: (Vf - Vi)/T
    ; extern int computeAcceleration(float initialV, float finalV, float time);
    ;                                        XMM0           XMM1         XMM2
    
    VSUBSD XMM3, XMM1, XMM0         ; XMM3 = XMM1 - XMM0
    
    convert_KM/H_to_M/S:
    
    
    
    
    RET