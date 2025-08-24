void MainWindow::on_RESTART_clicked()
{
    bool confirmed_quit = QMessageBox::question(this,"Quit","Are you sure you wanna restart the game ?",QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes ;
    if(confirmed_quit){

        // Get the path to the current executable
        QString appPath = QApplication::applicationFilePath();

        // Quit the application
        QApplication::quit();

        // Use QProcess to restart the application
        QProcess::startDetached(appPath);  // Start a new instance of the application
    }
}


void MainWindow::on_QUIT_GAME_clicked()
{
    bool confirmed_quit = QMessageBox::question(this,"Quit","Are you sure you wanna quit the game ? \n Wo mard nai ho dar jaye halat k khoni manzar sy \n Jis door main jeena mushkil ho us door main jeena lazim ha",QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes ;
    if(confirmed_quit){
        QApplication::quit();  // This will exit the application
    }
}
