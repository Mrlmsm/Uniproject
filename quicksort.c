#include <stdio.h>
#include <stdlib.h>


int comparInt(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

static size_t partition(void *base, 
	                    size_t p, 
						size_t r, 
	                    size_t size, 
						int (*compar)(const void *, const void *)){

	char *x = (char *)base + r * size; 
	
	size_t i = p - 1;

	for (size_t j = p; j <= r-1; j++){
		if(compar((char*)base+j*size, x) <= 0){
			i++;
			for (size_t k = 0; k < size; k++){
				char tmp = *((char*)base+i*size+k);
				*((char*)base+i*size+k) = *((char*)base+j*size+k);
				*((char*)base+j*size+k) = tmp;
			}
		}
	}

	for (size_t k = 0; k < size; k++){
		char tmp = *((char*)base+(i+1)*size+k);
		*((char*)base+(i+1)*size+k) = *((char*)base+r*size+k);
		*((char*)base+r*size+k) = tmp;
	}

	return i+1;
}

static void quicksort(void *base, 
	                  size_t p, 
					  size_t r, 
					  size_t size,
					  size_t k, 
	                  int (*compar)(const void *, const void *)){

    	if(p>=r) 
		return;
    size_t q = partition(base, p, r, size, compar);
	if(q > p)	
    quicksort(base, p, q - 1, size, k, compar);
	if(q < r)
    quicksort(base, q + 1, r, size, k, compar);
}

int main(){
	int a[5] = {9, 10, 5, 2, 7};
	quicksort(a, 0, 4, sizeof(int), 10, comparInt);
	for(int f = 0; f < 6; f++){
		printf("%d\n", a[f]);
	}
	return 0;
}
