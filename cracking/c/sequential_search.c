#define maxN 10000

/**
 * Array Implementation
 */
struct node {
  int key;
  int info;
};
struct node a[maxN + 1];
int N;
void seq_init () { N = 0; }
void seq_insert (int k, int info) {
  ++N;
  a[N].key = k;
  a[N].info = info;
}
int seq_search (int k) {
  a[0].key = k; // sentinal
  a[0].info = -1;
  int n = N + 1;
  while (a[--n].key != k);
  return a[n].info;
}
