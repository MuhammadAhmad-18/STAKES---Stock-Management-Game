void MainWindow::on_SELL_BUTTON_clicked()
{
    // Get the index of the currently selected row
    int currentRow = ui->STOCK_TABLE->currentRow();

    // Check if any row is selected
    if (currentRow == -1) {
        QMessageBox::warning(this, "Sell Stock", "No row is selected to sell from.");
        return;
    }

    // Retrieve the details of the selected business from the table
    QString businessName = ui->STOCK_TABLE->item(currentRow, 0)->text(); // Assuming the first column is the business name
    float stockPrice = ui->STOCK_TABLE->item(currentRow, 1)->text().toFloat(); // Assuming the second column is the stock price
    QString revenue = ui->STOCK_TABLE->item(currentRow, 2)->text();      // Assuming the third column is revenue

    // Check if the user owns stocks of the selected business
    if (!your_stocks.contains(businessName) || your_stocks[businessName] <= 0) {
        QMessageBox::warning(this, "Sell Stock", QString("You do not own any stocks of %1.").arg(businessName));
        return;
    }

    // Ask the user for the amount of stocks they want to sell
    bool ok;
    int maxStocks = your_stocks[businessName]; // Maximum stocks available to sell
    int stockAmount = QInputDialog::getInt(this, "Stock Amount",
                                           QString("Enter the number of stocks you want to sell of %1 (Max: %2):").arg(businessName).arg(maxStocks),
                                           1, 1, maxStocks, 1, &ok);
    if (!ok) {
        // User canceled the input
        return;
    }

    // Check if the user is trying to sell more stocks than they own
    if (stockAmount > maxStocks) {
        QMessageBox::warning(this, "Sell Stock", QString("You cannot sell more than %1 stocks of %2.").arg(maxStocks).arg(businessName));
        return;
    }

    float totalRevenue = stockAmount * stockPrice;

    // Assuming broker fee is a fixed percentage (e.g., 2%)
    float brokerFeePercentage = 1.0f; // Broker fee percentage
    float brokerFee = (brokerFeePercentage / 100) * totalRevenue; // Calculate broker fee
    float finalRevenue = totalRevenue - brokerFee; // Revenue after broker fee

    // Confirm sale
    if (QMessageBox::question(this, "Confirm Sale",
                              QString("Do you want to sell %1 stocks of %2?\nSTOCK PRICE: $%3\nRISK FACTOR: %4\nTOTAL REVENUE: $%5\nBROKER FEE: $%6\nFINAL REVENUE: $%7")
                                  .arg(stockAmount).arg(businessName).arg(stockPrice).arg(revenue).arg(totalRevenue).arg(brokerFee).arg(finalRevenue)) == QMessageBox::Yes) {

        // Update bank balance with final revenue after broker fee
        bank_balance += finalRevenue;
        ui->BALANCE->setText(QString::number(bank_balance));

        // Display success message
        QMessageBox::information(this, "Sale Successful",
                                 QString("You have successfully sold %1 stocks of %2 for $%3. Broker Fee: $%4. Final Earnings: $%5.")
                                     .arg(stockAmount).arg(businessName).arg(totalRevenue).arg(brokerFee).arg(finalRevenue));

        // Update your_stocks to reflect the sale
        your_stocks[businessName] -= stockAmount;

        // Optionally, mark the row as "Sold" (e.g., change background color)
        for (int col = 0; col < ui->STOCK_TABLE->columnCount(); ++col) {
            ui->STOCK_TABLE->item(currentRow, col)->setBackground(Qt::red);
        }
    }
}

void MainWindow::on_BUY_BUTTON_clicked()
{
    // Get the index of the currently selected row
    int currentRow = ui->STOCK_TABLE->currentRow();
    qDebug() << "Current Row:" << currentRow; // Debug output

    // Check if any row is selected
    if (currentRow == -1) {
        QMessageBox::warning(this, "Investment", "No row is selected to invest in.");
        return;
    }

    // Retrieve the details of the selected business from the table
    QString businessName = ui->STOCK_TABLE->item(currentRow, 0)->text(); // Assuming the first column is the business name
    QString priceText = ui->STOCK_TABLE->item(currentRow, 1)->text();    // Assuming the second column is the stock price
    QString revenue = ui->STOCK_TABLE->item(currentRow, 2)->text();      // Assuming the third column is revenue

    // Check if priceText is valid
    if (priceText.isEmpty()) {
        QMessageBox::warning(this, "Error", "Stock price is not available.");
        return;
    }

    float stockPrice = priceText.toFloat(); // Stock price from the table
    qDebug() << "Stock Price:" << stockPrice; // Debug output

    // Ask the user for the amount of stocks they want to buy
    bool ok;
    int stockAmount = QInputDialog::getInt(this, "Stock Amount",
                                           QString("Enter the number of stocks you want to buy of %1:").arg(businessName),
                                           1, 1, 1000000, 1, &ok);
    if (!ok) {
        // User canceled the input
        return;
    }

    // Calculate the total cost of the stocks
    float totalCost = stockAmount * stockPrice;
    qDebug() << "Total Cost:" << totalCost; // Debug output

    // Assuming broker fee is a fixed percentage (e.g., 2%)
    float brokerFeePercentage = 2.0f; // Broker fee percentage
    float brokerFee = (brokerFeePercentage / 100) * totalCost; // Calculate broker fee
    float finalCost = totalCost + brokerFee; // Final cost including broker fee

    // Check if the user has sufficient bank balance (including broker fee)
    if (finalCost > bank_balance) {
        QMessageBox::warning(this, "Insufficient Funds",
                             QString("You do not have enough funds to buy %1 stocks of %2.\nTotal cost: $%3\nBroker Fee: $%4\nYour balance: $%5")
                                 .arg(stockAmount).arg(businessName).arg(totalCost).arg(brokerFee).arg(bank_balance));
        return;
    }

    // Confirm investment
    if (QMessageBox::question(this, "Confirm Investment",
                              QString("Do you want to invest in %1?\nSTOCK PRICE: $%2\nRISK FACTOR: %3\nSTOCK AMOUNT: %4\nTOTAL COST: $%5\nBROKER FEE: $%6\nFINAL COST: $%7")
                                  .arg(businessName).arg(stockPrice).arg(revenue).arg(stockAmount).arg(totalCost).arg(brokerFee).arg(finalCost)) == QMessageBox::Yes) {

        // Display success message
        QMessageBox::information(this, "Investment Successful",
                                 QString("You have successfully invested in %1, buying %2 stocks. Broker Fee: $%3. Final Cost: $%4.")
                                     .arg(businessName).arg(stockAmount).arg(brokerFee).arg(finalCost));

        // Update your_stocks to reflect the purchase
        your_stocks[businessName] += stockAmount; // Increase the stock count for the purchased business

        // Deduct the total cost (including broker fee) from the bank balance
        bank_balance -= finalCost;
        ui->BALANCE->setText(QString::number(bank_balance));

        // Optionally, mark the row as "Invested" (e.g., change background color)
        for (int col = 0; col < ui->STOCK_TABLE->columnCount(); ++col) {
            ui->STOCK_TABLE->item(currentRow, col)->setBackground(Qt::green);
        }
    }
}
