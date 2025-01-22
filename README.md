# Symbol Table Project
  The Symbol Table Project is an implementation of a symbol table data structure in C++. A symbol table is a fundamental data structure used in compilers and interpreters to store and manage information about variables, functions, and other entities in a program. This implementation uses a linked list to store key-value pairs and provides various operations for managing and querying the table.

## Features
- **Add Bindings:** Insert key-value pairs into the symbol table.
- **Replace Bindings:** Update the value associated with a given key.
- **Remove Bindings:** Delete a key-value pair from the symbol table.
- **Query Bindings:** Check if a key exists and retrieve its associated value.
- **Length Query:** Get the number of bindings in the table.
- **Print Bindings:** Display all key-value pairs in the symbol table.

## Prerequisites
- **C++ Compiler:** Supports at least C++14.
- **Google Test Framework:** Required for unit testing.

## **Setup Instructions**

1. Clone the repository:  
   `git clone <repository_url>`

2. Navigate to the project folder:  
   `cd symbol_table_project`

3. Build the project using `make` or `cmake`:  
   For Makefile:  
   `make`

   For CMake:  
   `cmake . && make`

4. Run the tests:  
   `./run_tests`

## **Usage**

- **Adding Bindings:**  
  Use the `SymTable_put` method to add key-value pairs.

- **Replacing Bindings:**  
  Use the `SymTable_replace` method to update the value for a specific key.

- **Removing Bindings:**  
  Use the `SymTable_remove` method to delete a key-value pair.

- **Querying Bindings:**  
  Use the `SymTable_contains` to check if a key exists and `SymTable_get` to retrieve its value.

- **Printing Bindings:**  
  Use the `SymTable_printbinding` to display all key-value pairs stored in the symbol table.
