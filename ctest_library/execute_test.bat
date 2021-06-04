@ECHO off
gcc -c main.c
gcc -o teste main.o -L. -lctest
del main.o
teste
del teste
pause
