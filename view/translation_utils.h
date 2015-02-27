#ifndef VIEW_TRANSLATION_UTILS_H
#define VIEW_TRANSLATION_UTILS_H

#include <QString>
#include <string>
#include <QTranslator>

class TranslationUtils {
public:
  static QString translate(const std::string &context, const std::string &key);
  static bool loadTranslation(QString lang);

private:
  static QTranslator m_translator;
};

#endif
