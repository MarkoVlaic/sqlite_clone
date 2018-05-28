#include "Table.h"
#include "Row.h"

#include <stdlib.h>

uint32_t mod(uint32_t a, uint32_t b) {
  return a - b*(a/b);
}

void* row_slot(Table* table, uint32_t row_num) {

  uint32_t page_num = row_num/ROWS_PER_PAGE;
  void* page = table->pages[page_num];

  if(!page) {
    page = table->pages[page_num] = malloc(PAGE_SIZE);
  }

  uint32_t row_offset = mod(row_num, ROWS_PER_PAGE);
  uint32_t byte_offset = row_offset * get_row_size();

  return page + byte_offset;
}

Table* new_table() {
  Table* table = malloc(sizeof(table));

  table->num_rows = 0;

  return table;
}
