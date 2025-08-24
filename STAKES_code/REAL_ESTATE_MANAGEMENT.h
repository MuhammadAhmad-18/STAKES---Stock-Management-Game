void MainWindow::on_BUY_REAL_ESTATE_clicked()
{
    // Get the index of the currently selected row
    int currentRow = ui->REAL_ESTATE->currentRow();
    qDebug() << "Current Row:" << currentRow; // Debug output

    // Check if any row is selected
    if (currentRow == -1) {
        QMessageBox::warning(this, "Investment", "No row is selected to invest in.");
        return;
    }

    // Retrieve the details of the selected property from the table
    QString propertyName = ui->REAL_ESTATE->item(currentRow, 0)->text(); // Property name
    QString priceText = ui->REAL_ESTATE->item(currentRow, 1)->text();   // Property price
    QString location = ui->REAL_ESTATE->item(currentRow, 2)->text();     // Property location

    // Check if priceText is valid
    if (priceText.isEmpty()) {
        QMessageBox::warning(this, "Error", "Property price is not available.");
        return;
    }

    float propertyPrice = priceText.toFloat(); // Property price
    qDebug() << "Property Price:" << propertyPrice; // Debug output

    // Assuming a property tax rate of 1%
    float propertyTaxRate = 0.05f;
    float propertyTax = propertyPrice * propertyTaxRate;
    qDebug() << "Property Tax:" << propertyTax;

    // Assuming a broker fee rate of 2%
    float brokerFeeRate = 0.02f;
    float brokerFee = propertyPrice * brokerFeeRate;
    qDebug() << "Broker Fee:" << brokerFee;

    // Calculate the total cost including property tax and broker fee
    float totalCost = propertyPrice + propertyTax + brokerFee;
    qDebug() << "Total Cost (with Tax & Broker Fee):" << totalCost;

    QPair<int, int> Values = your_property_holdings[propertyName];

    // Check if the count (first element of the pair) is greater than 0
    if (Values.first > 0) {
        QMessageBox::warning(this, "Already Purchased",
                             QString("You have already purchased %1.").arg(propertyName));
        return; // Prevent further purchases of the same property
    }

    // Confirm investment for a single unit
    if (QMessageBox::question(this, "Confirm Investment",
                              QString("Do you want to invest in %1?\nPROPERTY PRICE: $%2\nPROPERTY TAX: $%3\nBROKER FEE: $%4\nTOTAL COST: $%5")
                                  .arg(propertyName).arg(propertyPrice).arg(propertyTax).arg(brokerFee).arg(totalCost)) == QMessageBox::Yes) {

        // Check if the user has sufficient bank balance
        if (totalCost > bank_balance) {
            QMessageBox::warning(this, "Insufficient Funds",
                                 QString("You do not have enough funds to buy %1.\nTotal cost: $%2\nYour balance: $%3")
                                     .arg(propertyName).arg(totalCost).arg(bank_balance));
            return;
        }

        // Display success message
        QMessageBox::information(this, "Investment Successful",
                                 QString("You have successfully invested in %1.").arg(propertyName));

        // Retrieve the current value (QPair<int, int>)
        QPair<int, int> currentValues = your_property_holdings[propertyName];

        // Decrease the count in the first integer
        currentValues.first = 1;
        currentValues.second = 1; // Assuming this represents ownership status or other values
        // Update the map with the new values
        your_property_holdings[propertyName] = currentValues;

        // Deduct the total cost (including tax and broker fee) from the bank balance
        bank_balance -= totalCost;
        ui->BALANCE->setText(QString::number(bank_balance));

        // Mark the row as "Invested" (e.g., change background color)
        for (int col = 0; col < ui->REAL_ESTATE->columnCount(); ++col) {
            ui->REAL_ESTATE->item(currentRow, col)->setBackground(Qt::green);
        }
    }
}
void MainWindow::on_SELL_REAL_ESTATE_clicked()
{
    // Get the index of the currently selected row
    int currentRow = ui->REAL_ESTATE->currentRow();
    qDebug() << "Current Row:" << currentRow; // Debug output

    // Check if any row is selected
    if (currentRow == -1) {
        QMessageBox::warning(this, "Investment", "No row is selected to sell.");
        return;
    }

    // Retrieve the details of the selected property from the table
    QString propertyName = ui->REAL_ESTATE->item(currentRow, 0)->text(); // Property name
    QString priceText = ui->REAL_ESTATE->item(currentRow, 1)->text();   // Property price
    QString rent = ui->REAL_ESTATE->item(currentRow, 2)->text();        // Property rent

    // Check if priceText is valid
    if (priceText.isEmpty()) {
        QMessageBox::warning(this, "Error", "Property price is not available.");
        return;
    }

    float propertyPrice = priceText.toFloat(); // Property price
    qDebug() << "Property Price:" << propertyPrice; // Debug output

    // Assuming a property tax rate of 1% (same as when buying)
    float propertyTaxRate = 0.05f;
    float propertyTax = propertyPrice * propertyTaxRate;
    qDebug() << "Property Tax Paid:" << propertyTax;

    // Assuming a broker fee rate of 2%
    float brokerFeeRate = 0.02f;
    float brokerFee = propertyPrice * brokerFeeRate;
    qDebug() << "Broker Fee:" << brokerFee;

    // Retrieve the current property values (QPair<int, int>)
    QPair<int, int> Values = your_property_holdings[propertyName];

    // Check if the user owns the property
    if (Values.first == 0) {
        QMessageBox::warning(this, "Not Owned",
                             QString("You do not own %1.").arg(propertyName));
        return; // Prevent selling a property that the user does not own
    }

    // Confirm sale for a single unit
    if (QMessageBox::question(this, "Confirm Sale",
                              QString("Do you want to sell %1?\nPROPERTY PRICE: $%2\nRENT: %3\nPROPERTY TAX PAID: $%4\nBROKER FEE: $%5")
                                  .arg(propertyName).arg(propertyPrice).arg(rent).arg(propertyTax).arg(brokerFee)) == QMessageBox::Yes) {

        // Display success message
        QMessageBox::information(this, "Sale Successful",
                                 QString("You have successfully sold %1.").arg(propertyName));

        // Update your_property_holdings to reflect the sale

        // Retrieve the current value (QPair<int, int>)
        QPair<int, int> currentValues = your_property_holdings[propertyName];

        // Decrease the count in the first integer (i.e., set it to 0 to indicate no ownership)
        currentValues.first = 0;
        currentValues.second = 0; // Assuming this indicates the property is no longer owned
        // Update the map with the new values
        your_property_holdings[propertyName] = currentValues;

        // Add the total revenue from the sale, adjusted by the broker fee and property tax, to the bank balance
        bank_balance += (propertyPrice - propertyTax - brokerFee); // Deduct both tax and broker fee from the sale price
        ui->BALANCE->setText(QString::number(bank_balance));

        // Optionally, mark the row as "Not Invested" (e.g., change background color back to default)
        for (int col = 0; col < ui->REAL_ESTATE->columnCount(); ++col) {
            ui->REAL_ESTATE->item(currentRow, col)->setBackground(Qt::white); // Change back to default color
        }
    }
}

