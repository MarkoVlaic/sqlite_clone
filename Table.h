#ifndef TABLE
#define TABLE

#include "Row.h"

#define ROW_SIZE get_row_size()

#define PAGE_SIZE 4096
#define TABLE_MAX_PAGES 100
#define ROWS_PER_PAGE PAGE_SIZE/ROW_SIZE
#define TABLE_MAX_ROWS ROWS_PER_PAGE * TABLE_MAX_PAGES

struct Table_t {
  void* pages[TABLE_MAX_PAGES];
  uint32_t num_rows;
};
typedef struct Table_t Table;

void* row_slot(Table*, uint32_t);
Table* new_table();

#endif
