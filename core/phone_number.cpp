#include "core/phone_number.h"

PhoneNumber::PhoneNumber() : m_type(PhoneNumberType::Mobile), m_number("") {
}

PhoneNumber::PhoneNumber(std::string &number, PhoneNumberType type) : m_type(type), m_number(number) {
}

void PhoneNumber::setNumber(std::string &number) {
  m_number = number;
}

std::string PhoneNumber::getNumber() {
  return m_number;
}

void PhoneNumber::setType(PhoneNumberType type) {
  m_type = type;
}

PhoneNumberType PhoneNumber::getType() {
  return m_type;
}


