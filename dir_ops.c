#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

void make_dir(char *name) {
    mkdir(name, 0777);
}

void change_dir(char *path) {
    chdir(path);
}

void print_dir() {
    char cwd[100];
    getcwd(cwd, sizeof(cwd));
    printf("%s\n", cwd);
}

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
}}
