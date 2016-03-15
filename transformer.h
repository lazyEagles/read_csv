
#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#define TRANSFORMER_LABEL_LENGTH 16

enum transformer_location_type {
  INDOOR_UNDERGROUND = 1,
  INDOOR_FLOOR = 2,
  OUTDOOR_GROUND = 3,
  OUTDOOR_POLE = 4
};

struct transformer {
  char label[TRANSFORMER_LABEL_LENGTH];
  double latitude;
  double longitude;
  enum transformer_location_type location_type;
  double pos_x;
  double pos_y;
  
};
#endif
