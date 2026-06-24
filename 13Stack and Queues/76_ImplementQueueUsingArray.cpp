#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Implement queue using array LINK: https://www.geeksforgeeks.org/problems/implement-queue-using-array/1

class myQueue {

  public:
    vector<int> arr;
    int a, b, n, size;
    
    myQueue(int n) {
        // Define Data Structures
        a = 0, b = 0, size = 0;
        arr.resize(n);
        this->n = n;
    }

    bool isEmpty() {
        // check if the queue is empty
        return size == 0;
    }

    bool isFull() {
        // check if the queue is full
        return size == n;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(isFull()) return;
        
        arr[b] = x;
        b = (b + 1) % n;
        
        size++;
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(isEmpty()) return;
        
        a = (a + 1) % n;
        
        size--;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[a];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[(b - 1 + n) % n];
    }
};