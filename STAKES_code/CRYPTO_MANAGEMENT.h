
void MainWindow::on_BUY_CRYPTO_clicked()
{
    // Get the index of the currently selected row
    int currentRow = ui->CRYPTO_TABLE->currentRow();
    qDebug() << "Current Row:" << currentRow; // Debug output

    // Check if any row is selected
    if (currentRow == -1) {
        QMessageBox::warning(this, "Investment", "No row is selected to invest in.");
        return;
    }

    // Retrieve the details of the selected cryptocurrency from the table
    QString cryptoName = ui->CRYPTO_TABLE->item(currentRow, 0)->text(); // Assuming the first column is the cryptocurrency name
    QString priceText = ui->CRYPTO_TABLE->item(currentRow, 1)->text();   // Assuming the second column is the crypto price
    QString marketCap = ui->CRYPTO_TABLE->item(currentRow, 2)->text();   // Assuming the third column is market cap

    // Check if priceText is valid
    if (priceText.isEmpty()) {
        QMessageBox::warning(this, "Error", "Crypto price is not available.");
        return;
    }

    float cryptoPrice = priceText.toFloat(); // Assuming the second column is the crypto price
    qDebug() << "Crypto Price:" << cryptoPrice; // Debug output

    // Ask the user for the amount of cryptocurrency they want to buy
    bool ok;
    int cryptoAmount = QInputDialog::getInt(this, "Crypto Amount",
                                            QString("Enter the number of units you want to buy of %1:").arg(cryptoName),
                                            1, 1, 1000000, 1, &ok);
    if (!ok) {
        // User canceled the input
        return;
    }

    // Calculate the total cost of the cryptocurrency
    float totalCost = cryptoAmount * cryptoPrice;
    qDebug() << "Total Cost:" << totalCost; // Debug output

    // Check if the user has sufficient bank balance
    if (totalCost > bank_balance) {
        QMessageBox::warning(this, "Insufficient Funds",
                             QString("You do not have enough funds to buy %1 units of %2.\nTotal cost: $%3\nYour balance: $%4")
                                 .arg(cryptoAmount).arg(cryptoName).arg(totalCost).arg(bank_balance));
        return;
    }

    // Confirm investment
    if (QMessageBox::question(this, "Confirm Investment",
                              QString("Do you want to invest in %1?\nCRYPTO PRICE: $%2\nMARKET CAP: %3\nCRYPTO AMOUNT: %4\nTOTAL COST: $%5")
                                  .arg(cryptoName).arg(cryptoPrice).arg(marketCap).arg(cryptoAmount).arg(totalCost)) == QMessageBox::Yes) {

        // Display success message
        QMessageBox::information(this, "Investment Successful",
                                 QString("You have successfully invested in %1, buying %2 units.").arg(cryptoName).arg(cryptoAmount));

        // Update your_crypto_holdings to reflect the purchase
        your_crypto_holdings[cryptoName] += cryptoAmount; // Increase the crypto count for the purchased cryptocurrency

        // Deduct the total cost from the bank balance
        bank_balance -= totalCost;
        ui->BALANCE->setText(QString::number(bank_balance));

        // Optionally, mark the row as "Invested" (e.g., change background color)
        for (int col = 0; col < ui->CRYPTO_TABLE->columnCount(); ++col) {
            ui->CRYPTO_TABLE->item(currentRow, col)->setBackground(Qt::green);
        }
    }
}


void MainWindow::on_SELL_CRYPTO_clicked()
{
    // Get the index of the currently selected row
    int currentRow = ui->CRYPTO_TABLE->currentRow();
    qDebug() << "Current Row:" << currentRow; // Debug output

    // Check if any row is selected
    if (currentRow == -1) {
        QMessageBox::warning(this, "Investment", "No row is selected to sell.");
        return;
    }

    // Retrieve the details of the selected cryptocurrency from the table
    QString cryptoName = ui->CRYPTO_TABLE->item(currentRow, 0)->text(); // Assuming the first column is the cryptocurrency name
    QString priceText = ui->CRYPTO_TABLE->item(currentRow, 1)->text();   // Assuming the second column is the crypto price
    QString marketCap = ui->CRYPTO_TABLE->item(currentRow, 2)->text();   // Assuming the third column is market cap

    // Check if priceText is valid
    if (priceText.isEmpty()) {
        QMessageBox::warning(this, "Error", "Crypto price is not available.");
        return;
    }

    float cryptoPrice = priceText.toFloat(); // Assuming the second column is the crypto price
    qDebug() << "Crypto Price:" << cryptoPrice; // Debug output

    // Check if the user has any holdings of the selected cryptocurrency
    if (your_crypto_holdings[cryptoName] <= 0) {
        QMessageBox::warning(this, "Error", QString("You do not own any units of %1.").arg(cryptoName));
        return;
    }

    // Ask the user for the amount of cryptocurrency they want to sell
    bool ok;
    int cryptoAmount = QInputDialog::getInt(this, "Crypto Amount",
                                            QString("Enter the number of units you want to sell of %1 (You own %2 units):").arg(cryptoName).arg(your_crypto_holdings[cryptoName]),
                                            1, 1, your_crypto_holdings[cryptoName], 1, &ok);
    if (!ok) {
        // User canceled the input
        return;
    }

    // Calculate the total earnings from the sale of the cryptocurrency
    float totalEarnings = cryptoAmount * cryptoPrice;
    qDebug() << "Total Earnings:" << totalEarnings; // Debug output

    // Check if the user is selling more than they own
    if (cryptoAmount > your_crypto_holdings[cryptoName]) {
        QMessageBox::warning(this, "Error",
                             QString("You cannot sell more than you own. You own %1 units of %2.").arg(your_crypto_holdings[cryptoName]).arg(cryptoName));
        return;
    }

    // Confirm sale
    if (QMessageBox::question(this, "Confirm Sale",
                              QString("Do you want to sell %1 units of %2?\nCRYPTO PRICE: $%3\nRISK FACTOR: %4\nTOTAL EARNINGS: $%5")
                                  .arg(cryptoAmount).arg(cryptoName).arg(cryptoPrice).arg(marketCap).arg(totalEarnings)) == QMessageBox::Yes) {

        // Display success message
        QMessageBox::information(this, "Sale Successful",
                                 QString("You have successfully sold %1 units of %2.").arg(cryptoAmount).arg(cryptoName));

        // Update your_crypto_holdings to reflect the sale
        your_crypto_holdings[cryptoName] -= cryptoAmount; // Decrease the crypto count for the sold cryptocurrency

        // Add the total earnings to the bank balance
        bank_balance += totalEarnings;
        ui->BALANCE->setText(QString::number(bank_balance));

        // Optionally, mark the row as "Sold" (e.g., change background color)
        for (int col = 0; col < ui->CRYPTO_TABLE->columnCount(); ++col) {
            ui->CRYPTO_TABLE->item(currentRow, col)->setBackground(Qt::red);
        }
    }

}
