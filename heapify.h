#ifndef __HEAPIFY_H
#define __HEAPIFY_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SIZE 256
void q1();
void maxHeapify(int arr[], int size, int rootIndex);
void buildHeap(int arr[], int size);
void printHeap(int arr[], int size);
void heapInsert(int arr[], int *pSize);
void extractMax(int arr[], int *pSize);
void extractMin(int arr[], int *pSize);
int findIndexOfMin(int arr[], int size, int rootIndex);
void heapDelete(int arr[], int *pSize, int index);
void prepareHeapDelete(int arr[], int *pSize);
void heapSort(int arr[], int size);
void printSpaces(int numSpaces);

#endif
