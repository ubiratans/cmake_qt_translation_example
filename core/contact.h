#ifndef CORE_CONTACT_H
#define CORE_CONTACT_H

#include <cstdint>
#include <string>
#include <vector>

#include <QDate>

#include "core/phone_number.h"

class Contact {
protected:
  Contact();
  Contact(std::string &name, QDate &date);

  QDate getBirthDate();
  void setBirthDate(QDate &date);

  std::string getName();
  void setName(std::string &name);

  void addPhoneNumber(std::string &number, PhoneNumberType type);
  void setPhoneNumber(uint32_t index, std::string &number, PhoneNumberType type);
  bool removePhoneNumber(uint32_t index);

  uint32_t getAge();

  std::vector< PhoneNumber > getPhoneNumbers();

private:
  QDate m_date_birth;

  std::string m_name;
  std::vector< PhoneNumber > m_phone_numbers;
};

#endif
