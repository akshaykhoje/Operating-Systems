# A lab exam based on the following will be conducted in the first week of the semester.

- Since you are going to do a LOT of C programming, its good to brush up your C skills. Write a C program on Linux, which does the following: 
    - Reads a CSV file with columns Name, MISID, Marks; then calculates the average, total, and median marks, and saves all the result in another CSV file with columns  statistics, number. The filenames should be accepted as command-line arguments.
    - Reads a CSV file with columns Name, MISID, Marks. Creates a doubly circular linked list of all the entries from the file.  Then sorts this doubly linked list on MISID. Then Reads another CSV file with same columns, and inserts the entries from the second CSV file into the doubly linked list in Sorted order.  The code should be properly divided into functions and a DCLL data type.
    - Read the header of a JPEG file and print it.
- Read the C-FAQ and "The C Programming Language"
- Take any 4 of your DSA-1 programs, compile them using gcc -S and see the assembly code. Draw a diagram of how the stack is built and wound up. Try to understand how the calling convention is followed. Try to have programs which use local variables, static varibles, static globals, globals, and also a program which is split into multiple files.
- Read the contents of the file /usr/include/stdio.h
- Learn Linux commands:  file, objdump, hexdump, ifconfig, ping, gdb, lspci, lsusb, dmesg, mkfs, fdisk, gparted,  apt install, apt-get source, lshw, lsmod, lsblk, lsof, netstat, iostat, ecryptfs, mount, wget, w3m,  adduser, id, ld,
- Read the following manual pages:  cat, head, printf, lseek (and open, read, write), exit
  which purpose the following files serve on Linux?
    - /etc/fstab  /etc/nsswitch.conf  /etc/resolv.conf  /var/log/apache2/error.log   /proc/cpuinfo /proc/partitions  /proc/uptime /proc/version  /boot/vmlinuz /boot/grub/grub.lst  /usr/lib/x86_64-linux-gnu/libc.so.6 /snap  /dev/sda /dev/nvme0  /dev/sda2 /dev/null /dev/zero   /etc/passwd /etc/shadow
- Answer following questions
    - What is a .a file and a .so file? How are they different?
    - How to create a  .a file and a .so file ?
- How big is the code of the sqrt() function in the Math library on Linux? Find out the code. Find the code of sqrt() and count the number of lines.  Why do you think the code is "complex"?
- Try creating  a new user on your Linux system, by manually editing /etc/passwd and /etc/shadow (beware!)
- Write an assembly program by hand, on 64-bit Ubuntu 20.04 (or 22.04), on x86_64 processor,  which reads two numbers using scanf, adds them, and prints the result using printf. Compile the program using GCC or gas and verify that it works.
