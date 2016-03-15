
#define ID_LEN 128

enum node_type {
  CONCENTRATOR,
  METER
};

enum location_type {

};

enum building_type {

};

enum link_state {
  WITH,
  WITHOUT,
  UNKNOWN
}

struct node {
  char id[ID_LEN];
  enum node_type type;
  double latitude;
  double longitude;
  double pos_x;
  double pos_y;
  enum location_type location_type;
  enum building_type building_type;   
};

struct link {
  char node_id[ID_LEN];
  struct link *next;
  struct link *head;
};

struct pair {
  int node_head_index;
  int node_tail_index;
  double distance;
  enum link_state link_state;
};
