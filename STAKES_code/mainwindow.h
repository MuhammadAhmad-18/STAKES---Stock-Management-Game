#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>
#include <QIcon>
#include <QProcess>
#include <QResizeEvent>
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QWidget>
#include <QDialog>
#include <QKeyEvent>
#include <QPropertyAnimation>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QLabel>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QHBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE





class LoadingScreen : public QDialog {
    Q_OBJECT // Enable signal/slot mechanism

public:
    LoadingScreen(QWidget *parent = nullptr) : QDialog(parent) {
        setWindowTitle("STAKES");
        setWindowIcon(QIcon(":/images/STAKES_LOGO.png"));

        setModal(true); // Make it modal
        setFixedSize(600, 400); // Set a fixed size

        QVBoxLayout *layout = new QVBoxLayout(this);

        // Add an image label
        QLabel *imageLabel = new QLabel(this);
        QPixmap image(":/images/STAKES_LOGO.png"); // Replace with your image path
        imageLabel->setPixmap(image.scaled(600, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation)); // Scale the image
        imageLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(imageLabel);

        // Add an instruction label
        QLabel *instructionLabel = new QLabel("Press Space to continue...", this);
        instructionLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(instructionLabel);

        // Set the initial opacity of the dialog to 0
        setWindowOpacity(0);
    }

    void showEvent(QShowEvent *event) override {
        QDialog::showEvent(event);
        // Create a fade-in animation
        QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
        animation->setDuration(1500); // Duration in milliseconds
        animation->setStartValue(0);
        animation->setEndValue(1);
        animation->start();
    }

protected:
    void keyPressEvent(QKeyEvent *event) override {
        if (event->key() == Qt::Key_Space) {
            accept(); // Close the dialog when Space is pressed
        }
        QDialog::keyPressEvent(event); // Call base class implementation
    }
};














class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_SELL_BUTTON_clicked();

    void on_BUY_BUTTON_clicked();

    void on_BUY_CRYPTO_clicked();

    void on_SELL_CRYPTO_clicked();

    void calculateLoan(double loanAmount, const QString &selectedDuration, QDialog *dialog) ;

    void on_loanButton_clicked();

    void on_BUY_REAL_ESTATE_clicked();

    void on_SELL_REAL_ESTATE_clicked();


    void on_REAPYMENT_clicked();


    void on_DIPLOMACY_clicked();



    void on_STCOK_HOLDINGS_clicked();

    void on_CRYPTO_HOLDINGS_clicked();

    void on_REAL_ESTAT_HOLDINGS_clicked();

    void on_COURT_STATUS_clicked();

    void on_RESTART_clicked();

    void on_QUIT_GAME_clicked();

    void on_SAVE_clicked();

    void on_LOAD_clicked();

private:
    Ui::MainWindow *ui;
    void checkForWar(QList<QPair<QString, float>>& countries); // Function to check for war


};
#endif // MAINWINDOW_H
