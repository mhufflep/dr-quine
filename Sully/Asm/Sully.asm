;
;    Author: mhufflep
;

segment .text
    global _start
    extern dprintf
    extern sprintf
    extern system
    extern exit

%macro open_file 1
    mov rdi, %1
    mov rsi, 578
    mov rdx, 0666o
    mov rax, 2
    syscall
%endmacro

%macro print_body 1
    mov rsi, %1
    mov rdx, 10
    mov rcx, [n]
    sub rcx, 1
    mov r8, 34
    mov r9, %1
    call dprintf
%endmacro

%macro resolve_name 3
    mov rdi, %1
    mov rsi, %2
    mov rdx, %3
    call sprintf
%endmacro

_start:
    resolve_name buf, src, [n]
    open_file buf
    mov rdi, rax
    print_body body
    resolve_name buf, cc, [n]
    mov rdi, buf
    call system
    cmp qword [n], 0
    jle return
    resolve_name buf, exe, [n]
    mov rdi, buf
    call system

return:
    mov rdi, 0
    call exit

segment .data
	n: dq 5
    buf: times 200 db 0
    src: db "Sully_%1$d.asm", 0
    exe: db "./Sully_%1$d", 0
	cc: db "nasm -f elf64 Sully_%1$d.asm && ld Sully_%1$d.o -o Sully_%1$d -lc --dynamic-linker /lib/x86_64-linux-gnu/ld-linux-x86-64.so.2 && rm -f Sully_%1$d.o", 0
    body: db ";%1$c;    Author: mhufflep%1$c;%1$c%1$csegment .text%1$c    global _start%1$c    extern dprintf%1$c    extern sprintf%1$c    extern system%1$c    extern exit%1$c%1$c%%macro open_file 1%1$c    mov rdi, %%1%1$c    mov rsi, 578%1$c    mov rdx, 0666o%1$c    mov rax, 2%1$c    syscall%1$c%%endmacro%1$c%1$c%%macro print_body 1%1$c    mov rsi, %%1%1$c    mov rdx, 10%1$c    mov rcx, [n]%1$c    sub rcx, 1%1$c    mov r8, 34%1$c    mov r9, %%1%1$c    call dprintf%1$c%%endmacro%1$c%1$c%%macro resolve_name 3%1$c    mov rdi, %%1%1$c    mov rsi, %%2%1$c    mov rdx, %%3%1$c    call sprintf%1$c%%endmacro%1$c%1$c_start:%1$c    resolve_name buf, src, [n]%1$c    open_file buf%1$c    mov rdi, rax%1$c    print_body body%1$c    resolve_name buf, cc, [n]%1$c    mov rdi, buf%1$c    call system%1$c    cmp qword [n], 0%1$c    jle return%1$c    resolve_name buf, exe, [n]%1$c    mov rdi, buf%1$c    call system%1$c%1$creturn:%1$c    mov rdi, 0%1$c    call exit%1$c%1$csegment .data%1$c	n: dq %2$d%1$c    buf: times 200 db 0%1$c    src: db %3$cSully_%%1$d.asm%3$c, 0%1$c    exe: db %3$c./Sully_%%1$d%3$c, 0%1$c	cc: db %3$cnasm -f elf64 Sully_%%1$d.asm && ld Sully_%%1$d.o -o Sully_%%1$d -lc --dynamic-linker /lib/x86_64-linux-gnu/ld-linux-x86-64.so.2 && rm -f Sully_%%1$d.o%3$c, 0%1$c    body: db %3$c%4$s%3$c, 0", 0