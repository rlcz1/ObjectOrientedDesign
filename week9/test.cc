#include "gtest/gtest.h"
#include "car.h"
#include "car_builder.h"
#include "car_parts_factory.h"
#include "part.h"
#include "door.h"
#include "hyundai_parts_factory.h"
#include "kia_parts_factory.h"
#include "wheel.h"
#include "roof.h"

class CarTest : public ::testing::Test {
 public :
  CarTest() : car() {}
 protected:
  void SetUp() override {}
  void TearDown() override {}
  Car* car;
  CarPartsFactory* car_factory;
};

TEST_F(CarTest, car_test1) {
  ASSERT_DEATH({
  car_factory = KiaPartsFactory::GetInstance();
    CarBuilder builder(car_factory);
    Car* my_car = builder.CreateDoor()
      .CreateRoof()
      .CreateWheel()
      .CreateWheel()
      .SetColor("green")
      .SetColor("red")
      .Build();
  }, "Duplicated Parts Creation: Wheel");
}

TEST_F(CarTest, car_test2) {
  ASSERT_DEATH({
  car_factory = KiaPartsFactory::GetInstance();
    CarBuilder builder(car_factory);
    Car* my_car = builder.CreateDoor()
      .CreateRoof()
      .CreateWheel()
      .CreateWheel()
      .SetColor("green")
      .Build();
  }, "Duplicated Parts Creation: Wheel");
}

TEST_F(CarTest, car_roof_test) {
  car_factory = KiaPartsFactory::GetInstance();
  CarBuilder builder(car_factory);
  builder.CreateRoof();
  ASSERT_DEATH(builder.CreateRoof(), "Duplicated Parts Creation: Roof");
}

TEST_F(CarTest, car_roof_test2) {
  car_factory = KiaPartsFactory::GetInstance();
  CarBuilder builder(car_factory);
  builder.CreateWheel();
  ASSERT_DEATH(builder.CreateWheel(), "Duplicated Parts Creation: Wheel");
}

TEST_F(CarTest, car_roof_test3) {
  car_factory = KiaPartsFactory::GetInstance();
  CarBuilder builder(car_factory);
  builder.CreateDoor();
  ASSERT_DEATH(builder.CreateDoor(), "Duplicated Parts Creation: Door");
}

TEST_F(CarTest, car_roof_test4) {
  car_factory = HyundaiPartsFactory::GetInstance();
  CarBuilder builder(car_factory);
  builder.CreateDoor();
  ASSERT_DEATH(builder.CreateDoor(), "Duplicated Parts Creation: Door");
}
