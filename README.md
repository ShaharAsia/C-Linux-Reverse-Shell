# C-Linux-Reverse-Shell

To gain control over a compromised system, we aim to gain interactive shell access for arbitrary command execution.
With such access, we can try to elevate the privileges to obtain full control of the operating system.
To do that, I created a program that will be compiled for a target system.
When executed, it will perform the following steps -
1. Creates a new socket and connects to it.
2. Changes the file descriptors of the process into the socket.
3. Runs a new shell bin/sh (with the same file descriptors).

* We will listen to the net by running "nc -lvvp port_num" command (l for listen , vv for visual, p for port) - 
when the target system executes this code, we will watch and get the control.
