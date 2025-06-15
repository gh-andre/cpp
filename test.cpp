#include <cstdio>
#include <cstdlib>

#define VERSION "3.1.0"

#if !defined(BUILD_NUMBER)
#error BUILD_NUMBER must be defined when compiling this source file
#endif

void print_version(void)
{
    printf("\nv%s build %d\n", VERSION, BUILD_NUMBER);
}

int main(void)
{
    print_version();

    printf("Hello, world!\n");

    FILE *csv = fopen("csv/20221211/abc.csv", "r");

    if(!csv) {
        fprintf(stderr, "Cannot open CSV\n");
        return EXIT_FAILURE;
    }

    char buffer[256];

    while(fgets(buffer, sizeof(buffer), csv)) {
        printf("%s", buffer);
    }

    if(ferror(csv)) {
        fprintf(stderr, "Error reading CSV\n");
        fclose(csv);
        return EXIT_FAILURE;
    }

    fclose(csv);

    return EXIT_SUCCESS;
}
