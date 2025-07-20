section .data
ONEk dd 1000.0
ONE dd 1.0
THREEkSIXh dd 3600.0

section .text
bits 64
default rel
global computeAcceleration
computeAcceleration:
    
    ; Formula: (Vf - Vi)/T
    ; extern int computeAcceleration(float initialV, float finalV, float time);
    ;                                        XMM0           XMM1         XMM2
    
    VSUBSS XMM3, XMM1, XMM0                                 ; XMM3 = XMM1 - XMM0
    
    convert_KMPerH_to_mPers:
        VMULSS XMM3, XMM3, [ONEk]                           ; XMM3 = (Vf - Vi) * 1000M/H
        
        MOVSS XMM1, [ONE]
        VDIVSS XMM0, XMM1, [THREEkSIXh]                     ; XMM0 = 1m/3600s
        
        
        VMULSS XMM3, XMM3, XMM0                             ; XMM3 = (Vf - Vi) * 1000M/H * (1m/3600s)
        
        VDIVSS XMM3, XMM3, XMM2                             ; XMM3 = ((Vf - Vi) * 1000M/H * (1m/3600s)) / time
        
        CVTSS2SI EAX, XMM3                                  ; convert single precision floating point to 32 bit integer (4 bytes)
    
        RET