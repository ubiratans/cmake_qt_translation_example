#include "view/main_screen.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QLabel>
#include <QString>
#include <QRadioButton>

#include <QTranslator>

#include "core/core_strings.h"
#include "view/translation_utils.h"

MainScreen::MainScreen(QWidget *parent) {
  bool ret = TranslationUtils::loadTranslation(QString("pt_BR"));

  m_main_layout = new QVBoxLayout(this);
  m_layout_button = new QHBoxLayout(this);

  m_text_edit = new QTextEdit("", this);
  m_text_edit->setReadOnly(true);

  m_button_br = new QRadioButton("pt_BR", this);
  m_button_de = new QRadioButton("de_DE", this);
  m_button_en = new QRadioButton("en_US", this);

  m_button_br->setChecked(true);

  connect( m_button_br, SIGNAL( clicked() ), this, SLOT( setTranslationLanguage()) );
  connect( m_button_de, SIGNAL( clicked() ), this, SLOT( setTranslationLanguage()) );
  connect( m_button_en, SIGNAL( clicked() ), this, SLOT( setTranslationLanguage()) );

  m_layout_button->addWidget(m_button_br);
  m_layout_button->addWidget(m_button_de);
  m_layout_button->addWidget(m_button_en);

  m_main_layout->addLayout(m_layout_button);
  m_main_layout->addWidget(m_text_edit);

  setLayout(m_main_layout);
  setMinimumSize(400, 300);

  setTextEditContent();
}

MainScreen::~MainScreen() {
  delete m_main_layout;
  delete m_text_edit;
  delete m_layout_button;
  delete m_button_br;
  delete m_button_de;
  delete m_button_en;
}

void MainScreen::setTextEditContent() {
  QString content = TranslationUtils::translate(kCoreStringsContext, kTkCoreStringsContact) + "\n"
                    + TranslationUtils::translate(kCoreStringsContext, kTkCoreStringsContactName) + "\n"
                    + TranslationUtils::translate(kCoreStringsContext, kTkCoreStringsPhoneNumber) + "\n"
                    + TranslationUtils::translate(kCoreStringsContext, kTkCoreStringsPhoneNumberType);

  m_text_edit->setText(content);
}

void MainScreen::setTranslationLanguage() {
  QString lang = "";

  if (QObject::sender() != nullptr) {
    QRadioButton *button = dynamic_cast< QRadioButton* >(QObject::sender());

    if (button != nullptr) {
      lang = button->text();
    }
  }

  TranslationUtils::loadTranslation(lang);
  setTextEditContent();
}
