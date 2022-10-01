CODE SEGMENT
     ASSUME CS:CODE, DS:CODE

     LEA SI, A 
     LEA DI, B 
     LEA  DX, OFFSET BX

     MOV AX, [SI, + 4]
     ADD AX, [DI + 4]
     MOV [BX + 4], AX

     MOV AX, [SI + 2]
     ADC AX, [DI + 2]
     MOV [BX+2], AX

     MOV AX, [SI]
     ADC AX, [DI]
     MOV [BX], AX

     HLT 

A DW 1234H, 0ABCDH, 5768H
B DW 1234H, 0ABCDH, 5768H
S DW 0H, 0H, 0H

CODE ENDS
     END
