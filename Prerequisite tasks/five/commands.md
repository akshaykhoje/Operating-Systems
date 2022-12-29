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

7. **lspci**

8. **lsusb**

9. **dmesg**

10. **mkfs**

11. **fdisk**

12. **gparted**

13. **apt install**

- ***apt*** is a package manager for Debian-based Linux distros. It is a cli for packages. The command has flags like install, update, upgrade, purge, remove, etc.
- ***apt install*** is used to install a package that is available in the official repository of apt or any .deb file which is locally available

> sudo apt install neofetch
>
> sudo apt install ./procfetch_1.0_all.deb


14. **apt-get source**

- ***apt-get*** is a command-line tool for handling packages. It may be considered the user's back-end to other tools using the APT library. Several "front-end" interfaces exist, such as aptitude, synaptic, etc.
- ***apt-get source*** causes apt-get to fetch source packages. APT will examine the available packages to decide which source package to fetch. It will then find and download into the current directory the newest available version of that source package while respecting the default release, set with the option APT::Default-Release, the -t option or per package with the pkg/release syntax, if possible.

> sudo apt-get source neofetch

15. **lshw**

16. **lsmod**

17. **lsof**

18. **netstat**

19. **iostat**

20. **ecryptfs**

21. **mount**

22. **wget**

23. **w3m**

24. **adduser**

25. **id**

26. **ld**
