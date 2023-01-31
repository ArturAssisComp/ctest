<a name="readme-top"></a>

[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/ArturAssisComp/ctest.git">
  </a>

  <h3 align="center">CTEST</h3>

  <p align="center">
    An unit test lib for C.
    <br />
    <a href="#documentation"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href=[issues-url]>Report Bug</a>
    ·
    <a href=[issues-url]>Request Feature</a>
  </p>
</div>

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#description">Description</a></li>
    <li><a href="#how-is-a-contribution-made">How to contribute</a></li>
    <li><a href="#requirements">Requirements</a></li>
    <li><a href="#how-to-use-the-makefile">How to use the makefile</a></li>
    <li>
      <a href="#how-to-use-ctest-in-other-projects">Using ctest</a>
      <ul>
        <li><a href="#example-of-usage">Example</a></li>
      </ul>
    </li>
    <li>
      <a href="#documentation">Documentation</a>
      <ul>
	<details>
          <summary>index</summary>
          <li><a href="#overview">Overview</a></li>
	      <li><a href="#types">Types</a></li>
	      <li><a href="#variables">Variables</a></li>
          <li><a href="#constants">Constants</a></li>
          <li><a href="#functions">Functions</a></li>
	      <ul>
              <li><a href="#single-data-types">Single data types</a></li>
	              <ul>
                       <li><a href="#unsigned_integer">unsigned_integer</a></li>
                       <li><a href="#integer">integer</a></li>
                       <li><a href="#floating_point">floating_point</a></li>
                       <li><a href="#bool">bool</a></li>
                       <li><a href="#char">char</a></li>
                       <li><a href="#file">file</a></li>
                       <li><a href="#void-pointer">Void pointer</a></li>
                  </ul>
              <li><a href="#array-data-types">Array data type</a></li>
	              <ul>
                       <li><a href="#unsigned_integerarray">unsigned_integerArray</a></li>
                       <li><a href="#integerarray">integerArray</a></li>
                       <li><a href="#boolarray">boolArray</a></li>
                       <li><a href="#chararray">charArray</a></li>
                       <li><a href="#string">string</a></li>
                  </ul>
          </ul>
          <li><a href="#macros">Macros</a></li>
	</details>
      </ul>
    </li>

  </ol>
</details>



<p align="right">(<a href="#readme-top">back to top</a>)</p>






# Description 

This repository contains a library that can be used to unittest C code.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

# How is a contribution made?

1. Create a branch from an issue;
2. Clone the repository: 
```bash
git clone  https://github.com/ArturAssisComp/ctest.git
```
3. Change to the desired branch: 
```bash
cd ctest
git checkout <branch-name>
```
4. For each meaningful change, make a commit;

-> Fist, add the files that were changed: 
```bash
git add <filename1> <filename2> ... <filenameN>
```
-> Commit the changes: 
```bash
git commit -m "Implemented function foo()"
```
5. Push the changes: 
```bash
git push origin <name-of-the-branch>
```
6. If more changes are necessary, go to 4. Else,
   go to 7;
7. Create a pull request and assign someone to review the changes
   that were made in the branch;

=> Other useful commands:

Check the history of commits
```bash
git log
```
Check the status of the repository
```bash
git status
```
Get changes from remote repository from branch master
```bash
git pull origin <master-branch-name>
```

<p align="right">(<a href="#readme-top">back to top</a>)</p>

# Requirements

make       4.3

gcc        11.2.0

<p align="right">(<a href="#readme-top">back to top</a>)</p>

# How to use the makefile?

Run the following command in the terminal in the root directory of the ctest project:
```bash
make
```  
The headers, object files, and archive lib object will be saved into ./build/ folder. 
They may be used to implement unit tests using ctest lib in other projects.

To clean ./build/ folder, run:
```bash
make clean
```

In order to run all tests:
```bash
make test
```
or, to print the results to txt files in ./build/test_results/
```bash
make test_to_txt
```
<p align="right">(<a href="#readme-top">back to top</a>)</p>

# How to use ctest in other projects?

Run the command make from the ctest base directory:
```bash
make
```  
then, the headers and the archive ctest.a files will be created and saved 
into the folder ./build/ctest_lib/

The files are organized as follows:

headers --> ./build/ctest_lib/include/

ctest.a --> ./build/ctest_lib/lib/

In order to use the library, the user must copy the content from ctest_lib 
to the desired folder in the target project, import the header ctest.h, and 
compile the file with the unit tests using as input, among others, the 
ctest.a object file.

## Example of usage
Let us suppose that the base directory for ctest is CTEST_BASE_DIR and the 
base directory for the target project, in which the unit tests will be 
implemented, is BASE_DIR. In an actual case, it is necessary to exchange
BASE_DIR and CTEST_BASE_DIR to the respective actual directory name.

1 - Execute the make command from CTEST_BASE_DIR:
```bash
cd CTEST_BASE_DIR
make
```  

2 - Copy the folder CTEST_BASE_DIR/build/ctest_lib and its contents to the
target project:
```bash
cp -r CTEST_BASE_DIR/build/ctest_lib BASE_DIR/
```  

3 - Create the unit test file with name unit_test.c:
```C
//C file that implements the unit tests
#include "ctest_lib/include/ctest.h"


#define MSG_SIZE 100

int add(int a, int b)
{
    return a + b;
}

int main(void)
{
	char suite_name[] = "Unit test";
	char suite_description[] = "Basic test case.";
	char *functions_tested[] = {
        "add",
		NULL
	};
	char error_msg[MSG_SIZE] = "";
	char msg[MSG_SIZE] = ""; 


	//------------------------------------------------------------------------------
	start_suite(suite_name, suite_description, functions_tested);
		//------------------------------------------------------------------------------
		start_module("EDGE CASES", "Module for testing edge cases.", functions_tested);
            /* 0 + 0 */
            assert_integer_equal(add(0, 0), 0, __LINE__, "add(0, 0) == 0");
            /*------*/
            /* -1 + 0 */
            assert_integer_equal(add(-1, 0), -1, __LINE__, "add(-1, 0) == -1");
            /*------*/
            /* -1 + 1 */
            assert_integer_equal(add(-1, 1), 0, __LINE__, "add(-1, 1) == 0");
            /*------*/
            /* 1 + 1 */
            assert_integer_equal(add(1, 1), 2, __LINE__, "add(1, 1) == 2");
            /*------*/
            /* -1 + 2 */
            assert_integer_equal(add(-1, 2), 1, __LINE__, "add(-1, 2) == 1");
            /*------*/    
		end_module();
		//------------------------------------------------------------------------------
    		//------------------------------------------------------------------------------
		start_module("Domain CASES", "Module for testing domain cases.", functions_tested);
            /* 123 + 44 */
            assert_integer_equal(add(123, 44), 167, __LINE__, "add(123, 44) == 167");
            /*------*/
            /* -14 + 10 */
            assert_integer_equal(add(-14, 10), -4, __LINE__, "add(-14, 10) == -4");
            /*------*/ 
		end_module();
		//------------------------------------------------------------------------------
        
		
	end_suite();
	//------------------------------------------------------------------------------
}
```

4 - Compile the unit test file and execute it:
```bash
cd BASE_DIR
gcc -o unit_test unit_test.c ctest_lib/lib/ctest_a
```  

5 - Execute unit_test and check the results:
```bash
unit_test
``` 
<p align="right">(<a href="#readme-top">back to top</a>)</p>


# Documentation

## Overview

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Types

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Variables

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Constants

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Functions

### Single data types

#### unsigned_integer

<p align="right">(<a href="#readme-top">back to top</a>)</p>

#### integer

<p align="right">(<a href="#readme-top">back to top</a>)</p>

#### floating_point


<p align="right">(<a href="#readme-top">back to top</a>)</p>


#### bool

<p align="right">(<a href="#readme-top">back to top</a>)</p>

#### char

<p align="right">(<a href="#readme-top">back to top</a>)</p>

#### file

<p align="right">(<a href="#readme-top">back to top</a>)</p>

#### void pointer

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Array data types

#### unsigned_integerArray

<p align="right">(<a href="#readme-top">back to top</a>)</p>

#### integerArray

<p align="right">(<a href="#readme-top">back to top</a>)</p>

#### boolArray

<p align="right">(<a href="#readme-top">back to top</a>)</p>

#### charArray

<p align="right">(<a href="#readme-top">back to top</a>)</p>


#### string

<p align="right">(<a href="#readme-top">back to top</a>)</p>


## Macros


<p align="right">(<a href="#readme-top">back to top</a>)</p>



[issues-shield]: https://img.shields.io/github/issues/ArturAssisComp/ctest?logo=github&style=for-the-badge
[issues-url]: https://github.com/ArturAssisComp/ctest/issues

[license-shield]: https://img.shields.io/github/license/othneildrew/Best-README-Template.svg?style=for-the-badge
[license-url]: https://github.com/ArturAssisComp/ctest/blob/version1_0/LICENSE
