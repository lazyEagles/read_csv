
#ifndef METER_H
#define METER_H

#include "transformer.h"

#define METER_ID_LENGTH 16
#define METER_POINT_LENGTH 64

enum meter_location_type {
  INDOOR_UNDERGROUND = 1,
  INDOOR_FLOOR = 2,
  OUTDOOR_INOVERHANG = 3,
  OUTDOOR_OUTOVERHANG = 4,
  OUTDOOR_POLE = 5,
  UNKOWN = 6
};

enum barrier_type {
  WITH_BARRIER = 0,
  WITHOUT_BARRIER = 1,
  UNKOWN = 2
};

enum barrier_metal_type {
  METAL = 0,
  NOT_METAL = 1,
  UNKOWN = 2
};

enum metalbox_type {
  WITHOUT_METALBOX = 0,
  WITH_METALBOX = 1,
  UNKOWN = 2
};

enum building_usage_type {
  APARTMENT_MANSION = 1,
  HOUSE = 2,
  STORE_FACTORY = 3,
  COMMERCIAL_BUILDING = 4,
  FACTORY_OFFICE = 5,
  FARM = 6,
  FISH_FARM = 7,
  UTILITY = 8,
  OTHERS = 100,
  UNKOWN = 9
  
};

struct meter {
  long id;
  char meter_point[METER_POINT_LENGTH];
  struct transformer transformer;
  double latitude;
  double longitude;
  enum meter_location_type location_type; 
  enum barrier_type barrier_type;
  enum barrier_metal_type barrier_metal_type;
  enum metalbox_type metalbox_type;
  enum building_usage_type building_usage_type;
}


#endif
