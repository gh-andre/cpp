#include <cstdio>
#include <cstdlib>

#define VERSION "2.6.0"

#if !defined(BUILD_NUMBER)
#error BUILD_NUMBER must be defined when compiling this source file
#endif

int main(void)
{
    printf("Hello, world!\n");
    printf("\nv%s build %d\n", VERSION, BUILD_NUMBER);

    return EXIT_SUCCESS;
}
