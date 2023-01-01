# Learn Linux commands

1.  **file**

- determines the file type. 
- The file command uses the /etc/magic file in its attempt to identify the type of a binary file. Essentially, /etc/magic contains templates that show what different types of files look like.

> file *
>
> file main.py
>
> file /etc/magic 

<hr>

2. **objdump** 

- Displays information from object files
- The objdump is a command-line utility used to display information about an object on Unix-like systems. 
- The command, when used, gets an object file’s information even when you don’t have its source code. Therefore, it can be a debugging tool for object files, especially when working with compiler programs.

> objdump -f /bin/echo
> objdump -x /bin/ls

<hr>

3. **hexdump**

- Display  file  contents  in hexadecimal, decimal, octal, or ascii.
- The hexdump utility is a filter which displays the specified files, or standard input if no files are specified, in a user-specified format.

<hr>

4. **ifconfig**

- It is used to configure the kernel-resident network interfaces.
- It is used at boot time to set up interfaces as necessary.  After that, it  is  usually  only  needed  when  debugging or when system tuning is needed.
- Used to enable or disable a network interface

> sudo ifconfig -a
> 
> sudo ifconfig [inerface_name] 

<hr>

5. **ping**

- The command is used to check if a site/server is reachable. It can also be used to check if there is a packet loss in connection with another IP address.
- You ping another computer with packets including an ICMP ECHO_REQUEST which requests "reply if you get this"; to which, the host receives the ping and replies it with echo packets. Thus we get the amount of time it took for each packet to reach the destination, and whethere there were packets lost in the transmission.

> ping gnu.org
> 
> ping google.com

<hr>

6. **gdb**

- The purpose of a debugger such as GDB is to allow you to see what is going on ''inside'' another program while it executes-or what another program was doing at the moment it crashed. 
> https://linux.die.net/man/1/gdb

7. **lspci**

- lspci  is  a  utility for displaying information about PCI buses in the system and devices connected to them.
- Some parts of the output, especially in the highly verbose  modes,  are probably  intelligible only to experienced PCI hackers. For exact definitions of the fields, please consult either the PCI specifications  or the header.h and /usr/include/linux/pci.h include files.

> lspci -v | grep -i nvidia
>
> lspci -v | grep -i sata

<hr>

8. **lsusb**

- lsusb  is a utility for displaying information about USB buses in the system and the devices connected to them. It uses udev's hardware database to associate a full human-readable name to the vendor ID and the product ID.

> lsusb --tree
>
> lsusb -s BusNum:DeviceNum

<hr>

9. **dmesg**

- dmesg is used to examine or control the kernel ring buffer.
    - *The kernel ring buffer is a data structure that records messages related to the operation of the kernel. A ring buffer is a special kind of buffer that is always a constant size, removing the oldest messages when new messages are received.*

> sudo dmesg | grep -i usb
>
> sudo dmesg | grep -i sda
> 
> sudo dmesg -f syslog, daemon

<hr>

10. **mkfs**

- mkfs stands for **Makes File Systems**. 
- It provides the necessary framework for handling and storing the metadata, the partition can be used to add files.
- *Journaling is an important conecpt in file systems. The file systems records the pending file writes to a journal. As each file is written to, the journal is updated, and the pending write records are updated. This allows the file system to repair broken, partially written files that have occurred due to a catastrophic event such as a power cut. Some of the older file systems do not support journaling. Those that don’t, write to the disk less frequently because they don’t need to update the journal. They may perform faster, but they are more prone to damage due to interrupted file writes.* 

[More on mkfs](https://www.howtogeek.com/443342/how-to-use-the-mkfs-command-on-linux/)

<hr>

11. **fdisk**

- fdisk  is  a  dialog-driven program for creation and manipulation of partition tables.
- It understands GPT, MBR, Sun, SGI and BSD partition tables.

> sudo fdisk -l

<hr>

12. **gparted**

- The gparted application is the GNOME partition editor for creating, re‐organizing, and deleting disk partitions.
- A disk device can be subdivided  into  one  or  more  partitions. The gparted application enables you to change the partition organization on a disk device while preserving the contents of the partition.

> sudo apt install gparted

<hr>

13. **apt install**

- ***apt*** is a package manager for Debian-based Linux distros. It is a cli for packages. The command has flags like install, update, upgrade, purge, remove, etc.
- ***apt install*** is used to install a package that is available in the official repository of apt or any .deb file which is locally available

> sudo apt install neofetch
>
> sudo apt install ./procfetch_1.0_all.deb

<hr>

14. **apt-get source**

- ***apt-get*** is a command-line tool for handling packages. It may be considered the user's back-end to other tools using the APT library. Several "front-end" interfaces exist, such as aptitude, synaptic, etc.
- ***apt-get source*** causes apt-get to fetch source packages. APT will examine the available packages to decide which source package to fetch. It will then find and download into the current directory the newest available version of that source package while respecting the default release, set with the option APT::Default-Release, the -t option or per package with the pkg/release syntax, if possible.

> sudo apt-get source neofetch

<hr>

15. **lshw**

- Lists hardware. It is a symbol to extract detailed info on the h/w config of the machine.
- It can report exact memory configuration, firmware version, mainboard configuration, CPU version and speed, cache configuration, bus speed, etc. on DMI-capable x86 or IA-64 systems  and on some PowerPC machines (PowerMac G4 is known to work).
- It  currently  supports  DMI  (x86 and IA-64 only), OpenFirmware device tree (PowerPC only), PCI/AGP, CPUID (x86), IDE/ATA/ATAPI, PCMCIA  (only tested on x86), SCSI and USB.
- *DMI - Desktop Management Interface*

<hr>

16. **lsmod**

- Show the status of modules in the Linux Kernel.
- lsmod is a trivial program which nicely formats the contents of the /proc/modules, showing what kernel modules are currently loaded.

<hr>

17. **lsof**

- list open files
> An  open file may be a regular file, a directory, a block special file, a character special file, an executing text  reference,  a  library,  a stream  or  a  network  file  (Internet socket, NFS file or UNIX domain socket.)  A specific file or all the files in a file system may be  se‐ lected by path.
>
> Instead  of  a  formatted display, lsof will produce output that can be parsed by other programs.  See the -F, option description, and the OUTPUT FOR OTHER PROGRAMS section for more information.
>
> In  addition to producing a single output list, lsof will run in repeat mode.  In repeat mode it will produce output, delay,  then  repeat  the output  operation  until stopped with an interrupt or quit signal.
> 
> In the absence of any options, lsof lists all open files  belonging  to all active processes.
```
lsof 
```
<hr>

18. **netstat**

- Print network connections, routing tables, interface statistics, masquerade connections, and multicast memberships

> netstat -g
>
> netstat -i  
> 
> netstat -r

<hr>

19. **iostat**

- Report Central Processing Unit (CPU) statistics and input/output statistics for devices and partitions.
- It command is used for monitoring system input/output device loading by observing the time the devices are active in relation to their average transfer rates.
- The command generates reports that can be used to change system configuration to better balance the input/output load between physical disks.
- It generates two types of reports - CPU Utilization and Device Utilization 
    - CPU Utilization
        - For multiprocessor systems, the  CPU  values  are global averages among all processors.
    - Device Utilization
        - provides statistics  on  a per  physical  device or partition basis. Block devices and partitions for which statistics are to be displayed may be entered on the command line.  If no device nor partition is entered, then statistics are displayed for every device used by the system,  and providing that the kernel maintains statistics for it.  If the ALL keyword is given on the command line, then statistics are dis‐ played for every device defined by the system, including those that have never been used.  Transfer rates are shown in 1K  blocks by  default, unless the environment variable POSIXLY_CORRECT is set, in which case 512-byte blocks are used.

<hr>

20. **ecryptfs**

- an enterprise-class cryptographic filesystem for linux 
- eCryptfs extends Cryptfs to provide advanced key management and policy features.
- It stores cryptographic metadata in the header of each file written, so that encrypted files can be copied between hosts; the file will be decryptable with the proper key, and there is no need to keep track of any additional information aside from what is already in the encrypted file itself. 

<hr>

21. **mount**

- Mount a filesystem.
- All files accessible in a Unix system are arranged in one big tree, the file hierarchy, rooted at /.  These files  can  be  spread out over several devices.  The mount command serves to attach the  filesystem  found on some device to the big file tree.

<hr>

22. **wget**

- GNU Wget is a free utility for non-interactive download of files from the Web.  It supports HTTP, HTTPS, and FTP protocols, as well as retrieval through HTTP proxies.
- Wget is non-interactive, meaning that it can work in the background, while the user is not logged on.  This allows you to start a retrieval and disconnect from the system, letting Wget finish the work.  By contrast, most of the Web browsers require constant user's presence, which can be a great hindrance when transferring a lot of data.
- Wget can follow links in HTML, XHTML, and CSS pages, to create local versions of remote web sites, fully recreating the directory structure of the original site.  This is sometimes referred to as "recursive downloading."  While doing that, Wget respects the Robot Exclusion Standard (/robots.txt).  Wget can be instructed to convert the links in downloaded files to point at the local files, for offline viewing.
> *robots.txt is a standard used by websites to indicate to visiting web crawlers and other web robots which portions of the website they are allowed to visit. This relies on voluntary compliance. Not all robots comply with the standard; email harvesters, spambots, malware and robots that scan for security vulnerabilities may even start with the portions of the website where they have been told to stay out.*

<hr>

23. **w3m**

- w3m is a text based Web browser and pager
- *A terminal pager, paging program or simply pager is a computer program used to view (but not modify) the contents of a text file moving down the file one line or one screen at a time.*
- It is a WWW text-based client. It will display hypertext markup  language  (HTML) documents containing links to files residing on the local system, as well as files residing on remote systems.

<hr>

24. **adduser**

- Add a user or group to the system.
- adduser  and  addgroup  add users and groups to the system according to command  line  options  and  configuration  information in /etc/adduser.conf.
- They are friendlier front ends to the low level tools like useradd, groupadd and usermod programs, by default choosing Debian pol‐ icy  conformant  UID  and  GID  values,  creating a home directory with skeletal configuration, running a custom script,  and  other  features.

> useradd -u <UID> -g <group_name> <username>   
>
> useradd -e 2021-08-27 alphabeta       // username with expiry date

<hr>

25. **id**

- Print real and effective user and group IDs.
- Print user and group information for each specified USER, or (when USER omitted) for the current user.

> id -a
>
> id -Z
>
> id -G

<hr>

26. **ld**

- The GNU linker. ld combines a number of object and archive files, relocates their data and ties up symbol references. Usually the last step in compiling a program is to run ld.
- ld accepts Linker Command Language files written in a superset of AT&T's Link Editor Command Language syntax, to provide explicit and total control over the linking process.

> ld -o <output> /lib/crt0.o hello.o -lc