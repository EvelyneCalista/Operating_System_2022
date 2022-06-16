
// high level operation with stdlibc
// fopen, fread, fwrite
#include <stdio.h>
#include <stdlib.h>
#define BUFFSIZE 1024  
int
main(int argc, char *argv[])
{
    char buffer[BUFFSIZE];
    size_t bytes;
    FILE *fd_in, *fd_out;
    fd_in = fopen(argv[1], "rb");
    fd_out = fopen(argv[2], "wb");
    if(fd_in == NULL || fd_out == NULL)
        return 1;                                               // or other action
    while (0 < (bytes = fread(buffer, 1, sizeof(buffer), fd_in)))
    {
    fwrite(buffer, 1, bytes, fd_out);
    }
    fclose(fd_out);
    fclose(fd_in);
    return 0;
}