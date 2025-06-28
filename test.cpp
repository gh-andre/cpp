#include <cstdio>
#include <cstdlib>
#include <cstring>

#define VERSION "3.2.0"

#if !defined(BUILD_NUMBER)
#error BUILD_NUMBER must be defined when compiling this source file
#endif

enum class OPT {
    NONE,
    HANDLED,
    ERROR
};

void print_version(void)
{
    printf("\nv%s build %d\n", VERSION, BUILD_NUMBER);
}

void print_help(void)
{
    printf("Usage: test [options]\n\n");

    printf("  -h, --help      Show this help message\n");
    printf("  -v, --version   Show version information\n");
}

OPT parse_options(int argc, char *argv[])
{
    if(argc == 1)
      return OPT::NONE;

    for(int i = 1; i < argc; i++) {
       if(*argv[i] != '-') {
           fprintf(stderr, "Unknown argument %s\n", argv[i]);
           return OPT::ERROR;
       }
        
       switch (argv[i][1]) {
           case 'h':
               print_help();
               break;
           case 'v':
               print_version();
               break;
           case '-':
               if(!strcmp(argv[i]+2, "help"))
                   print_help();
               else if (!strcmp(argv[i]+2, "version"))
                   print_version();
               else {
                   fprintf(stderr, "Unknown long option %s\n", argv[i]);
                   return OPT::ERROR;
               }
               break;
           default:
               fprintf(stderr, "Unknown option %s\n", argv[i]);
               return OPT::ERROR;
       }
    }

    return OPT::HANDLED;
}

int main(int argc, char *argv[])
{
    switch(parse_options(argc, argv)) {
        case OPT::HANDLED:
            return EXIT_SUCCESS;
        case OPT::ERROR:
            return EXIT_FAILURE;
    }

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
