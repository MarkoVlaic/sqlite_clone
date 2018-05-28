#include "Row.h"
#define size_of_attribute(Struct, Attribute) sizeof(((Struct*)0)->Attribute)

#include <string.h>

uint32_t ID_SIZE;
uint32_t USERNAME_SIZE;
uint32_t EMAIL_SIZE;

uint32_t ID_OFFSET;
uint32_t USERNAME_OFFSET;
uint32_t EMAIL_OFFSET;
uint32_t ROW_SIZE;

void init_row_units() {
  ID_SIZE = size_of_attribute(Row, id);
  USERNAME_SIZE = size_of_attribute(Row, username);
  EMAIL_SIZE = size_of_attribute(Row, email);

  ID_OFFSET = 0;
  USERNAME_OFFSET = ID_OFFSET + ID_SIZE;
  EMAIL_OFFSET = USERNAME_OFFSET + USERNAME_SIZE;
  ROW_SIZE = ID_SIZE + USERNAME_SIZE + EMAIL_SIZE;
}

uint32_t get_row_size() {
  init_row_units();
  return ROW_SIZE;
}

void serialize_row(Row* source, void* destination) {
  memcpy(destination + ID_OFFSET, &(source->id), ID_SIZE);
  memcpy(destination + USERNAME_OFFSET, &(source->username), USERNAME_SIZE);
  memcpy(destination + EMAIL_OFFSET, &(source->email), EMAIL_SIZE);
}

void deserialize_row(void* source, Row* destination) {
  memcpy(&(destination->id), source+ID_OFFSET, ID_SIZE);
  memcpy(&(destination->username), source+USERNAME_OFFSET, USERNAME_SIZE);
  memcpy(&(destination->email), source+EMAIL_OFFSET, EMAIL_SIZE);
}

void print_row(Row* row) {
  printf("%d %s %s\n", row->id, row->username, row->email);
}
