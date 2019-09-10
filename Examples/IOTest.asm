TITLE Test IO subroutine            

INCLUDE Irvine32.inc

.data

iArray DWORD 100 dup(0)
count  DWORD ?
prompt1 BYTE "Enter the Number of Integer (<100):",0
prompt2 BYTE "Enter Integers (<):",0

.code
main PROC
	mov edx,offset prompt1
	WriteString
	
	exit
main ENDP
END main