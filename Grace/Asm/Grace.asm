;
;    Author: mhufflep
;

segment .text
    global _start
    extern dprintf
    extern exit

%macro open_file 1
    mov rdi, %1
    mov rsi, 578
	mov rdx, 0666o
	mov rax, 2
    syscall
%endmacro

%macro print_body 1
    mov rdi, rax
    mov rsi, %1
    mov rdx, 10
    mov rcx, 37
    mov r8, 34
    mov r9, %1
    call dprintf
%endmacro

%macro main 0
    open_file file
    print_body msg
    mov rdi, 0
    call exit
%endmacro

_start:
    main

segment .data
    file: db "Grace_kid.asm", 0
    msg: db ";%1$c;    Author: mhufflep%1$c;%1$c%1$csegment .text%1$c    global _start%1$c    extern dprintf%1$c    extern exit%1$c%1$c%2$cmacro open_file 1%1$c    mov rdi, %2$c1%1$c    mov rsi, 578%1$c	mov rdx, 0666o%1$c	mov rax, 2%1$c    syscall%1$c%2$cendmacro%1$c%1$c%2$cmacro print_body 1%1$c    mov rdi, rax%1$c    mov rsi, %2$c1%1$c    mov rdx, 10%1$c    mov rcx, 37%1$c    mov r8, 34%1$c    mov r9, %2$c1%1$c    call dprintf%1$c%2$cendmacro%1$c%1$c%2$cmacro main 0%1$c    open_file file%1$c    print_body msg%1$c    mov rdi, 0%1$c    call exit%1$c%2$cendmacro%1$c%1$c_start:%1$c    main%1$c%1$csegment .data%1$c    file: db %3$cGrace_kid.asm%3$c, 0%1$c    msg: db %3$c%4$s%3$c, 0", 0