#ifndef CTEST_H
#define CTEST_H

//Declaration of functions:
void print_result();
void start_suite(char *name, char *description, char *func_ids[]);
void end_suite();
void start_module(char *name, char *description, char *func_ids[]);
void end_module();
#endif
