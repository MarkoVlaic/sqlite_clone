#ifndef ROW
#define ROW

#include <stdint.h>
#include <stdio.h>

#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255


//Structure containing info about single row in a table
struct Row_t {
  uint32_t id;
  char username[COLUMN_USERNAME_SIZE+1];
  char email[COLUMN_EMAIL_SIZE+1];
};
typedef struct Row_t Row;

void init_row_units();
uint32_t get_row_size();
void serialize_row(Row*, void*);
void deserialize_row(void*, Row*);
void print_row(Row*);

#endif
