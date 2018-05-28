#include "Statement.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

ExecuteResult execute_insert(Statement* statement, Table* table) {
  /*
    param: statement - struct object describing the input
    param: table - table to insert the row to

    returns: EXECUTE_TABLE_FULL if no more rows fit into the table
             EXECUTE_SUCCESS otherwise

    serializes statement->row_to_insert into memory
  */

  if(table->num_rows >= TABLE_MAX_ROWS)return EXECUTE_TABLE_FULL;

  Row* row_to_insert = &(statement->row_to_insert);

  serialize_row(row_to_insert, row_slot(table, table->num_rows));
  table->num_rows++;

  return EXECUTE_SUCCESS;
}

ExecuteResult execute_select(Statement* statement, Table* table) {
  //printf("Selecting\n");
  Row row;

  for(uint32_t i=0;i<table->num_rows;i++) {
    deserialize_row(row_slot(table, i), &row);
    print_row(&row);
  }

  return EXECUTE_SUCCESS;
}

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement) {
  /*
    param: input_buffer - struct containing one line of input
    param: statement - statement to modify

    returns: PREPARE_SYNTAX_ERROR if the command syntax is wrong
             PREPARE_FAILURE if no command matches the input
             PREPARE_SUCCESS otherwise

    compares input_buffer->buffer to list of supported commands and saves the statement type into statement->type accordingly
  */


  if(strncmp(input_buffer->buffer, "insert", 6) == 0){
    statement->type = STATEMENT_INSERT;

    //int args_assigned = sscanf(input_buffer->buffer, "insert %d %s %s", &(statement->row_to_insert.id), &(statement->row_to_insert.username), &(statement->row_to_insert.email));
    //if(args_assigned < 3)return PREPARE_SYNTAX_ERROR;

    char* keyword = strtok(input_buffer->buffer, " ");
    char* id_string = strtok(NULL, " ");
    char* username = strtok(NULL, " ");
    char* email = strtok(NULL, " ");

    if(id_string == NULL || username == NULL || email == NULL)return PREPARE_SYNTAX_ERROR;

    int id = atoi(id_string);

    if(id < 0)return PREPARE_NEGATIVE_ID;

    if(strlen(username) > COLUMN_USERNAME_SIZE) return PREPARE_STRING_TOO_LONG;
    if(strlen(email) > COLUMN_EMAIL_SIZE) return PREPARE_STRING_TOO_LONG;

    statement->row_to_insert.id = id;
    strcpy(statement->row_to_insert.username, username);
    strcpy(statement->row_to_insert.email, email);

    return PREPARE_SUCCESS;
  }
  else if(strncmp(input_buffer->buffer, "select", 6) == 0){
    statement->type = STATEMENT_SELECT;
    return PREPARE_SUCCESS;
  }

  return PREPARE_FAILURE;
}

ExecuteResult execute_statement(Statement* statement, Table* table) {
  /*
    param: statement - statement to execute
    param: table - table to execute the statement on

    calls an execute function according to the statement type
  */

  switch (statement->type) {
    case STATEMENT_SELECT:
      return execute_select(statement, table);
      break;
    case STATEMENT_INSERT:
      return execute_insert(statement, table);
      break;
  }
}
