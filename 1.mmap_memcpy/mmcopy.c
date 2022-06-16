// mmap and memcpy

#define _GNU_SOURCE
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
int main(int argc, char *argv[]){

    int fd_in, fd_out;
    char *src, *dest;
    size_t filesize;
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    //Input 
    fd_in = open(argv[1], O_RDONLY);
    filesize = lseek(fd_in, 0, SEEK_END);

    src = mmap(NULL, filesize, PROT_READ, MAP_PRIVATE, fd_in, 0);

    //output 
    fd_out = open(argv[2], O_RDWR | O_CREAT, 0666);

    ftruncate(fd_out, filesize);

    dest = mmap(NULL, filesize, PROT_READ | PROT_WRITE, MAP_SHARED, fd_out, 0);

    //copyprocess

    memcpy(dest, src, filesize);

    munmap(src, filesize);
    munmap(dest, filesize);

    close(fd_in);
    close(fd_out);

    return 0;
}