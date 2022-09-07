#include <fcntl.h>
#include <stdio.h>

/*
    Author: mhufflep
*/
#define OPEN(x) int fd = open(x, O_CREAT | O_TRUNC | O_RDWR, 0666);
#define PRINT() dprintf(fd, s, 10, 10, 10, 10, 10, 10, 10, 10, 34, s, 34, 34, 34, 10);
#define MAIN() int main() { const char *s = "#include <fcntl.h>%c#include <stdio.h>%c%c/*%c    Author: mhufflep%c*/%c#define OPEN(x) int fd = open(x, O_CREAT | O_TRUNC | O_RDWR, 0666);%c#define PRINT() dprintf(fd, s, 10, 10, 10, 10, 10, 10, 10, 10, 34, s, 34, 34, 34, 10);%c#define MAIN() int main() { const char *s = %c%s%c; OPEN(%cGrace_kid.c%c); PRINT(); }%cMAIN()"; OPEN("Grace_kid.c"); PRINT(); }
MAIN()