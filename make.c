#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>


struct makewhat {
    
    // ------- first argument boolean --------

    bool dir;
    bool file;
    bool debug;

    // ------- other condition boolean --------

    bool ext;
    bool perm;
    bool name;

    // ------- String --------

    char *nameStr;
    char *extStr;
};

void init(struct makewhat *mw) {

    // ------- Init boolean -------

    mw -> dir   = false;
    mw -> file  = false;
    mw -> ext   = false;
    mw -> name  = false;
    mw -> debug = false;

    // ------- Init String -------

    mw -> nameStr = NULL;
    mw -> extStr  = NULL;

}

void make(struct makewhat *mw) {

    if (mw -> debug) {

        printf("DIR   : %d\n", mw -> dir);
        printf("FILE  : %d\n", mw -> file);
        printf("EXT   : %d\n", mw -> ext);
        printf("NAME  : %d\n", mw -> name);
        printf("DEBUG : %d\n", mw -> debug);

        if (mw -> name) {

            if (mw -> file) printf("File name: %s\n", mw -> nameStr);
            if (mw -> dir)  printf("Dir name: %s\n", mw -> nameStr);

        } 

        if (mw -> ext) printf("Extension name: %s\n", mw -> extStr);

    }

    if (mw -> dir) {
        int result = mkdir(mw -> nameStr, 0777);
        if (result != 0 && mw -> debug) {
            perror("Error creating directory");
        }
    }

    if (mw -> file) {

        char fullName[256];

        if (mw -> name) {

            if (mw -> ext) {

                strcpy(fullName, mw -> nameStr);
                strcat(fullName, mw -> extStr);

            } else {

                strcpy(fullName, mw -> nameStr);
            }
        }

        if (mw -> ext  && !mw -> name) strcpy(fullName, mw -> extStr);
        if (!mw -> ext && !mw -> name) strcpy(fullName, "default");




        FILE *cfile = fopen(fullName, "w");
        if (cfile == NULL && mw -> debug) {

            perror("Error creating file.");

        } else {

            fclose(cfile);
        }
    }

}

int main(int argc, char *argv[]) {

    struct makewhat mw;
    init(&mw);

    if(argc < 2) {

        printf("Error: No argument.\n");
        return 1;

    } else {

        for(int arg = 1; arg < argc; arg++) {

            if(strcmp(argv[arg], "dir") == 0) mw.dir = true;
            if(strcmp(argv[arg], "file") == 0) mw.file = true;

            if(strcmp(argv[arg], "-e") == 0) {

                if (arg + 1 < argc) {


                    mw.ext = true;
                    char ext[256];

                    strcpy(ext, ".");
                    strcat(ext, argv[arg + 1]);

                    mw.extStr = ext;
                    arg++;

                } else {
                    printf("Error: No extension type after -e.\n");
                    return 1;
                }
            }

            if(strcmp(argv[arg], "-n") == 0) {

                if (arg + 1 < argc) {

                    mw.name = true;
                    mw.nameStr = argv[arg + 1];
                    arg++;

                } else {

                    printf("Error: No name after -n.\n");
                    return 1;

                }
            }

            if(strcmp(argv[arg], "-debug") == 0 || strcmp(argv[arg], "-d") == 0) {

                mw.debug = true;
            }
        }

        make(&mw);
    }

    return 0;
}