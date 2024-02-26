This is the supposed group project but i worked alone



# Simple Shell
## Description
    - a UNIX command line interpreter
    - Alx team project ,but i choose to work alone 

# Compilation
    - gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

# Team members
    - Daniel Demerw
# Testing
    - this shell works in interactive mode:
        $ ./hsh
        ($) /bin/ls
        hsh main.c shell.c
        ($)
        ($) exit
        $
    - also in non-interactive mode:
        $ echo "/bin/ls" | ./hsh
        hsh main.c shell.c test_ls_2
        $
        $ cat test_ls_2
        /bin/ls
        /bin/ls
        $
        $ cat test_ls_2 | ./hsh
        hsh main.c shell.c test_ls_2
        hsh main.c shell.c test_ls_2
        $

# File and function content included in this project
    ========== _change.c ==========
    _change
    ========== Built_ins1.c ==========
    shell_env
    shell_cd
    shell_help
    shell_exit
    ========== builtins2.c ==========
    shell_setenv
    shell_unsetenv
    ========== execute.c ==========
    get_function
    execute
    new_process
    ========== main.c ==========
    main
    ========== read_line.c ==========
    read_line
    ========== read_stream.c ==========
    read_stream
    ========== shell.h ==========
    struct builtin
    ========== _strcmp.c ==========
    _strcmp
    ========== split_line.c ==========
    split_line

# Reference
- https://medium.com/@santiagobedoa/coding-a-shell-using-c-1ea939f10e7e
- https://brennan.io/2015/01/16/write-a-shell-in-c/

