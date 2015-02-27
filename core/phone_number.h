#ifndef CORE_PHONE_NUMBER_H
#define CORE_PHONE_NUMBER_H

#include <string>

enum class PhoneNumberType : char {
  Residential,
  Mobile,
  Work,
  Other
};

class PhoneNumber {
public:
  PhoneNumber();
  PhoneNumber(std::string &number, PhoneNumberType type);

  void setNumber(std::string &number);
  std::string getNumber();

  void setType(PhoneNumberType type);
  PhoneNumberType getType();

private:
  PhoneNumberType m_type;
  std::string m_number;
};

#endif
