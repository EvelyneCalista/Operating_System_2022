# Operating_System_2022
This repository is as a documentation for Operating System 2022 Spring class on National Yang Ming Chiao Tung University




## Introduction - FAST FILE DUPLICATION
This assignment task is to optimize the copying file with 1GB file on tmpfs. The baseline code is using low level operation, such as open(), creat(), read(), write(). This assignment is performed on the virtual memory file system tmpfs, it will eliminate disk overhead when
copying data from storage to kernel pages and vice versa. The operation is much faster as no disk access is affected.
Hence the key point in this homework is to reduce system calls using between file operation in order to minimize the
overhead results. Also the other keypoint is reduce the switch between user and kernel space.

**See the report in this [drive](https://drive.google.com/file/d/1QnSImJ7VX660Vh2oLjL2smrEe-zuRNog/view?usp=sharing).**
## Dependencies
  - Ubuntu

## Usage
1. Preconditioning:  
   a. Mount tmpfs with 3 GB size
      ```
      sudo mount -t tmpfs -o size=3G source target
      ```
   b. Clear swap  
      ```
      swapoff -a
      swapon -a
      ```
   c. Clear cache 
      ```
      sudo sh -c 'echo 3 > /proc/sys/vm/drop_caches'
      ```
2. Compile the c code
3. Run on the terminal: 
      ```
      time codefile sourcefile outputfile
      ```
      use real time to compare.
      
* The code comprises four methods to compare with the baseline
  - mmcopy : mmap() + memcpy()
  - standardlibc: fopen() + fread() + fwrite()
  - copy_file_range(): Linux Zero-copy method.
  - sendfile(): Linux Zero-copy method.
  
## References
1. copy_file_range(2)—Linux manual page. https://man7.org/linux/man-pages/man2/copy_file _range.2.html. Accessed: 2022-06-15.
2. Eﬀicient data transfer through zero copy. https://developer.ibm.com/articles/j-zerocopy/. Accessed:2022-06-15.
3. Michael Kerrisk. The Linux Programming Interface:A Linux and UNIX System Programming Handbook.1st. USA: No Starch Press, 2010. isbn: 1593272200.
4. memcpy(3). https://man7.org/linux/man-pages/man3/memcpy.3.html. Accessed: 2022-06-15.
5. Mark Mitchell and Alex Samuel. Advanced Linux Programming. USA: New Riders Publishing, 2001.isbn: 0735710430.
6. mmap(2). https://man7.org/linux/man-pages/man2/mmap.2.html. Accessed: 2022-06-15.
7. sendfile(2). https://man7.org/linux/man-pages/man2/sendfile.2.html. Accessed: 2022-06-15.
8. Storage 5: Data copying and Mmap. https://cs61.seas.harvard.edu/wiki/images/0/0a/Storage5.pdf. Accessed: 2022-06-15.
9. Understanding about Zero copy. https://ducmanhphan.github.io/2020-04-06-Understanding-about-Zero-copy/. Accessed:2022-06-15.
10. Which is fastest: read, fread, ifstream or mmap? https://lemire.me/blog/2012/06/26/which-is-fastest-read-fread-ifstream-or-mmap/. Accessed:2022-06-15.
