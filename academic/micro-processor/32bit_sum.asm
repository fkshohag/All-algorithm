CODE SEGMENT
     ASSUME CS:CODE, DS:CODE

     LEA SI, A 
     LEA DI, B 
     LEA  DX, OFFSET BX

     MOV AX, [SI, + 2]
     ADD AX, [DI + 2]
     MOV [BX + 2], AX

     MOV AX, [SI]
     ADD AX, [DI]
     MOV [BX], AX
     HLT 

A DW 1234H, 0ABCDH
B DW 1234H, 0ABCDH
S DW 0H, 0H

CODE ENDS
     END
