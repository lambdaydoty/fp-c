#include <stdio.h>

int numJewelsInStones(char * J, char * S) {
  int count = 0;
  for (int s = 0; S[s] != '\0'; ++s) {
    for (int j = 0; J[j] != '\0'; ++j) {
      if (S[s] == J[j]) count = count + 1;
    }
  }
  return count;
}

int main(int argc, char *argv[]) {
  printf("%d\n", numJewelsInStones("aA", "aAAbbbb"));
  return 0;
}
