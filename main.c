#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "InputBuffer.h"

int main() {

  InputBuffer* input_buffer = new_input_buffer();

  while(true){
    print_prompt();
    read_input(input_buffer);

    if(strcmp(input_buffer->buffer, ".exit") == 0)exit(EXIT_SUCCESS);
    else printf("Unknown command %s\n", input_buffer->buffer);
  }

  return 0;
}
