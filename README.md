# dr-quine

## Description

The goal of this project is to write three quines.

A quine is a program that output is equal to its source code.

This project is done using C, Asm ans JavaScript.

## Requirements

### Colleen
1. The source code should be printed in stdout 
2. At least 1 comment in global scope
3. At least 1 comment inside function
4. One extra function that should be called inside main

### Grace
1. The source code should be printed in Grace_kid.ext
2. At least 1 comment should present 
3. Only three defines
4. No main declared

### Sully
1. A variable equal to 5 should be declared in source
2. The source code should be printed in Sully_X.ext with a var decremented by 1
3. The program should compile Sully_X.ext (if necessary)
4. The result executable should be run if X > 0

## Try

:warning: All the asm parts were written on Linux (Ubuntu 20.04, elf64)

Use `make` to compile project.

`make test` will run basic test for each quine.

There is also `make test2` for Sully. 
