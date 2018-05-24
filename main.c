#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "InputBuffer.h"
#include "MetaCommand.h"

int main() {

  InputBuffer* input_buffer = new_input_buffer();

  while(true){
    print_prompt();
    read_input(input_buffer);

    /*TODO: Process meta commands*/

    if(input_buffer->buffer[0] == '.'){
      switch (process_meta_command(input_buffer)){
        case META_SUCCESS:continue;
        case META_FAILURE:
          printf("Unknown meta command %s\n", input_buffer->buffer);
          continue;
      }
    }

    /*TODO: Process statements*/


  }

  return 0;
}
