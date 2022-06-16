#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/sendfile.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
//sendfile
//source: https://richard.esplins.org/static/downloads/linux_book.pdf
int main (int argc, char* argv[])
{
    int fd_in;
    int fd_out;
    struct stat stat_buf;
    off_t offset = 0;

    //Input 
    fd_in = open (argv[1], O_RDONLY);
    // Stat the input file get its size.
    fstat (fd_in, &stat_buf);
    //output 
    fd_out = open (argv[2], O_WRONLY | O_CREAT, stat_buf.st_mode);
    // Blast the bytes from one file to the other
    sendfile (fd_out, fd_in, &offset, stat_buf.st_size);
    
    close (fd_in);
    close (fd_out);

    return 0;
}