#ifndef INPUT_BUFFER
#define INPUT_BUFFER

#include <stddef.h>
#include <sys/types.h>

struct InputBuffer_t {
  char* buffer;
  size_t input_length;
  ssize_t buffer_length;
};
typedef struct InputBuffer_t InputBuffer;

InputBuffer* new_input_buffer();
void read_input(InputBuffer*);
void print_prompt();

#endif
