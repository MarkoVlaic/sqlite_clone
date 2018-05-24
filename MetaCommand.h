#ifndef META_COMMAND
#define META_COMMAND

#include "InputBuffer.h"

enum MetaCommandResult_t {
  META_SUCCESS, META_FAILURE
};
typedef enum MetaCommandResult_t MetaCommandResult;

MetaCommandResult process_meta_command(InputBuffer* input_buffer);

#endif
