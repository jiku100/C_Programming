#include <stdio.h>

void print(int* array, int size);
void arraymerge(int* a, int asize, int* b, int bsize, int* c);

int main(void) {
    int a[] = { 1, 2, 5, 7, 9, 14 };
    int asize = sizeof(a) / sizeof(int);
    int b[] = { 2, 3, 6, 8, 13 };
    int bsize = sizeof(b) / sizeof(int);
    int c[20];
    int csize = asize + bsize;
    printf("배열 a[] = "); print(a, asize); printf("\n\n");
    printf("배열 b[] = "); print(b, bsize); printf("\n\n");
    arraymerge(a, asize, b, bsize, c);
    printf("배열 c[] = "); print(c, csize); printf("\n");
    return 0;
}

void print(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}
void arraymerge(int* a, int asize, int* b, int bsize, int* c) { 
    int i = 0, j = 0, k = 0;    
    while (i < asize && j < bsize) {  
        if (a[i] < b[j]) { 
            c[k++] = a[i++];
        }
        else {
            c[k++] = b[j++];
        }
    }
    if (i < asize && j >= bsize) {
        for (i; i < asize; i++) {
            c[k++] = a[i]; 
        }
    }
    else if (j < bsize && i >= asize) { 
        for (j; j < bsize; j++) {
            c[k++] = b[j]; 
        }
    }
}
