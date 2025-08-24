void MainWindow::on_COURT_STATUS_clicked()
{
    // Show the result using QMessageBox
    QMessageBox::information(this, "Petition Status",  QString("You have a declared %1 petitions till now.").arg(number_of_petitions));
    QMessageBox::information(this, "Arrest Information",  QString("You have a %1% chance of being arrested due to your reputation.").arg(arrestProbability));

}
