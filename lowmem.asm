    ; Clear carry flag
    clc
 
    ; Switch to the BIOS (= request low memory size)
    int 0x12
 
    ; The carry flag is set if it failed
    jc .Error
 
    ; AX = amount of continuous memory in KB starting from 0.
