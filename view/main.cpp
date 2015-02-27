#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>

#include "view/main_screen.h"
#include "core/core_strings.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  MainScreen *main_screen = new MainScreen();
  main_screen->show();

  return app.exec();
}
