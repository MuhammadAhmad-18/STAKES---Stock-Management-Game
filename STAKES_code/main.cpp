#include "mainwindow.h"

#include <QApplication>
#include <QPalette>
#include <QWidget>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Set the Fusion style
    a.setStyle("Fusion");

    // Create a dark palette
    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::Highlight, QColor(0, 120, 215));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);

    a.setPalette(darkPalette);


    a.setWindowIcon(QIcon(":/images/STAKES_LOGO.png"));
    // Show the loading screen
    LoadingScreen loadingScreen;
    if (loadingScreen.exec() == QDialog::Accepted) {
        // Show the main window after the loading screen is closed
        MainWindow w;
        w.setWindowTitle("STAKES"); // Set the title of the MainWindow to "STAKES"
        w.showMaximized(); // Show the window maximized
        return a.exec(); // Start the event loop
    }

    // Exit the application if the loading screen is closed
    return 0;
}
