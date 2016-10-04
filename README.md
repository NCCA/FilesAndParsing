# Files and Serialisation

## Introduction
- C  programs can store results & information permanently on disk using file handling functions 
- These functions let you write either text or binary data to a file, and read this information back later
- All file access is controlled by a file pointer :-
  - a pointer to a structure which is created when you open a file 
  - contains information about the file you opened 
  - Once the file is opened, refer to file via this pointer, NOT by its name. 
- The file pointer is a variable of type [FILE](http://www.cplusplus.com/reference/cstdio/FILE/) 

## [FILE *](http://www.cplusplus.com/reference/cstdio/FILE/)
- FILE * is a complex structure which holds information about the file system.
- This information differs from different operating systems, and file system types.
- To make the C language portable an abstraction is used
- The C library contains a number of file access functions which use the FILE * abstraction to process the information

## C++ File operations
- C++ provides a number of classes to perform output and input of characters to / from files
- These are specified to allow read, write, and read / write
- Unlike C these classes have different names as follows
  - [ofstream](http://www.cplusplus.com/reference/fstream/ofstream/) :  a stream class to write to files
  - [ifstream](http://www.cplusplus.com/reference/fstream/ifstream/) :  a stream class to read from files
  - [fstream](http://www.cplusplus.com/reference/fstream/fstream/) :  a stream class to both read and write from/to files.

# Opening a file
- To open a file we need to create a file object of the correct type.
- Once this is done we use the open method to see if the file can be accessed.
- In the following example we open a file for writing too
```
std::ifstream FileIn;

FileIn.open(argv[1]);
// check to see if we can open the file
if (!FileIn.is_open())
{
  std::cerr <<"Could not open File : "<<argv[1]<<" for writing \n";
  exit(EXIT_FAILURE);
}

```
## Stream I/O
- When a file is opened a file descriptor is returned and this file descriptor is used for each subsequent I/O operation, when any operation is carried out on the file descriptor its is known as a stream.
- When a stream is opened the stream object created is used for all subsequent file operations not the file name.

## [open](http://www.cplusplus.com/reference/fstream/ifstream/open/)
- The open method takes two parameters.
- By default we only need to specify one which is the name of the file to access.
- However we can pass an additional mode parameter which allows us to specify different operations such as read/write. 
- Also we can specify if the data is to be written as text (default) or binary 

##




## References
- [C Files](https://en.wikipedia.org/wiki/C_file_input/output)