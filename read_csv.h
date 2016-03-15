
#ifndef READ_CSV_H
#define READ_CSV_H

#define LINE_LENGTH 256
#define COLUMN_LENGTH 32

void read_data(FILE *fd, struct meter *meter, long size_lines, long size_columns);
void read_column(char *line, char *column[], long size_columns);
void write_data_to_meter(struct meter *meter, char *column[]);


#endif
