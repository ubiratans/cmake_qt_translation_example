#include "view/translation_utils.h"

#include <QCoreApplication>

QTranslator TranslationUtils::m_translator;

QString TranslationUtils::translate(const std::string &context, const std::string &key) {
  return QCoreApplication::translate(context.c_str(), key.c_str());
}

bool TranslationUtils::loadTranslation(QString lang) {
  QString file = "lang/translation_package_" + lang;

  bool status = m_translator.load(file);

  return status && QCoreApplication::installTranslator(&m_translator);
}
