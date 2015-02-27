#include "core/contact.h"

Contact::Contact() : m_name("") {
  m_date_birth = QDate::currentDate();
}

Contact::Contact(std::string &name, QDate &date) : m_name(name), m_date_birth(date) {

}

QDate Contact::getBirthDate() {
  return m_date_birth;
}

void Contact::setBirthDate(QDate &date) {
  m_date_birth = date;
}

std::string Contact::getName() {
  return m_name;
}

void Contact::setName(std::string &name) {
  m_name = name;
}

void Contact::addPhoneNumber(std::string &number, PhoneNumberType type) {
  m_phone_numbers.push_back(PhoneNumber(number, type));
}

void Contact::setPhoneNumber(uint32_t index, std::string &number, PhoneNumberType type) {
  if (m_phone_numbers.size() > index) {
    m_phone_numbers[index].setNumber(number);
    m_phone_numbers[index].setType(type);
  }
}

bool Contact::removePhoneNumber(uint32_t index) {
  if (m_phone_numbers.size() > index) {
    m_phone_numbers.erase(m_phone_numbers.begin() + index);

    return true;
  }

  return false;
}

uint32_t Contact::getAge() {
  QDate current = QDate::currentDate();

  return m_date_birth.daysTo(current) / 365.25;
}

std::vector<PhoneNumber> Contact::getPhoneNumbers() {
  return m_phone_numbers;
}
