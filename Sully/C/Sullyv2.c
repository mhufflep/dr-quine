#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n = 5;
#define T(x) #x
#define S(x) T(x)
#undef strcat
#define MAIN(x) int main() { const char *s = "#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\nint n = %s;\n#define T(x) #x\n#define S(x) T(x)\n#undef strcat\n#define MAIN(x) "x"\nMAIN(S(MAIN(x)))"; --n; char p[3] = {0}; p[0] = 37; p[1] = 115; char src[30] = "./Sully_"; char cc[50] = "clang "; char exe[30] = "./Sully_"; char num[32]; num[30] = 48; int c = (n < 0) ? -n : n; int i = 30; for (; c; c /= 10) num[i--] = "0123456789"[c - 10 * (c / 10)]; if (n < 0) num[i] = '-'; if (n > 0) i++; strcat(src, &num[i]); strcat(src, ".c"); strcat(exe, &num[i]); strcat(cc, src); strcat(cc, " -o "); strcat(cc, exe); FILE *f = fopen(src, "w+"); fprintf(f, s, &num[i], p); fclose(f); system(cc); return (n > 0 ? system(exe) : 0); }
MAIN(S(MAIN(x)))