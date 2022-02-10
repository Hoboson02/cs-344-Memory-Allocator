# cs-344-Memory-Allocator

##Introduction

This is a multi part project, each part taking one week. This is part 1.

Hint: before you type a line of code, you should understand this problem well enough to teach it to someone to the degree they could work an example with pen and paper. It will be much harder to implement if you do not understand it well enough. This advice is always true, but I want to really drive it home for this project where it is especially true.

We're going to write a malloc()/free() implementation from scratch!

You may NOT use malloc() or any of its relatives (e.g. calloc()), free(), or mmap() for this project. Solutions that use these functions will not be accepted.

When you request more data segment space from the OS with sbrk(), it increases the size of the continuous chunk of memory used for the heap, the part that's right after the program code.

There are no holes in this memory--it's one big piece.

What malloc() does is to micromanage this big space, making it look to a process like it's split into a bunch of little ones.
