@ECHO off
gcc -c assert.c ctest.c text_formatting.c
ar rsc libctest.a assert.o ctest.o text_formatting.o
del assert.o ctest.o text_formatting.o
