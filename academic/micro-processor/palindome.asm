CODE SEGMENT
     ASSUME CS:CODE DS:CODE

     MOV AX, 8301H
     PUSH AX
     XOR BX, BX

     MOV CL, 16D

     L1:
       SHR AX, 1
       ADC BX, 0H
       CMP CX, 1
       JE Last
       SHL BX, 1
       LOOP L1

    LAST:
       POP AX
       CMP AX, BX
       JE EQUAL
       MOV DX, 1
           HLT 
    EQUAL:
         MOV DX, 0
         HLT 
    CODE ENDS 
         END