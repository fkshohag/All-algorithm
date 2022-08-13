CODE SEGMENT
    ASSUME CS:CODE, DS:CODE
    
        MOV AX, 5H  
        MOV BX, 5H
        CMP BX, AX
        JE Equal
        JG Greater
        JL Less
       
    Greater:
       MOV DX, 0   
       JMP Last
        
    Equal:
       MOV DX, 1H
       JMP Last   
       
    Less:
       MOV DX, 2H
       JMP Last
    
        
    Last: HLT
   
CODE ENDS
     END
