# Operating_System_2022
This repository is as a documentation for Operating System 2022 Spring class on National Yang Ming Chiao Tung University




## Introduction
This assignment task is to optimize the copying file with 1GB file on \emph{tmpfs}. The \emph{tmpfs} uses main memory as its storage medium to eliminate disk overhead. Therefore we will focus on how to reduce the overhead between two switches from user to/from kernel, and one copy overhead from kernel pages to/from user buffer.

**Get the report in this [drive](https://reurl.cc/aNR1VD).**
## Dependencies
  - Ubuntu

## Usage
1. Mount tmpfs with 3 GB size
      ```
      sudo mount -t tmpfs -o size=3G source target
      ```
2. Compile the c code
3. Run on the terminal: 
      ```
      time codefile sourcefile outputfile
      ```

      ```
  
## References
[1] copy_file_range(2)—Linuxmanualpage. https : / /
man7.org/linux/man-pages/man2/copy_file_range.
2.html. Accessed: 2022-06-15.
[2] File Transfer. https : / / www . ibm . com / topics / file -
transfer. Accessed: 2022-06-15.
[3] Michael Kerrisk. The Linux Programming Interface:
A Linux and UNIX System Programming Handbook.
1st. USA: No Starch Press, 2010. isbn: 1593272200.
[4] memcpy(3). https : / / man7 . org / linux / man - pages /
man3/memcpy.3.html. Accessed: 2022-06-15.
[5] mmap(2). https : / / man7 . org / linux / man - pages /
man2/mmap.2.html. Accessed: 2022-06-15.
[6] sendfile(2). https : / / man7 . org / linux / man - pages /
man2/sendfile.2.html. Accessed: 2022-06-15.
[7] Storage 5: Data copying and Mmap. https : / / cs61 .
seas.harvard.edu/wiki/images/0/0a/Storage5.pdf.
Accessed: 2022-06-15.
[8] Which is fastest: read, fread, ifstream or mmap? https:
//lemire.me/blog/2012/06/26/which-is-fastest-read-
fread-ifstream-or-mmap/. Accessed: 2022-06-15.

