#include <cstdio>

#define VERSION "1.1.0"

#if !defined(BUILD_NUMBER)
#error BUILD_NUMBER must be defined when compiling this source file
#enfif    

int main(void)
{
    printf("Hello, world!\n");
    printf("\nv%s build %d\n", VERSION, BUILD_NUMBER);
    return 0;
}
