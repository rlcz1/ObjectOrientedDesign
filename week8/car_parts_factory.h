#ifndef _CAR_PARTS_FACTORY_H_
#define _CAR_PARTS_FACTORY_H_

#include "door.h"
#include "wheel.h"
#include "roof.h"

class CarPartsFactory {
 public:
  virtual Part* CreateDoor() const = 0;
  virtual Part* CreateWheel() const = 0;
  virtual Part* CreateRoof() const = 0;
};

#endif
