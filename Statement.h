#ifndef STATEMENT
#define STATEMENT

#include "InputBuffer.h"

enum PrepareResult_t {
  PREPARE_SUCCESS,
  PREPARE_FAILURE
};
typedef enum PrepareResult_t PrepareResult;

enum StatementType_t {
  STATEMENT_INSERT,
  STATEMENT_SELECT
};
typedef enum StatementType_t StatementType;

struct Statement_t {
  StatementType type;
};
typedef struct Statement_t Statement;

PrepareResult prepare_statement(InputBuffer*, Statement*);
void execute_statement(Statement*);

#endif
