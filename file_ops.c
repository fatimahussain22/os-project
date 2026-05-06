#include <stdio.h>
#include <unistd.h>

void remove_file(char *name) {
    remove(name);
}

void remove_dir(char *name) {
    rmdir(name);
}

void move_file(char *old, char *new) {
    rename(old, new);
}
