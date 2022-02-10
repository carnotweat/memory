CLC			; CF bug workaround
	MOV AH, 0x88
	INT 0x15		; request upper memory size
	JC SHORT .ERR
	TEST AX, AX		; size = 0 is an error
	JE SHORT .ERR
	; AX = number of contiguous KB above 1M
