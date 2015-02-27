#ifndef VIEW_MAIN_SCREEN_H
#define VIEW_MAIN_SCREEN_H

#include <QWidget>

class QLabel;
class QTextEdit;
class QVBoxLayout;
class QHBoxLayout;
class QRadioButton;

class MainScreen : public QWidget {
  Q_OBJECT

public:
  MainScreen(QWidget *parent = nullptr);
  virtual ~MainScreen();

private:
  void setTextEditContent();

  QVBoxLayout *m_main_layout;
  QHBoxLayout *m_layout_button;
  QTextEdit *m_text_edit;
  QRadioButton *m_button_br;
  QRadioButton *m_button_en;
  QRadioButton *m_button_de;

signals:
  void translationLanguageChanged(QString lang);

private slots:
  void setTranslationLanguage();
};


#endif
