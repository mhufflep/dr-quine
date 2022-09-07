; 
; Author: mhufflep
;
segment .text
    global _start
    extern printf

_start:
; 
; Haro, ma furendo!
;
mov rdi, body
mov rsi, body
mov rdx, 10
mov rcx, 34
mov r8, 59
call printf

return:
mov rax, 0
ret

segment .data
body db "%4$c%2$c%4$c Author: mhufflep%2$c%4$c%2$csegment .text%2$cglobal _main%2$cextern printf%2$c%2$c_main:%2$c%4$c%2$c%4$c  Haro, ma furendo!%2$c%4$c%2$cmov rdi, body%2$ccall printf%2$c%2$creturn:%2$cmov rax, 0%2$cret%2$c%2$csegment .data%2$cbody db %3$c%1$s%3$c, 0", 0