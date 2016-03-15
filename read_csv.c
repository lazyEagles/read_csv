
#include "read_csv.h"
#include <stdio.h>

void read_data(FILE *fd, struct meter *meter, long size_lines) {
  int i;
  char line[LINE_LENGTH];

  fgets(line, LINE_LENGTH, fd);
  for (i = 1; i < size_lines; i++) {
    fgets(line, LINE_LENGTH, fd);
  }
}
