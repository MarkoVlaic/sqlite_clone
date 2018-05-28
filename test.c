#include <stdio.h>
#include <stdint.h>

#define NUM 14

void f(uint32_t x) {
  printf("%d\n", x%NUM);
}

int main() {
  int i;

  for(i=0;i<5;i++){
    f(i);
  }

  return 0;
}
