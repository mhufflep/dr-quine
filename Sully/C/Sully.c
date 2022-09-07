#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define NAME(buf, f) snprintf(buf, sizeof(buf), f, n - 1)
#define COMP(buf, src, exe) snprintf(buf, sizeof(buf), "clang %s -o %s", src, exe)

int main() {
    int n = 5;
    const char *s = "#include <fcntl.h>%c#include <stdio.h>%c#include <stdlib.h>%c%c#define NAME(buf, f) snprintf(buf, sizeof(buf), f, n - 1)%c#define COMP(buf, src, exe) snprintf(buf, sizeof(buf), %cclang %%s -o %%s%c, src, exe)%c%cint main() {%c    int n = %d;%c    const char *s = %c%s%c;%c    char src[50], exe[50], comp[50];%c    NAME(src, %c./Sully_%%d.c%c);%c    NAME(exe, %c./Sully_%%d%c);%c    COMP(comp, src, exe);%c    int fd = open(src, 1538, 0777);%c    dprintf(fd, s, 10, 10, 10, 10, 10, 34, 34, 10, 10, 10, n - 1, 10, 34, s, 34, 10, 10, 34, 34, 10, 34, 34, 10, 10, 10, 10, 10, 10);%c    system(comp);%c    return (n - 1 > 0 ? system(exe) : 0);%c}";
    char src[50], exe[50], comp[50];
    NAME(src, "./Sully_%d.c");
    NAME(exe, "./Sully_%d");
    COMP(comp, src, exe);
    int fd = open(src, 1538, 0777);
    dprintf(fd, s, 10, 10, 10, 10, 10, 34, 34, 10, 10, 10, n - 1, 10, 34, s, 34, 10, 10, 34, 34, 10, 34, 34, 10, 10, 10, 10, 10, 10);
    system(comp);
    return (n - 1 > 0 ? system(exe) : 0);
}