#include "car_builder.h"

CarBuilder::CarBuilder(const CarPartsFactory* factory) : factory_(factory) {
  door_ = nullptr;
  wheel_ = nullptr;
  roof_ = nullptr;
  color_ = "";
}

CarBuilder& CarBuilder::CreateDoor() {
  assert(door_ == nullptr && "Duplicated Parts Creation: Door");
  door_ = factory_->CreateDoor();
  return *this;
}

CarBuilder& CarBuilder::CreateWheel() {
  assert(wheel_ == nullptr && "Duplicated Parts Creation: Wheel");
  wheel_ = factory_->CreateWheel();
  return *this;
}

CarBuilder& CarBuilder::CreateRoof() {
  assert(roof_ == nullptr && "Duplicated Parts Creation: Roof");
  roof_ = factory_->CreateRoof();
  return *this;
}

CarBuilder& CarBuilder::SetColor(std::string color) {
  color_ = color;
  return *this;
}

Car* CarBuilder::Build() {
  Car* car_ptr = new Car(door_, wheel_, roof_, color_);
  return car_ptr;
}
