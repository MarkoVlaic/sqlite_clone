#include "MetaCommand.h"

#include <string.h>
#include <stdlib.h>

MetaCommandResult process_meta_command(InputBuffer* input_buffer) {
  if(strcmp(input_buffer->buffer, ".exit") == 0){
    exit(EXIT_SUCCESS);
  }

  return META_FAILURE;
}
