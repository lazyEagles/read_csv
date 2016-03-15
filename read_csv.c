
#include "read_csv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

void read_data(FILE *fd, struct meter *meter, long size_lines, long size_columns) {
  int i;
  char line[LINE_LENGTH];
  char *column[COLUMN_LENGTH];

  fgets(line, LINE_LENGTH, fd);
  for (i = 1; i < size_lines; i++) {
    fgets(line, LINE_LENGTH, fd);
    read_column(line, column, size_columns);
    write_data_to_meter(&meter[i-1], column);
  }
}

void read_column(char *line, char *column[], long size_columns) {
  long i;
  i = 0;
  column[i] = strtok(line, ",\"\n");
  while (i < size_columns && column[i]) {
    i++;
    column[i] = strtok(NULL, ",\"\n");
  }
}

void write_data_to_meter(struct meter *meter, char *column[]) {
  meter->id = atol(column[0]);
  strncpy(meter->meter_point, column[1], METER_POINT_LENGTH);
  strncpy(meter->transformer.label, column[2], TRANSFORMER_LABEL_LENGTH);
  meter->transformer.latitude = strncmp(column[3], "NA", 2) ? atof(column[3]) : DBL_MAX;
  meter->transformer.longitude = strncmp(column[4], "NA", 2) ? atof(column[4]) : DBL_MAX;
  meter->latitude = strncmp(column[5], "NA", 2) ? atof(column[5]) : DBL_MAX;
  meter->longitude = strncmp(column[6], "NA", 2) ? atof(column[6]) : DBL_MAX;
  meter->transformer.location_type = strncmp(column[7], "NULL", 4) ? atol(column[7]) : UNKOWN;
  meter->location_type = strncmp(column[8], "NULL", 4) ? atol(column[8]) : UNKOWN;
  meter->barrier_type = strncmp(column[9], "NULL", 4) ? atol(column[9]) : UNKOWN;
  meter->barrier_metal_type = strncmp(column[10], "NULL", 4) ? atol(column[10]) : UNKOWN;
  meter->metalbox_type = strncmp(column[12], "NULL", 4) ? atol(column[12]) : UNKOWN;
  meter->building_usage_type = strncmp(column[13], "NULL", 4) ? atol(column[13]) : UNKOWN;

}
