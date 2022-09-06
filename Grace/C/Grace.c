/* Author: mhufflep */
#include <stdio.h>
#define T(x) #x
#define S(x) T(x)
#define MAIN(x) int main() { const char *s = "/* Author: mhufflep */\n#include <stdio.h>\n#define T(x) #x\n#define S(x) T(x)\n#define MAIN(x) "x"\nMAIN(S(MAIN(x)))"; FILE *f = fopen("Grace_kid.c", "w+"); fputs(s, f); fclose(f); return 0; }
MAIN(S(MAIN(x)))