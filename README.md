# Simple Shell
## Description
A simple UNIX command interpreter. mini_shell is the user interface to communicate with the operative system services.

This project consists in the creation of a simple shell
that will allow the user to interact with the system using commands.

It handles the PATH to find the programs it will execute.
It will use the execve() system call to perform the commands.
The execution of the programs will be done under children processes using fork().
CTRL+C won't close the program, with the command exit close the shell.


### Requirements
Gcc (gnu compiler collection) version 4.8
##### Included .c .h source code
main.c - main code Loop
shell.c - execute source code
shell.h - prototypes 
cespecial.c - source code look for the type of delimiter
cases.c - source code run according delimiter
ctrlc.c - source code for avoid the ctrl+c
salir.c - source code for implement the exit and cases
env.c - source code Implement the env built-in.
### Compiling
gcc-4.8 -Wall -Werror -Wextra -pedantic *.c -o hsh

### Running
./hsh

### Output
our program have the  same output as sh

### Example:
**$ ls**
use path for list the files

**$ echo l**
use path for found echo and execute file 

**$ /bin/ls**
for list the files in the current directory or

**$ /bin/pwd**
for display the current directory address
### FlowChart

```flow
st=>start: Start
op=>operation: Loop infinite 
cond=>condition: Successful Yes or No?
e=>end: To admin

st->op->cond
cond(yes)->e
cond(no)->op
```
### How to exit
You have two forms to exit from micro_shell, just type exit

**$ exit**
**You can press CTRL + d**

## AUTHORS

**Edgar Quintero** <fogniebla@hotmail.com>
**Jimmer Hernandez** <jichernandezbe@unal.edu.co>
