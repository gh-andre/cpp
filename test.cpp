#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <format>

#define VERSION "3.2.0"

#if !defined(BUILD_NUMBER)
#error BUILD_NUMBER must be defined when compiling this source file
#endif

struct options_t {
    bool print_help = false;
    bool print_version = false;
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

options_t parse_options(int argc, char *argv[])
{
    options_t options;
    
    for(int i = 1; i < argc; i++) {
       if(*argv[i] != '-')
           throw std::runtime_error(std::format("Unknown argument {:s}", argv[i]));
        
       switch (argv[i][1]) {
           case 'h':
               options.print_help = true;
               break;
           case 'v':
               options.print_version = true;
               break;
           case '-':
               if(!strcmp(argv[i]+2, "help"))
                   options.print_help = true;
               else if (!strcmp(argv[i]+2, "version"))
                   options.print_version = true;
               else
                   throw std::runtime_error(std::format("Unknown long option {:s}", argv[i]));
               break;
           default:
               throw std::runtime_error(std::format("Unknown option {:s}", argv[i]));
       }
    }

    return options;
}

int main(int argc, char *argv[])
{
    try {
        options_t options = parse_options(argc, argv);

        if(options.print_version) {
            print_version();
            return EXIT_SUCCESS;
        }
    
        if(options.print_help) {
            print_help();
            return EXIT_SUCCESS;
        }

        FILE *csv = fopen("csv/20221211/abc.csv", "r");
    
        if(!csv)
            throw std::runtime_error("Cannot open CSV");
    
        char buffer[256];
    
        while(fgets(buffer, sizeof(buffer), csv)) {
            printf("%s", buffer);
        }
    
        if(ferror(csv)) {
            fclose(csv);
            throw std::runtime_error("Error reading CSV");
        }
    
        fclose(csv);
    
        return EXIT_SUCCESS;
    }
    catch (const std::exception& error) {
        fprintf(stderr, "%s\n", error.what());
    }

    return EXIT_FAILURE;
}
