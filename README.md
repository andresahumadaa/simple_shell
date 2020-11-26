# Basic Shell

[![holberton](https://images.squarespace-cdn.com/content/v1/5a4bfe8bf09ca4228ceca3b7/1539139199598-ANH454IHZI1OKWONKRXY/ke17ZwdGBToddI8pDm48kNp8pt3EdxuCXc7Btqw6aCUUqsxRUqqbr1mOJYKfIPR7LoDQ9mXPOjoJoqy81S2I8N_N4V1vUb5AoIIIbLZhVYxCRW4BPu10St3TBAUQYVKc582kKJI7R4YoEbaG0ar5y9SuJlHH4BCe-KXYJFHtaWtSg47dcfuoHTlsl7xAkdij/logo.jpg?format=2500w "holberton")](https://images.squarespace-cdn.com/content/v1/5a4bfe8bf09ca4228ceca3b7/1539139199598-ANH454IHZI1OKWONKRXY/ke17ZwdGBToddI8pDm48kNp8pt3EdxuCXc7Btqw6aCUUqsxRUqqbr1mOJYKfIPR7LoDQ9mXPOjoJoqy81S2I8N_N4V1vUb5AoIIIbLZhVYxCRW4BPu10St3TBAUQYVKc582kKJI7R4YoEbaG0ar5y9SuJlHH4BCe-KXYJFHtaWtSg47dcfuoHTlsl7xAkdij/logo.jpg?format=2500w "holberton")

## what is this project?
is a project to create our own mini shell, our shell is a simple version that has basic functionality. You can create / write / read / open / delete folders, print things in terminal, change directories, etc. Is one of the first large projects where we implemented everything seen in this quarter 

the commands authorized to use the shell were
* `chdir (man 2 chdir)`
* `execve (man 2 execve)`
* `exit (man 3 exit)`
* `fork (man 2 fork)`
* `free (man 3 free)`
* `getline (man 3 getline)`
* `isatty (man 3 isatty)`
* `malloc (man 3 malloc)`
* `perror (man 3 perror)`
* `signal (man 2 signal)`
* `stat (__xstat) (man 2 stat)`
* `strtok (man 3 strtok)`
* `wait (man 2 wait)`
* `write (man 2 write)`

## how is it composed? and why ?
- **PID & PPID
A process is an instance of an executing program, that has a unique process ID. This process ID is used by many functions and system calls to interact with \
and manipulate processes. In order to retrieve the current process ID, getpid (man 2 getpid)

## How To Install & Compile
To have this repository and its content, you must execute the following on your terminal:
$ git clone https://github.com/andresahumadaa/simple_shell.git
$ cd simple_shell/

You do not need to create a main function as it is already in our files.

Once you done installing it you are able to write make build in your terminal and the shell will be running by then.

## Description of the files contained
|  name | description and funcion  |
| ------------ | ------------ |
|  holberton.h |Header file. It contains the necessary standard libraries and the prototypes used in all the functions of the program.  |
| simple_shell.c | Contains the main function that execute our own shell |
