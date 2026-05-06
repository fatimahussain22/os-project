#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

// create directory
void make_dir(char *name) {
    mkdir(name, 0777);
}

// change directory
void change_dir(char *path) {
    chdir(path);
}

// print current directory
void print_dir() {
    char cwd[100];
    getcwd(cwd, sizeof(cwd));
    printf("%s\n", cwd);
}

// list directory contents
void list_dir() {
    struct dirent *d;
    DIR *dir = opendir(".");

    if(dir == NULL) {
        printf("Cannot open directory\n");
        return;
    }

    while((d = readdir(dir)) != NULL) {
        printf("%s\n", d->d_name);
    }

    closedir(dir);
}
