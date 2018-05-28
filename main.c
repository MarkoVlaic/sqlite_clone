#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "InputBuffer.h"
#include "MetaCommand.h"
#include "Statement.h"
#include "Row.h"
#include "Table.h"

int main() {

  Table* table = new_table();
  InputBuffer* input_buffer = new_input_buffer();

  init_row_units();

  while(true){
    print_prompt();
    read_input(input_buffer);


    //Process meta commands
    if(input_buffer->buffer[0] == '.'){
      switch (process_meta_command(input_buffer)){
        case META_SUCCESS:continue;
        case META_FAILURE:
          printf("Unknown meta command %s\n", input_buffer->buffer);
          continue;
      }
    }

    //Process statements
    Statement statement;
    switch (prepare_statement(input_buffer, &statement)) {
      case PREPARE_SUCCESS:
        break;
      case PREPARE_FAILURE:
        printf("Unknown statement %s\n", input_buffer->buffer);
        continue;
      case PREPARE_SYNTAX_ERROR:
        printf("SyntaxError in %s\n", input_buffer->buffer);
        continue;
      case PREPARE_STRING_TOO_LONG:
        printf("String in %s is too long\n", input_buffer->buffer);
        continue;
      case PREPARE_NEGATIVE_ID:
        printf("Id must be positive\n");
        continue;
    }

    switch (execute_statement(&statement, table)) {
      case EXECUTE_SUCCESS:
        printf("Executed\n");
        break;
      case EXECUTE_TABLE_FULL:
        printf("Cannot insert into the database\n");
        break;
    }

  }

  return 0;
}
