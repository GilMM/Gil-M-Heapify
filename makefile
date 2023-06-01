heapify:  heapify.o
	gcc -g heapify.c -o myheapify
myheapify.o:  heapify.c
	gcc -c heapify.c -o myheapify.o
