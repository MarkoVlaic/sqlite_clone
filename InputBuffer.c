#include "InputBuffer.h"

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

InputBuffer* new_input_buffer() {
  InputBuffer* ret = malloc(sizeof(InputBuffer));

  ret->buffer = NULL;
  ret->buffer_length = 0;
  ret->input_length = 0;

  return ret;
}

void read_input(InputBuffer* input_buffer) {
  input_buffer->input_length = getline( &(input_buffer->buffer), &(input_buffer->buffer_length), stdin );

  input_buffer->buffer[input_buffer->input_length-1] = 0;
}

void print_prompt() {
  printf("db > ");
}
