# cs-344-Memory-Allocator

## Introduction

This is a multi part project, each part taking one week. This is part 1.

We're going to write a malloc()/free() implementation from scratch!

You may NOT use malloc() or any of its relatives (e.g. calloc()), free(), or mmap() for this project. Solutions that use these functions will not be accepted.

When you request more data segment space from the OS with sbrk(), it increases the size of the continuous chunk of memory used for the heap, the part that's right after the program code.

There are no holes in this memory--it's one big piece.

What malloc() does is to micromanage this big space, making it look to a process like it's split into a bunch of little ones.

This is the overview for myalloc() for this week. Note that this is an incomplete implementation, but we'll be working more on it in the following weeks.

- If this is the first call, sbrk() to get some space.
    - At the same time, build a linked-list node inside the new space indicating its size and "in-use" status.
- Walk the linked list in a loop and look for the first node that is:
    - Not in-use
    - Big enough to hold the requested amount (plus padding)
- If the block is found:
    - Mark it in-use.
    - Return a pointer to the user data just after the linked list node (plus padding)).
- If no such block is found:
    - Return NULL
