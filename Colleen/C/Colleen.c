#include <stdio.h>

/*
    Author: mhufflep
*/
void display() {
    const char *s = "#include <stdio.h>%c%c/*%c    Author: mhufflep%c*/%cvoid display() {%c    const char *s = %c%s%c;%c    printf(s, 10, 10, 10, 10, 10, 10, 34, s, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10);%c}%c%cint main() {%c    /*%c        Hola, amigo!%c    */%c    display();%c    return 0;%c}";
    printf(s, 10, 10, 10, 10, 10, 10, 34, s, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10);
}

int main() {
    /*
        Hola, amigo!
    */
    display();
    return 0;
}