#include <string>
#include <vector>
#include <utility>

class Vehicle {
  std::string make;
  std::string model;
  std::pair<int,int> size;
  int year;

public:
  Vehicle(std::string make, std::string model, int year);
  std::string getMake();
  std::string getModel();
  int getYear();
  std::pair<int,int> getSize();
};

class ParkingSpot {
  Vehicle* vehicle;
  std::pair<int,int> size;
  int row;
  int spotNum;

public:
  ParkingSpot(std::pair<int,int> size, int row, int spotNum);
  void park(Vehicle* v) { vehicle = v; }
  std::pair<int,int> getSize();
};

class Level {
  int floor;
  int availableSpots;
  std::vector<ParkingSpot*> parkingSpots;

public:
  Level(int numSpots, int floor);
  ParkingSpot* getAvailableSpot();
  int numAvailableSpots();
};

class ParkingGarage {
  std::vector<Level*> levels;

public:
  ParkingGarage(std::vector<Level*> levels);
  void park(Vehicle* v) {
    for (Level* level : levels) {
      ParkingSpot* spot = level->getAvailableSpot();
      if (spot) {
	spot->park(v);
	break;
      }
    }
  }
};
