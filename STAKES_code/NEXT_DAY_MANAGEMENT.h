void MainWindow::on_pushButton_clicked()
{    
    if(bank_balance>0)
    {
        QWidget *parentWidget = this; // Or some other widget that is the parent
    checkReputation(reputation,parentWidget) ;

    DAY_NUMBER++ ;
        reputation += 0.5;
    addNegativeScenarios();
    addPositiveScenarios();

    for (auto it = your_property_holdings.begin(); it != your_property_holdings.end(); ++it) {
        const QString& key = it.key(); // Get the key (QString)
        QPair<int, int>& value = it.value(); // Get the value (QPair<int, int>)

        // Check if the second element is greater than 0
        if (value.second > 0) {
            // Increase the second element by 1
            value.second += 1;

            // Optional: Print the updated value
            qDebug() << "Property:" << key << "updated to value:" << value.second;
        }
    }

    for(int i = 0; i < your_property_holdings.size(); ++i)
    {
        const QString &propertyName = properties[i].first; // Access the property name

        checkAndUpdateBalance( your_property_holdings , properties, propertyName) ;
    }
    ui->DAYNUMBER->setText(QString::number(DAY_NUMBER));
    ui->BALANCE->setText(QString::number(bank_balance));


    ui->REPUTATION->setText(QString::number(reputation));
    if (reputation < 30) {
        ui->REPUTATION->setStyleSheet("color: red;");
    } else {
        ui->REPUTATION->setStyleSheet("color: green;");
    }

    if (bank_balance < 0) {
        ui->BALANCE->setStyleSheet("color: red;");
    }

    ui->TOTAL_LOAN->setText(QString::number(total_loan_taken));

    if(DAY_NUMBER==1)
    {
        for (const QString &company : for_list_companies) {
            your_stocks[company] = 0; // Initialize each company's stock to 0
        }
    }
    if (DAY_NUMBER == 1) {
        for (const QString &cryptoName : for_list_companies) {
            your_crypto_holdings[cryptoName] = 0; // Initialize each cryptocurrency holding to 0
        }
    }
    net_balance = (bank_balance - total_loan_taken);

    if (loan_number == 1) {
        net_balance = net_balance - total_loan_taken;

        for (int i = 0; i < loans.size(); ++i) {
            loans[i].second.second.first -= 1;
            if (loans[i].second.second.first == 0) {


                bool goToCourt = QMessageBox::question(this, "Court Option",
                                                       "Do you want to go to court and obtain a stay order?",
                                                       QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes;

                if (goToCourt) {
                    if (reputation >= 5) { // Only proceed if reputation is sufficient
                        // Ask the user for how long they want the stay order (15 days or 3 months)
                        bool ok;
                        QString stayOptionString = QInputDialog::getItem(this, "Stay Order",
                                                                         "Choose the duration of the stay order:",
                                                                         {"15 days", "1 month"}, 0, false, &ok);
                        if (ok) {
                            // Convert stayOptionString to int based on selection
                            int stayOption = 0; // Default value
                            if (stayOptionString == "15 days") {
                                stayOption = 15;  // 15 days
                            } else if (stayOptionString == "1 month") {
                                stayOption = 30;  // 1 month
                            }

                            // Deduct reputation based on the chosen stay duration
                            if (stayOption == 15) {  // 15 days
                                reputation -= 5;
                                QMessageBox::information(this, "Court Decision",
                                                         "Stay order granted for 15 days. Reputation decreased by 5.");
                                loans[i].second.second.first = 15; // Update loan stay duration
                            } else if (stayOption == 30) {  // 1 month
                                reputation -= 10;
                                QMessageBox::information(this, "Court Decision",
                                                         "Stay order granted for 1 month. Reputation decreased by 10.");
                                loans[i].second.second.first = 30; // Update loan stay duration
                            }

                            // Prevent stay if reputation is too low
                            if (reputation < 0) {
                                reputation = 0;  // Ensure reputation doesn't go below 0
                            }
                            ui->REPUTATION->setText(QString::number(reputation));

                        }
                    } else {
                        QMessageBox::warning(this, "Low Reputation",
                                             "Your reputation is too low to obtain a stay order. Loan repayment will proceed immediately.");
                        bank_balance = bank_balance - loans[i].second.first;
                        total_loan_taken = total_loan_taken - loans[i].first;
                        loans.removeAt(i);
                        i--;
                        ui->LOAN_TABLE->removeRow(i);
                        ui->LOAN_TABLE->setRowCount(loans.size());
                        ui->BALANCE->setText(QString::number(bank_balance));
                        ui->TOTAL_LOAN->setText(QString::number(total_loan_taken));
                    }
                }
                else
                {
                    bank_balance = bank_balance - loans[i].second.first;
                    total_loan_taken = total_loan_taken - loans[i].first;
                    loans.removeAt(i);
                    i--;
                    ui->LOAN_TABLE->removeRow(i);
                    ui->LOAN_TABLE->setRowCount(loans.size());
                    ui->BALANCE->setText(QString::number(bank_balance));
                    ui->TOTAL_LOAN->setText(QString::number(total_loan_taken));
                }
                // Show the message box and wait for user response
            }
        }
    }

    for (int i = 0; i < loans.size(); ++i) {
        const auto &loan = loans[i];

        // Set the values in the table
        ui->LOAN_TABLE->setItem(i, 0, new QTableWidgetItem(QString::number(loan.first))); // Loan Amount
        ui->LOAN_TABLE->setItem(i, 1, new QTableWidgetItem(QString::number(loan.second.first))); // TO BE PAID
        ui->LOAN_TABLE->setItem(i, 2, new QTableWidgetItem(QString::number(loan.second.second.first))); // Term
        ui->LOAN_TABLE->setItem(i, 3, new QTableWidgetItem(loan.second.second.second)); // STATUS
    }


    QStringList headers;
    headers << "Company Name" << "Stock Price ($)" << "Risk Factor";
    ui->STOCK_TABLE->setHorizontalHeaderLabels(headers);
    QList<QPair<QString, QPair<float, float>>> companies;

    for (int i = 0; i < 30; ++i) {
        companies.append(QPair<QString, QPair<float, float>>(company_names[i], QPair<float, float>(stock_prices[i], risk_factors[i])));
    }


    if(DAY_NUMBER>1){
        stock_simulate(companies);
    }

    std::sort(companies.begin(), companies.end(), [](const QPair<QString, QPair<float, float>>& a, const QPair<QString, QPair<float, float>>& b) {
        return a.second.first > b.second.first;  // descending order by price
    });

    // Populate the table with company data, stock prices, and risk factors
    for (int i = 0; i < companies.size(); ++i) {
        ui->STOCK_TABLE->setItem(i, 0, new QTableWidgetItem(companies[i].first)); // Company Name
        ui->STOCK_TABLE->setItem(i, 1, new QTableWidgetItem(QString::number(companies[i].second.first, 'f', 2))); // Stock Price
        ui->STOCK_TABLE->setItem(i, 2, new QTableWidgetItem(QString::number(companies[i].second.second, 'f', 4))); // Risk Factor
    }
  /*  // Sort the companies list by stock price (second.first) in descending order
    QList<QPair<QPair<QString, QPair<float, float>>, bool>> combined;
    for (int i = 0; i < companies.size(); ++i) {
        combined.append(qMakePair(companies[i], colour[i]));
    }

    // Sort the combined list by stock price (second.first) in descending order
    std::sort(combined.begin(), combined.end(), [](const auto& a, const auto& b) {
        return a.first.second.first > b.first.second.first; // Sort in descending order
    });

    // Extract the sorted values back into companies and color lists
    companies.clear();
    colour.clear();
    for (const auto& item : combined) {
        companies.append(item.first);
        colour.append(item.second);
    }

    for (int i = 0; i < companies.size(); ++i) {
        ui->STOCK_TABLE->setItem(i, 0, new QTableWidgetItem(companies[i].first)); // Company Name

        // Create a new QTableWidgetItem for Stock Price
        QTableWidgetItem* priceItem = new QTableWidgetItem(QString::number(companies[i].second.first, 'f', 2)); // Stock Price

        // Set the text color based on price change

        ui->STOCK_TABLE->setItem(i, 1, priceItem); // Stock Price

        ui->STOCK_TABLE->setItem(i, 2, new QTableWidgetItem(QString::number(companies[i].second.second, 'f', 4))); // Risk Factor
    }

    colour.clear();
*/
    ui->STOCK_TABLE->resizeColumnsToContents();


    generateDiplomaticScenario(neighboringCountriesDiplomaticStatus,countriesExcludingNeighborsDiplomaticStatus,borderingCountriesPositiveScenarios,borderingCountriesNegativeScenarios,nonBorderingCountriesPositiveScenarios,nonBorderingCountriesNegativeScenarios,newsArray);

    newsText = "\t\t\tTHE STAKES BUSINESS NEWS \n";
    for (int i = 0; i < 4; ++i) {
        // Generate a random index from the list
        int randomIndex = QRandomGenerator::global()->bounded(news.size());

        // Retrieve the random news item
        selectedNews = news[randomIndex].second.first; // Headline

        indexes_of_companies[i]= randomIndex ;
        // Format the output for the current news item
        newsText += "Headline: " + selectedNews + "\n";

    }
    newsText += "\t\t\tTHE STAKES NATIONAL NEWS \n";
    selectNewsAndCalculateChange(negative_news) ;

    newsText += "\t\t\tTHE STAKES INTERNATIONAL NEWS \n";
    for (int i = 0; i < 3; ++i) {
        newsText += "Headline: " + newsArray[i] + "\n";
    }


    // Set the constructed QString to the NEWS widget
    ui->NEWS->setPlainText(newsText);
    // Display the news in the QTextBrowser
    // ui->NEWS->setPlainText(news);




    QList<QPair<QString, QPair<float, float>>> cryptos;
    for (int i = 0; i < 30; ++i) {
        cryptos.append(QPair<QString, QPair<float, float>>(cryptoNames[i], QPair<float, float>(cryptoPrices[i], cryptoRiskFactors[i])));
    }

    if(DAY_NUMBER>0){
        simulateCryptoChanges(cryptos);
    }

    // Sort the cryptocurrencies by price in descending order
    std::sort(cryptos.begin(), cryptos.end(), [](const QPair<QString, QPair<float, float>>& a, const QPair<QString, QPair<float, float>>& b) {
        return a.second.first > b.second.first;  // descending order by price
    });

    // Populate the table with cryptocurrency data
    for (int i = 0; i < cryptos.size(); ++i) {
        ui->CRYPTO_TABLE->setItem(i, 0, new QTableWidgetItem(cryptos[i].first)); // Cryptocurrency Name
        ui->CRYPTO_TABLE->setItem(i, 1, new QTableWidgetItem(QString::number(cryptos[i].second.first, 'f', 2))); // Price
        ui->CRYPTO_TABLE->setItem(i, 2, new QTableWidgetItem(QString::number(cryptos[i].second.second, 'f', 4))); // Risk Factor
    }

    ui->REAL_ESTATE->setRowCount(properties.size());
    ui->REAL_ESTATE->verticalHeader()->setVisible(false);

    std::sort(properties.begin(), properties.end(), [](const QPair<QString, QPair<float, float>>& a, const QPair<QString, QPair<float, float>>& b) {
        return a.second.first < b.second.first;  // descending order by stock price
    });
    for (int i = 0; i < properties.size(); ++i) {
        const auto& property = properties[i];







        // Set the property name
        ui->REAL_ESTATE->setItem(i, 0, new QTableWidgetItem(property.first));
        // Set the purchase price
        ui->REAL_ESTATE->setItem(i, 1, new QTableWidgetItem(QString::number(property.second.first, 'f' , 2)));
        // Set the rental price
        ui->REAL_ESTATE->setItem(i, 2, new QTableWidgetItem(QString::number(property.second.second, 'f' , 2)));
    }


    ui->REAL_ESTATE->resizeColumnsToContents();

    ui->LOAN_TABLE->resizeColumnsToContents();







    if(DAY_NUMBER>0)
    {
        simulate_news_based_change(news,indexes_of_companies,4);
        updateStockPrices(companies) ;

    }

    QList<QPair<QString, float>> Countries = neighboringCountriesDiplomaticStatus + countriesExcludingNeighborsDiplomaticStatus;
    checkForWar(Countries);

    selectNewsAndCalculateChange(negative_news) ;
    }
    else
    {
        bool wow = QMessageBox::question(this,"Bankrupcy","You have a negative balance. Sell assets or file bankrupcy. Do you want to file Bankrupcy.",QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes ;
        if(wow)
        {
            bool exit = QMessageBox::question(this,"Good Game","Nice try fed ... Want to give it another try ?", QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes ;
            if(!exit)
            {
                bool confirmed_quit = QMessageBox::question(this,"Quit","Are you sure you wanna quit the game ? \n Wo mard nai ho dar jaye halat k khoni manzar sy \n Jis door main jeena mushkil ho us door main jeena lazim ha",QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes ;
                if(confirmed_quit){
                    QApplication::quit();  // This will exit the application
                }

            }
            else
            {
                // Get the path to the current executable
                QString appPath = QApplication::applicationFilePath();

                // Quit the application
                QApplication::quit();

                // Use QProcess to restart the application
                QProcess::startDetached(appPath);  // Start a new instance of the application
            }

        }
    }
}
