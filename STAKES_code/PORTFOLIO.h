
void MainWindow::on_STCOK_HOLDINGS_clicked()
{
    // Create the dialog window to display the stocks table
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Your Stocks");

    // Check if the user owns any stocks
    if (your_stocks.isEmpty()) {
        QMessageBox::warning(this, "No Stocks", "You do not own any stocks.");
        return;
    }

    // Create the table widget
    QTableWidget *tableWidget = new QTableWidget(dialog);
    tableWidget->setColumnCount(2); // Two columns: Company and Stock Price
    tableWidget->setHorizontalHeaderLabels({"Company", "Stock Price"});

    // Copy the stocks data into a list so we can sort by stock amount
    QList<QPair<QString, int>> sortedStocks;
    for (auto it = your_stocks.begin(); it != your_stocks.end(); ++it) {
        sortedStocks.append(qMakePair(it.key(), it.value()));
    }

    // Sort the list by the stock amount (value) in descending order
    std::sort(sortedStocks.begin(), sortedStocks.end(),
              [](const QPair<QString, int>& a, const QPair<QString, int>& b) {
                  return a.second > b.second;  // Sort in descending order based on the stock amount
              });

    // Set row count based on the number of stocks the user owns
    tableWidget->setRowCount(sortedStocks.size());

    // Populate the table with company names and their corresponding stock prices
    int row = 0;
    for (const auto& stock : sortedStocks) {
        // Create and set company name in the first column
        QTableWidgetItem *companyItem = new QTableWidgetItem(stock.first);
        tableWidget->setItem(row, 0, companyItem);

        // Create and set stock price in the second column
        QTableWidgetItem *priceItem = new QTableWidgetItem(QString::number(stock.second));
        tableWidget->setItem(row, 1, priceItem);

        ++row; // Move to the next row
    }

    // Set layout for the dialog and show it
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(tableWidget);
    dialog->setLayout(layout);
    dialog->exec();

}


void MainWindow::on_CRYPTO_HOLDINGS_clicked()
{
    // Create the dialog window to display the crypto holdings table
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Your Crypto Holdings");

    // Check if the user owns any cryptocurrency
    if (your_crypto_holdings.isEmpty()) {
        QMessageBox::warning(this, "No Cryptos", "You do not own any cryptocurrencies.");
        return;
    }

    // Create the table widget
    QTableWidget *tableWidget = new QTableWidget(dialog);
    tableWidget->setColumnCount(2); // Two columns: Cryptocurrency and Quantity
    tableWidget->setHorizontalHeaderLabels({"Cryptocurrency", "Quantity"});

    // Copy the crypto holdings data into a list so we can sort by quantity
    QList<QPair<QString, int>> sortedCryptos;
    for (auto it = your_crypto_holdings.begin(); it != your_crypto_holdings.end(); ++it) {
        sortedCryptos.append(qMakePair(it.key(), it.value()));
    }

    // Sort the list by the quantity in descending order
    std::sort(sortedCryptos.begin(), sortedCryptos.end(),
              [](const QPair<QString, int>& a, const QPair<QString, int>& b) {
                  return a.second > b.second;  // Sort in descending order based on the quantity
              });

    // Set row count based on the number of cryptocurrencies the user owns
    tableWidget->setRowCount(sortedCryptos.size());

    // Populate the table with cryptocurrency names and their corresponding quantities
    int row = 0;
    for (const auto& crypto : sortedCryptos) {
        // Create and set cryptocurrency name in the first column
        QTableWidgetItem *cryptoItem = new QTableWidgetItem(crypto.first);
        tableWidget->setItem(row, 0, cryptoItem);

        // Create and set quantity in the second column
        QTableWidgetItem *quantityItem = new QTableWidgetItem(QString::number(crypto.second));
        tableWidget->setItem(row, 1, quantityItem);

        ++row; // Move to the next row
    }

    // Set layout for the dialog and show it
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(tableWidget);
    dialog->setLayout(layout);
    dialog->exec();


}


void MainWindow::on_REAL_ESTAT_HOLDINGS_clicked()
{
    // Create the dialog window to display the property holdings table
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Your Property Holdings");

    // Check if the user owns any properties
    if (your_property_holdings.isEmpty()) {
        QMessageBox::warning(this, "No Properties", "You do not own any properties.");
        return;
    }

    // Create the table widget
    QTableWidget *tableWidget = new QTableWidget(dialog);
    tableWidget->setColumnCount(3); // Three columns: Property, Units Owned, Property Value
    tableWidget->setHorizontalHeaderLabels({"Property", "Units Owned", "Property Value"});

    // Copy the property holdings data into a list so we can sort by units owned
    QList<QPair<QString, QPair<int, int>>> sortedProperties;
    for (auto it = your_property_holdings.begin(); it != your_property_holdings.end(); ++it) {
        sortedProperties.append(qMakePair(it.key(), it.value()));
    }

    // Sort the list by the number of units owned in descending order
    std::sort(sortedProperties.begin(), sortedProperties.end(),
              [](const QPair<QString, QPair<int, int>>& a, const QPair<QString, QPair<int, int>>& b) {
                  return a.second.first > b.second.first;  // Sort in descending order based on units owned
              });

    // Set row count based on the number of properties the user owns
    tableWidget->setRowCount(sortedProperties.size());

    // Populate the table with property names, units owned, and property values
    int row = 0;
    for (const auto& property : sortedProperties) {
        // Create and set property name in the first column
        QTableWidgetItem *propertyItem = new QTableWidgetItem(property.first);
        tableWidget->setItem(row, 0, propertyItem);

        // Create and set units owned in the second column
        QTableWidgetItem *unitsItem = new QTableWidgetItem(QString::number(property.second.first));
        tableWidget->setItem(row, 1, unitsItem);

        // Create and set property value in the third column
        QTableWidgetItem *valueItem = new QTableWidgetItem(QString::number(property.second.second));
        tableWidget->setItem(row, 2, valueItem);

        ++row; // Move to the next row
    }

    // Set layout for the dialog and show it
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(tableWidget);
    dialog->setLayout(layout);
    dialog->exec();

}

