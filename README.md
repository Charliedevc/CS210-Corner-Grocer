# CS210-Corner-Grocer

## Project Summary

For this project, I created a C++ program for the Corner Grocer that tracks how often grocery items were purchased. The program reads item names from an input file, counts how many times each item appears, and gives the user a menu with different options. The user can search for a specific item, view all item frequencies, or display a histogram using asterisks. The program also creates a backup file called `frequency.dat`.

## What I Did Well

One thing I think I did well was organizing the program into a class instead of putting everything directly into `main()`. This made the code easier to follow and helped keep each part of the program focused on one job. I also used a map to store the grocery items and their counts, which made the frequency tracking cleaner and more efficient.

## Where I Could Improve

One area I could improve is input handling. The program already checks for invalid menu choices, but I could make it even stronger by handling item names with spaces or cleaning punctuation from the input file. I could also separate the class into a header file and implementation file to make the project more professional and easier to expand later.

## Challenges

The most challenging part was making sure the file input worked correctly and that the program handled missing or empty files without crashing. I worked through this by checking whether the file opened successfully and returning false if the program could not load the data. I also used course materials, examples, and debugging to better understand how file streams and maps work in C++.

## Transferable Skills

This project helped me practice skills that I can use in future programming courses and real projects. Some of those skills include reading and writing files, using classes, working with maps, validating user input, and writing menu-driven programs. These are important because many programs need to process data, store information, and interact with users.

## Maintainability, Readability, and Adaptability

I made the program maintainable by separating the major tasks into different functions, such as reading the input file, creating the backup file, displaying the menu, searching for an item, and showing the histogram. I also used comments to explain what important sections of the code do. The program is adaptable because the input and output file names are stored as variables, and the class structure would make it easier to add new features later.
