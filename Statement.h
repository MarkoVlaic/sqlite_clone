#ifndef STATEMENT
#define STATEMENT

#include "InputBuffer.h"
#include "Row.h"
#include "Table.h"

enum PrepareResult_t {
  PREPARE_SUCCESS,
  PREPARE_FAILURE,
  PREPARE_SYNTAX_ERROR
};
typedef enum PrepareResult_t PrepareResult;

enum StatementType_t {
  STATEMENT_INSERT,
  STATEMENT_SELECT
};
typedef enum StatementType_t StatementType;

enum ExecuteResult_t {
  EXECUTE_TABLE_FULL,
  EXECUTE_SUCCESS
};
typedef enum ExecuteResult_t ExecuteResult;

struct Statement_t {
  StatementType type;
  Row row_to_insert;
};
typedef struct Statement_t Statement;

PrepareResult prepare_statement(InputBuffer*, Statement*);

ExecuteResult execute_insert(Statement*, Table*);
ExecuteResult execute_select(Statement*, Table*);

ExecuteResult execute_statement(Statement*, Table*);

#endif
