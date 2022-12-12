#include <cstdio>
#include <cstdlib>

#define VERSION "3.1.0"

#if !defined(BUILD_NUMBER)
#error BUILD_NUMBER must be defined when compiling this source file
#endif

int main(void)
{
    printf("Hello, world!\n");
    printf("\nv%s build %d\n", VERSION, BUILD_NUMBER);
    
    FILE *csv = fopen("csv/20221211/abc.csv", "r");
    
    if(!csv) {
        fprintf(stderr, "Cannot open CSV\n");
        return EXIT_FAILURE;
    }
    
    char buffer[256];
    
    while(!feof(csv)) {
        const char *line = fgets(buffer, sizeof(buffer), csv);
        if(line)
            fprintf(stdout, "%s\n", line);
    }
    
    fclose(csv);

    return EXIT_SUCCESS;
}
