void saveGameState(int slot) {
    QString filename = "game_save_" + QString::number(slot) + ".txt";
    QFile file(filename);

    // Check if the file already exists and ask for confirmation to override
    if (file.exists()) {
        QMessageBox::StandardButton reply = QMessageBox::question(nullptr, "Override Save Slot",
                                                                  "This slot already exists. Do you want to override it?",
                                                                  QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::No) {
            return;  // Do not proceed with saving if the user doesn't want to override
        }
    }

    // Attempt to open the file for writing
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Cannot open file for writing!";
        return;
    }

    QTextStream out(&file);

    // Save your_stocks
    out << "your_stocks:\n";
    for (const auto& stock : your_stocks.toStdMap()) {
        out << stock.first << " " << stock.second << "\n";
    }

    // Save your_crypto_holdings
    out << "your_crypto_holdings:\n";
    for (const auto& crypto : your_crypto_holdings.toStdMap()) {
        out << crypto.first << " " << crypto.second << "\n";
    }

    // Save your_property_holdings
    out << "your_property_holdings:\n";
    for (const auto& property : your_property_holdings.toStdMap()) {
        out << property.first << " " << property.second.first << " " << property.second.second << "\n";
    }

    // Save days_owned
    out << "days_owned:\n";
    for (const auto& day : days_owned.toStdMap()) {
        out << day.first << " " << day.second << "\n";
    }

    // Save primitive values
    out << "bank_balance: " << bank_balance << "\n";
    out << "DAY_NUMBER: " << DAY_NUMBER << "\n";
    out << "total_loan_taken: " << total_loan_taken << "\n";
    out << "net_balance: " << net_balance << "\n";
    out << "loan_number: " << loan_number << "\n";
    out << "change_occured: " << change_occured << "\n";
    out << "countries_at_war_with: " << countries_at_war_with << "\n";
    out << "balancia: " << balancia << "\n";
    out << "country_health: " << country_health << "\n";
    out << "war_impact: " << war_impact << "\n";
    out << "overall_change_internal_chaos: " << overall_change_internal_chaos << "\n";
    out << "negative_news: " << negative_news << "\n";
    out << "reputation: " << reputation << "\n";
    out << "arrestProbability: " << arrestProbability << "\n";
    out << "number_of_petitions: " << number_of_petitions << "\n";

    // Save the news array
    out << "newsArray:\n";
    for (const QString& news : newsArray) {
        out << news << "\n";
    }

    // Save the for_list_companies
    out << "for_list_companies:\n";
    for (const QString& company : for_list_companies) {
        out << company << "\n";
    }

    // Save stock prices
    out << "stock_prices:\n";
    for (float price : stock_prices) {
        out << price << " ";
    }
    out << "\n";

    // Save crypto prices
    out << "cryptoPrices:\n";
    for (float price : cryptoPrices) {
        out << price << " ";
    }
    out << "\n";

    // Save loans
    out << "loans:\n";
    for ( const auto& loan : loans) {
        out << loan.first << " " << loan.second.first << " " << loan.second.second.first << " " << loan.second.second.second << "\n";
    }

    // Save diplomatic status of neighboring countries
    out << "neighboringCountriesDiplomaticStatus:\n";
    for (const auto& status : neighboringCountriesDiplomaticStatus) {
        out << status.first << " " << status.second << "\n";
    }

    // Save diplomatic status of countries excluding neighbors
    out << "countriesExcludingNeighborsDiplomaticStatus:\n";
    for (const auto& status : countriesExcludingNeighborsDiplomaticStatus) {
        out << status.first << " " << status.second << "\n";
    }

    qDebug() << "SAVE COMPLETE";
    file.close();
}

void loadGameState(int slot,Ui::MainWindow* ui) {
    qDebug() << "aloo_shora";
    QString filename = "game_save_" + QString::number(slot) + ".txt";
    QFile file(filename);

    // Attempt to open the file
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(nullptr, "Load Error", "Failed to open file for loading.");
        return;
    }

    QTextStream in(&file);
    QString line;

    // Variables to hold the bank balance and day number
    float tempBankBalance = 0.0f;
    int tempDayNumber = 0;

    // Read and extract information
    while (!in.atEnd()) {
        line = in.readLine().trimmed();

        // Process primitive data
        if (line.startsWith("bank_balance:")) {
            tempBankBalance = line.split(":")[1].toFloat();
        } else if (line.startsWith("DAY_NUMBER:")) {
            tempDayNumber = line.split(":")[1].toInt();
        }
    }

    // Show the bank balance and DAY_NUMBER from the loaded slot and ask for confirmation
    QString confirmationMessage = QString("You are about to load a saved game from Slot %1.\n"
                                          "Bank Balance: $%2\nDay Number: %3\n\nDo you want to continue?")
                                      .arg(slot)
                                      .arg(tempBankBalance)
                                      .arg(tempDayNumber);

    QMessageBox::StandardButton reply = QMessageBox::question(nullptr, "Load Game Confirmation", confirmationMessage,
                                                              QMessageBox::Yes | QMessageBox::No, QMessageBox::No);

    if (reply == QMessageBox::No) {
        // Cancel the load if the user clicked 'No'
        file.close();
        return;
    }

    // Reset the file cursor to the beginning to read again
    file.seek(0);

    // Read and extract information
    while (!in.atEnd()) {
        line = in.readLine().trimmed();

        // Process primitive data
        if (line.startsWith("bank_balance:")) {
            bank_balance = line.split(":")[1].toFloat();
            qDebug() << "Loaded bank_balance:" << bank_balance; // Debug output
        } else if (line.startsWith("DAY_NUMBER:")) {
            DAY_NUMBER = line.split(":")[1].toInt();
            qDebug() << "Loaded DAY_NUMBER:" << DAY_NUMBER; // Debug output
        } else if (line.startsWith("total_loan_taken:")) {
            total_loan_taken = line.split(":")[1].toFloat();
        } else if (line.startsWith("net_balance:")) {
            net_balance = line.split(":")[1].toFloat();
        } else if (line.startsWith("loan_number:")) {
            loan_number = line.split(":")[1].toInt();
        } else if (line.startsWith("change_occured:")) {
            change_occured = line.split(":")[1].toInt();
        } else if (line.startsWith("countries_at_war_with:")) {
            countries_at_war_with = line.split(":")[1].toInt();
        } else if (line.startsWith("balancia:")) {
            balancia = line.split(":")[1].toInt();
        } else if (line.startsWith("country_health:")) {
            country_health = line.split(":")[1].toInt();
        } else if (line.startsWith("war_impact:")) {
            war_impact = line.split(":")[1].toFloat();
        } else if (line.startsWith("overall_change_internal_chaos:")) {
            overall_change_internal_chaos = line.split(":")[1].toFloat();
        } else if (line.startsWith("negative_news:")) {
            negative_news = line.split(":")[1] == "true";
        } else if (line.startsWith("reputation:")) {
            reputation = line.split(":")[1].toInt();
        } else if (line.startsWith("arrestProbability:")) {
            arrestProbability = line.split(":")[1].toInt();
        } else if (line.startsWith("number_of_petitions:")) {
            number_of_petitions = line.split(":")[1].toInt();
        } else if (line.startsWith("jugad:")) {
            jugad = line.split(":")[1].toInt();
        } else if (line.startsWith("selectedNews:")) {
            selectedNews = line.split(":")[1];
        } else if (line.startsWith("your_stocks:")) {
            // Handle your_stocks section
            while (!in.atEnd()) {
                line = in.readLine().trimmed();
                if (line.isEmpty() || line.endsWith(":")) break; // End of section
                QStringList parts = line.split(" ");
                if (parts.size() == 2) {
                    your_stocks.insert(parts[0], parts[1].toInt());
                }
            }
        } else if (line.startsWith("your_crypto_holdings:")) {
            // Handle your_crypto_holdings section
            while (!in.atEnd()) {
                line = in.readLine().trimmed();
                if (line.isEmpty() || line.endsWith(":")) break; // End of section
                QStringList parts = line.split(" ");
                if (parts.size() == 2) {
                    your_crypto_holdings.insert(parts[0], parts[1].toInt());
                }
            }
        } else if (line.startsWith("your_property_holdings:")) {
            // Handle your_property_holdings section
            while (!in.atEnd()) {
                line = in.readLine().trimmed();
                if (line.isEmpty() || line.endsWith(":")) break; // End of section
                QStringList parts = line.split(" ");
                if (parts.size() == 3) {
                    your_property_holdings .insert(parts[0], QPair<int, int>(parts[1].toInt(), parts[2].toInt()));
                }
            }
        } else if (line.startsWith("days_owned:")) {
            // Handle days_owned section
            while (!in.atEnd()) {
                line = in.readLine().trimmed();
                if (line.isEmpty() || line.endsWith(":")) break; // End of section
                QStringList parts = line.split(" ");
                if (parts.size() == 2) {
                    days_owned.insert(parts[0], parts[1].toInt());
                }
            }
        } else if (line.startsWith("newsArray:")) {
            // Handle newsArray section
            while (!in.atEnd()) {
                line = in.readLine().trimmed();
                if (line.isEmpty() || line.endsWith(":")) break; // End of section
                newsArray.append(line);
            }
        } else if (line.startsWith("for_list_companies:")) {
            // Handle for_list_companies section
            while (!in.atEnd()) {
                line = in.readLine().trimmed();
                if (line.isEmpty() || line.endsWith(":")) break; // End of section
                for_list_companies.append(line);
            }
        } else if (line.startsWith("stock_prices:")) {
            int stock_prices_count = 0; // To keep track of the number of elements added

            // Handle stock_prices section
            while (!in.atEnd()) {
                line = in.readLine().trimmed();
                if (line.isEmpty() || line.endsWith(":")) break; // End of section
                QStringList parts = line.split(" ");
                for (const QString& part : parts) {
                    if (stock_prices_count < 30) { // Ensure we don't exceed the array size
                        stock_prices[stock_prices_count++] = part.toFloat();
                    } else {
                        qWarning() << "Exceeded maximum stock prices limit!";
                        break; // Stop adding if we exceed the limit
                    }
                }
            }
        } else if (line.startsWith("cryptoPrices:")) {
            int cryptoPrices_count = 0; // To keep track of the number of elements added

            // Handle cryptoPrices section
            while (!in.atEnd()) {
                line = in.readLine().trimmed();
                if (line.isEmpty() || line.endsWith(":")) break; // End of section
                QStringList parts = line.split(" ");
                for (const QString& part : parts) {
                    if (cryptoPrices_count < 30) { // Ensure we don't exceed the array size
                        cryptoPrices[cryptoPrices_count++] = part.toFloat();
                    } else {
                        qWarning() << "Exceeded maximum crypto prices limit!";
                        break; // Stop adding if we exceed the limit
                    }
                }
            }
        } else if (line.startsWith("loans:")) {
            // Handle loans section
            while (!in.atEnd()) {
                line = in.readLine().trimmed();
                if (line.isEmpty() || line.endsWith(":")) break; // End of section
                QStringList parts = line.split(" ");
                if (parts.size() == 4) {
                    loans.append(QPair<double, QPair<double, QPair<int, QString>>>(
                        parts[0].toDouble(),
                        QPair<double, QPair<int, QString>>(
                            parts[1].toDouble(),
                            QPair<int, QString>(parts[2].toInt(), parts[3])
                            )
                        ));
                }
            }
        } else if (line.startsWith("neighboringCountriesDiplomaticStatus:")) {
            // Handle neighboringCountriesDiplomaticStatus section
            while (!in.atEnd()) {
                line = in.readLine().trimmed();
                if (line.isEmpty() || line.endsWith(":")) break; // End of section
                QStringList parts = line.split(" ");
                if (parts.size() == 2) {
                    neighboringCountriesDiplomaticStatus.append(QPair<QString, float>(parts[0], parts[1].toFloat()));
                }
            }
        } else if (line.startsWith("countriesExcludingNeighborsDiplomaticStatus:")) {
            // Handle countriesExcludingNeighborsDiplomaticStatus section
            while (!in.atEnd()) {
                line = in.readLine().trimmed();
                if (line.isEmpty() || line.endsWith(":")) break; // End of section
                QStringList parts = line.split(" ");
                if (parts.size() == 2) {
                    countriesExcludingNeighborsDiplomaticStatus.append(QPair<QString, float>(parts[0], parts[1].toFloat()));
                }
            }
        }
    }

    file.close();
    QMessageBox::information(nullptr,"SLOT LOADED SUCCESSFULLY","THE DESIRED SLOT HAS BEEN LOADED SUCCESFULLY");
    fill_data(ui);

}
