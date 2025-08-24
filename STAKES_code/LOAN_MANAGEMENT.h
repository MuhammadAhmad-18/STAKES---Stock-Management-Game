
void MainWindow::on_loanButton_clicked()
{

    // Create a dialog for loan options
    QDialog loanDialog(this);
    loanDialog.setWindowTitle("Loan Options");

    QVBoxLayout *layout = new QVBoxLayout(&loanDialog);

    // Display current balance
    QLabel *balanceLabel = new QLabel("Your Current Balance: $" + QString::number(bank_balance), this);
    layout->addWidget(balanceLabel);

    // SpinBox for loan amount
    QDoubleSpinBox *loanAmountSpinBox = new QDoubleSpinBox(this);
    loanAmountSpinBox->setMaximum(5000000);
    loanAmountSpinBox->setPrefix("$");
    layout->addWidget(new QLabel("Select Loan Amount:", this));
    layout->addWidget(loanAmountSpinBox);

    // ComboBox for loan duration
    QComboBox *loanDurationComboBox = new QComboBox(this);
    loanDurationComboBox->addItem("15 Days");
    loanDurationComboBox->addItem("1 Month");
    loanDurationComboBox->addItem("2 Months");
    layout->addWidget(new QLabel("Select Loan Duration:", this));
    layout->addWidget(loanDurationComboBox);

    // Button to calculate loan
    QPushButton *calculateButton = new QPushButton("Calculate Loan", this);
    layout->addWidget(calculateButton);

    // Connect the button click to a named slot
    connect(calculateButton, &QPushButton::clicked, this, [this, loanAmountSpinBox, loanDurationComboBox, &loanDialog]() {
        double loanAmount = loanAmountSpinBox->value();
        if (loanAmount > net_balance) {
            QMessageBox::warning(this,
                                 "Warning",
                                 "The STAKES bank found that your assets are not valuable enough to be considered as collateral.",
                                 QMessageBox::Ok);
        }
        else{
            calculateLoan(loanAmount, loanDurationComboBox->currentText(), &loanDialog);
        }
    });

    loanDialog.exec();
}

void MainWindow::calculateLoan(double loanAmount, const QString &selectedDuration, QDialog *dialog) {
    double taxRate = 0.05; // Example tax rate
    double interestRate = 0.03; // Example interest rate

    // Calculate payment based on selected duration
    double totalPayment;
    if (selectedDuration == "15 Days") {
        totalPayment = loanAmount + (loanAmount * interestRate * (15.0 / 365.0));
    } else if (selectedDuration == "1 Month") {
        totalPayment = loanAmount + (loanAmount * interestRate);
    } else if (selectedDuration == "2 Months") {
        totalPayment = loanAmount + (loanAmount * interestRate * 2);
    }

    double totalTax = totalPayment * taxRate;
    totalPayment += totalTax;

    // Confirmation dialog
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(dialog, "Confirm Loan",
                                  QString("Loan Amount: $%1\nTotal Payment (incl. tax): $%2\n\nDo you want to proceed?")
                                      .arg(loanAmount)
                                      .arg(totalPayment),
                                  QMessageBox::Yes | QMessageBox::No);


    if (reply == QMessageBox::Yes)
    {
        if(loanAmount>0){

            // Update bank balance and total loan taken
            total_loan_taken += loanAmount; // Add loan amount to total loan taken
            net_balance -= loanAmount ;
            bank_balance += loanAmount; // Add loan amount to bank balance
            loan_number = 1 ;
            ui->BALANCE->setText(QString::number(bank_balance));
            // Add loan record to loan table
            int daysRemaining = (selectedDuration == "15 Days") ? 15 : (selectedDuration == "1 Month") ? 30 : 60;
            QString status = "Active"; // Initially, the loan is active
            // Insert a new row in the loan table
            int rowCount = ui->LOAN_TABLE->rowCount();
            ui->LOAN_TABLE->insertRow(rowCount);
            ui->LOAN_TABLE->setItem(rowCount, 0, new QTableWidgetItem(QString::number(loanAmount))); // Loan Amount
            ui->LOAN_TABLE->setItem(rowCount, 1, new QTableWidgetItem(QString::number(totalPayment))); // Amount to be Paid
            ui->LOAN_TABLE->setItem(rowCount, 2, new QTableWidgetItem(QString::number(daysRemaining))); // Days Remaining
            ui->LOAN_TABLE->setItem(rowCount, 3, new QTableWidgetItem(status)); // Status

            loans << qMakePair(loanAmount, qMakePair(totalPayment, qMakePair(daysRemaining, status)));
            QMessageBox::information(dialog, "Loan Confirmed",
                                     QString("Loan of $%1 has been approved by the STAKES Bank .\nNew Balance: $%2")
                                         .arg(loanAmount)
                                         .arg(bank_balance));
        }
        else
            QMessageBox::information(dialog, "PLEASE SELECT AN AMOUNT",
                                     QString("A LOAN OF ZERO DOLLARS CAN'T BE APPROVED"));
    }
}

void MainWindow::on_REAPYMENT_clicked()
{

    int currentRow = ui->LOAN_TABLE->currentRow();

    // Check if a row is selected
    if (currentRow < 0) {
        qDebug() << "No row selected!";
        return; // Exit the function if no row is selected
    }

    // Access the item in the second column (index 1)
    QTableWidgetItem* item = ui->LOAN_TABLE->item(currentRow, 1);
    if (item) {
        float LOAN_PAYMENT_ = item->text().toFloat(); // Convert the text to float
        qDebug() << "Loan Payment:" << LOAN_PAYMENT_;

        // Proceed with the repayment logic, e.g., removing the loan
        // ...

        // Retrieve the details of the selected property from the table
        bank_balance = bank_balance - LOAN_PAYMENT_ ;
        total_loan_taken = total_loan_taken  - loans[currentRow].first ;
        loans.removeAt(currentRow);
        ui->LOAN_TABLE->removeRow(currentRow);
        ui->LOAN_TABLE->setRowCount(loans.size());
        ui->TOTAL_LOAN->setText(QString::number(total_loan_taken));
        ui->BALANCE->setText(QString::number(bank_balance));
        ui->REPUTATION->setText(QString::number(reputation));
    } else {
        qDebug() << "Item not found in the specified column!";
    }
}
