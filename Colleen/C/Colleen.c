#include <stdio.h>

/* Author: mhufflep */
void display() {
    const char *s = "#include <stdio.h>%c%c/* Author: mhufflep */%cvoid display() {%c    const char *s = %c%s%c;%c    printf(s, 10, 10, 10, 10, 34, s, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10);%c}%c%cint main() {%c    /* Hola, amigo! */%c    display();%c    return 0;%c}";
    printf(s, 10, 10, 10, 10, 34, s, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10);
}

int main() {
    /* Hola, amigo! */
    display();
    return 0;
}