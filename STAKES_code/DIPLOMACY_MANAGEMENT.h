void MainWindow::on_DIPLOMACY_clicked()
{
    // Create the dialog window to display the table
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Diplomatic Relations Table");

    if(countries_at_war_with>0){

        if(countries_at_war_with==1){

            QMessageBox::warning(this, "War Alert","Pakistan is at war with 1 country!");

        }
        else
        {
            QMessageBox::warning(this, "War Alert","Pakistan is at war with multiple countries!");
        }

    }
    else
    {
        QMessageBox::warning(this, "War Alert","Pakistan is not at war with any country!");
    }
    // Create the table widget
    QTableWidget *tableWidget = new QTableWidget(dialog);
    tableWidget->setColumnCount(2); // Two columns: Country and Diplomatic Value
    tableWidget->setHorizontalHeaderLabels({"Country", "Diplomatic Value"});

    //both lists of countries into one list
    QList<QPair<QString, float>> allCountries = neighboringCountriesDiplomaticStatus + countriesExcludingNeighborsDiplomaticStatus;

    // Set row count based on the number of countries
    tableWidget->setRowCount(allCountries.size());

    // Populate the table with country names and their corresponding diplomatic values
    for (int i = 0; i < allCountries.size(); ++i) {
        QTableWidgetItem *countryItem = new QTableWidgetItem(allCountries[i].first);
        tableWidget->setItem(i, 0, countryItem);

        QTableWidgetItem *valueItem = new QTableWidgetItem(QString::number(allCountries[i].second));
        tableWidget->setItem(i, 1, valueItem);
    }

    // Set layout for the dialog and show it
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(tableWidget);
    dialog->setLayout(layout);
    dialog->exec();

}




void MainWindow::checkForWar(QList<QPair<QString, float>>& countries)
{
    // Random generator for the war chance
    QRandomGenerator randGen;
    countries_at_war_with = 0;
    // Loop through each country and check their diplomatic value
    for (const QPair<QString, float>& country : countries)
    {
        if (country.second < 5.0) // Diplomatic value below 5
        {
            // 5% chance of war
            if (randGen.bounded(100) < 5)  // 5% chance
            {
                // War has occurred
                countries_at_war_with += 1;
                war_impact = war_impact * countries_at_war_with;
                return; // Exit after the first war alert is displayed
            }
        }
    }

    // If no war detected
}
