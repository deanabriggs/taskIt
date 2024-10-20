# Overview

This software was created to use C++ to solve a real world problem. It demonstrates the use of conditionals, loops, functions, classes, and a vector. It also shows how data can be exported to a file.

This is a task list program designed with an installation service company in mind. Each time the company makes a sale, a long list of tasks need to be accomplished before and after the installation. This program provides a built in list of "pre" and "post" tasks. This avoids individually entering each task for each customer, minimizing dataentry and ensuring nothing is missed.

[Software Demo Video](https://www.loom.com/share/8e6b0ebc2cf3496aa95d3a8e6deece03?sid=6a9f999b-4842-4631-bf90-aef7c9882418)

# Development Environment

Software
* VS Code (1.94.2)
* C++ (13.2.0)
* MinGW-w64s (GCC 13.2.0 / g++ 13.2.0 / GDB 14.1)

Libraries
* vector
* fstream
* iostream

# Useful Websites
 
- [w3schools C++ Tutorial](https://www.w3schools.com/cpp/)
- [MinGW for C++ on Windows](https://code.visualstudio.com/docs/cpp/config-mingw#_prerequisites)

# Future Work

Other things that would improve the software:

- Options to print a portion of the list by department, customer, priority, or incomplete
- Options for the user to chose a file name before saving
- Add error catching for no data in the vector before saving
- Add a "header" file in the event that the program gets larger
- Consider making the Task class private