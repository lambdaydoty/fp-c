#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef enum { false = 0, true = 1 } bool;
typedef int K_T;
typedef char * V_T;
typedef struct {
	K_T key;
	V_T value;
} Node;

Node a[MAX + 1];

/**
 * key: 999
 *
 *  ^ 0 | { key: 999, value: NULL  } <-- the sentinal record
 *  | 1 | { key:  23, value: ...   }
 *  | 2 | { key:  24, value: ...   }
 *  | 3 | { key:  29, value: ...   }
 *  | ..
 *  | N | { key:  33, value: ...   }
 */

int N = 0;

void seq_init () {
	N = 0;
}

bool key_equal (K_T key1, K_T key2) {
	return key1 == key2;
}

// :: K_T -> V_T|NULL
V_T seq_search (K_T key) {
	/* Search backward */
	a[0].key = key;
	a[0].value = NULL;
	int i = N;
	while (!key_equal(a[i].key, key)) {
		i--;
	}
	return a[i].value;
}

void seq_insert (K_T key, V_T value) {
	N++;
	if (N == MAX + 1) abort();
	a[N].key = key;
	a[N].value = value;
}

int main () {
	seq_insert(0, "alice");
	seq_insert(13, "bob");
	seq_insert(999, "carol");

	int key = 99;
	printf("key == %d, value == %s\n",
			key,
			seq_search(key));
	return 0;
}
