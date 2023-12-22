#include "float_accumulator.h"

float_accumulator::Accumulator::Accumulator(float acc) {
  acc_ = acc;
}

void float_accumulator::Accumulator::Add(float x) {
  acc_ += x;
}

void float_accumulator::Accumulator::Sub(float x) {
  acc_ -= x;
}

void float_accumulator::Accumulator::Mult(float x) {
  acc_ *= x;
}

void float_accumulator::Accumulator::Div(float x) {
  assert(x != 0 && "Divide-by-zero");
  acc_ /= x;
}

int float_accumulator::Accumulator::acc() {
  return acc_;
}
