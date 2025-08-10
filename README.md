# Queue Implementations in C
This repository contains C programs demonstrating the implementation of **Linear Queue** and **Circular Queue** using arrays.

## What is a Queue?

A **Queue** is a linear data structure that follows the **FIFO (First In First Out)** principle. Elements are inserted from the **rear** and removed from the **front**.

Real-world analogy: A queue at a ticket counter — the first person to enter the line is the first to be served.

---

## Linear Queue

### Characteristics:
- Elements are added at the **rear** and removed from the **front**.
- Uses a **one-way movement** approach.
- Implemented using an array.

### Limitation:
In a Linear Queue implemented using arrays, once the rear reaches the end of the array, no more elements can be added even if there is free space at the beginning (due to removed elements). This leads to **wasted space**.

### Operations:
- **Enqueue**: Add an element at the rear.
- **Dequeue**: Remove an element from the front.
- **Peek**: View the front element without removing it.
- **isFull / isEmpty**: Check queue status.

---

## Circular Queue

### Characteristics:
- A more efficient version of the linear queue.
- Connects the last position of the array back to the first position — forming a **circular structure**.
- Solves the wasted space problem in linear queues.

### How It Works:
- Rear wraps to the beginning of the array if there is available space.
- Positions are calculated using modulo operation:  
  `rear = (rear + 1) % size`

### Operations:
- **Enqueue**: Add an element at the rear (wraps if needed).
- **Dequeue**: Remove an element from the front (wraps if needed).
- **Peek**: View the front element.
- **isFull / isEmpty**: More complex conditions due to circular nature.

---

## Files

| File Name              | Description                            |
|------------------------|----------------------------------------|
| `Queue.c`              | C program for Linear and Circular Queue|

---

## How to Compile and Run

Use GCC or any C compiler:

```
gcc Queue.c
./a.out
```
---
