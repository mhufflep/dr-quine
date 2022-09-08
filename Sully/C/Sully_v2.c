#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n = 5;
#define T(x) #x
#define S(x) T(x)
#undef strcat
#undef sprintf
#define MAIN(x) int main() { const char *s = "#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\nint n = %s;\n#define T(x) #x\n#define S(x) T(x)\n#undef strcat\n#undef sprintf\n#define MAIN(x) "x"\nMAIN(S(MAIN(x)))"; char ps[3] = {0}; ps[0] = 37; ps[1] = 115; char pd[3] = {0}; pd[0] = 37; pd[1] = 100; char src[30] = "./Sully_"; char cc[50] = "clang "; char exe[30] = "./Sully_"; char num[32]; sprintf(num, pd, n); strcat(src, num); strcat(src, ".c"); strcat(exe, num); strcat(cc, src); strcat(cc, " -o "); strcat(cc, exe); FILE *f = fopen(src, "w+"); sprintf(num, pd, n - 1); fprintf(f, s, num, ps); fclose(f); system(cc); return (n > 0 ? system(exe) : 0); }
MAIN(S(MAIN(x)))