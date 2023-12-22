#include "car.h"

Car::Car(Part* door, Part* wheel, Part* roof, std::string color)
  : door_(door), wheel_(wheel), roof_(roof), color_(color) {}

Car::Car(const Car& car) {
  door_ = new Door(car.door_->factory_name());
  wheel_ = new Wheel(car.wheel_->factory_name());
  roof_ = new Roof(car.roof_->factory_name());
  color_ = car.color_;
}

Car& Car::operator=(const Car& car) {
  if (door_ != nullptr) delete door_;
  door_ = new Door(car.door_->factory_name());

  if (wheel_ != nullptr) delete wheel_;
  wheel_ = new Wheel(car.wheel_->factory_name());

  if (roof_ != nullptr) delete roof_;
  roof_ = new Roof(car.roof_->factory_name());

  return *this;
}

Car::~Car() {
  if (door_ != nullptr) delete door_;
  if (wheel_ != nullptr) delete wheel_;
  if (roof_ != nullptr) delete roof_;
}

std::string Car::GetSpec() const {
  std::string ret = "Car(";

  Part* parts[3] = {door_, wheel_, roof_};
  for (Part* part : parts) {
    if (part == nullptr) {
      continue;
    }
      ret += part->GetInfo();
      ret += ", ";
  }
  ret += color_;
  ret += ")";

  return ret;
}
