;
;    Author: mhufflep
;
segment .text
    global main
    extern printf
    extern exit

print_body:
;
;    push needed to align stack to 16
;
    push rbp
    call printf
    pop rbp
    ret

main:
    mov rdi, msg
    mov rsi, 10
    mov rdx, 34
    mov rcx, msg
    call print_body
    mov rdi, 0
    call exit

segment .data
    msg: db ";%1$c;    Author: mhufflep%1$c;%1$csegment .text%1$c    global main%1$c    extern printf%1$c    extern exit%1$c%1$cprint_body:%1$c;%1$c;    push needed to align stack to 16%1$c;%1$c    push rbp%1$c    call printf%1$c    pop rbp%1$c    ret%1$c%1$cmain:%1$c    mov rdi, msg%1$c    mov rsi, 10%1$c    mov rdx, 34%1$c    mov rcx, msg%1$c    call print_body%1$c    mov rdi, 0%1$c    call exit%1$c%1$csegment .data%1$c    msg: db %2$c%3$s%2$c"