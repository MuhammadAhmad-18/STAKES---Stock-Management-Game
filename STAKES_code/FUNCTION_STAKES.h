

void checkAndUpdateBalance( const QMap<QString, QPair<int, int>>& your_property_holdings , const QList<QPair<QString, QPair<float, float>>>& properties, const QString& propertyName) {

    const QPair<int, int>& propertyStatus =  your_property_holdings[propertyName] ;

    // Check if the first int is 1
    if (propertyStatus.first == 1) {
        // Check if the second int is completely divisible by 5
        if (propertyStatus.second % 30 == 0) {
            // Find the rent associated with the property
            for (const auto& property : properties) {
                if (property.first == propertyName) {
                    // Get the rent (last float in the QPair)
                    float rent = property.second.second; // Assuming the rent is the second float in the pair
                    bank_balance += rent; // Increase bank balance by the rent
                    qDebug() << "Bank balance updated. New balance:" << bank_balance;
                    return; // Exit after updating
                }
            }
            // If property not found
            qDebug() << "Property not found:" << propertyName;
        } else {
            qDebug() << "The second integer is not divisible by 30.";
        }
    } else {
        qDebug() << "The first integer is not 1.";
    }
}

// Function to generate realistic diplomatic scenarios
void generateDiplomaticScenario(
    QList<QPair<QString, float>>& borderingCountries,
    QList<QPair<QString, float>>& nonBorderingCountries,
    QList<QPair<QString, float>>& positiveBorderingScenarios,
    QList<QPair<QString, float>>& negativeBorderingScenarios,
    QList<QPair<QString, float>>& positiveNonBorderingScenarios,
    QList<QPair<QString, float>>& negativeNonBorderingScenarios,
    QStringList& newsArray)
{QRandomGenerator randGen;
    randGen.seed(QRandomGenerator::global()->generate()); // Ensures fresh seed

    // Clear the news array to avoid displaying old news
    newsArray.clear();

    // Ensure that the lists are not empty
    if (borderingCountries.isEmpty() || nonBorderingCountries.isEmpty()) {
        qDebug() << "One or more countries lists are empty!";
        return;
    }
    if (positiveBorderingScenarios.isEmpty() || negativeBorderingScenarios.isEmpty() ||
        positiveNonBorderingScenarios.isEmpty() || negativeNonBorderingScenarios.isEmpty()) {
        qDebug() << "One or more scenario lists are empty!";
        return;
    }

    // Randomly select one bordering country
    int borderIndex = randGen.bounded(borderingCountries.size());
    QString borderingCountry = borderingCountries[borderIndex].first;
    float currentBorderRelation = borderingCountries[borderIndex].second;

    // Debug: Check the initial relation value
    qDebug() << "Selected bordering country: " << borderingCountry;
    qDebug() << "Initial Border Relation: " << currentBorderRelation;

    // Randomly select two non-bordering countries (ensure no duplicates)
    int nonBorderIndex1 = randGen.bounded(nonBorderingCountries.size());
    int nonBorderIndex2;
    do {
        nonBorderIndex2 = randGen.bounded(nonBorderingCountries.size());
    } while (nonBorderIndex1 == nonBorderIndex2); // Ensure two different non-bordering countries

    QString nonBorderCountry1 = nonBorderingCountries[nonBorderIndex1].first;
    QString nonBorderCountry2 = nonBorderingCountries[nonBorderIndex2].first;

    // Get current relations for non-bordering countries
    float currentNonBorderRelation1 = nonBorderingCountries[nonBorderIndex1].second;
    float currentNonBorderRelation2 = nonBorderingCountries[nonBorderIndex2].second;

    // Debug: Check initial relations for non-bordering countries
    qDebug() << "Selected non-bordering countries: " << nonBorderCountry1 << " and " << nonBorderCountry2;
    qDebug() << "Initial non-border relations: " << currentNonBorderRelation1 << ", " << currentNonBorderRelation2;

    // Select scenarios based on the relation
    bool chooseNegativeBorder = (randGen.generate() % 100) < (100 - currentBorderRelation);
    QList<QPair<QString, float>> *chosenBorderScenarios = chooseNegativeBorder ? &negativeBorderingScenarios : &positiveBorderingScenarios;
    int borderScenarioIndex = randGen.bounded(chosenBorderScenarios->size());
    QString chosenBorderScenario = (*chosenBorderScenarios)[borderScenarioIndex].first;
    float borderScenarioImpact = (*chosenBorderScenarios)[borderScenarioIndex].second;

    bool chooseNegativeNonBorder1 = (randGen.generate() % 100) < (100 - currentNonBorderRelation1);
    QList<QPair<QString, float>> *chosenNonBorderScenarios1 = chooseNegativeNonBorder1 ? &negativeNonBorderingScenarios : &positiveNonBorderingScenarios;
    int nonBorderScenarioIndex1 = randGen.bounded(chosenNonBorderScenarios1->size());
    QString chosenNonBorderScenario1 = (*chosenNonBorderScenarios1)[nonBorderScenarioIndex1].first;
    float nonBorderScenarioImpact1 = (*chosenNonBorderScenarios1)[nonBorderScenarioIndex1].second;

    bool chooseNegativeNonBorder2 = (randGen.generate() % 100) < (100 - currentNonBorderRelation2);
    QList<QPair<QString, float>> *chosenNonBorderScenarios2 = chooseNegativeNonBorder2 ? &negativeNonBorderingScenarios : &positiveNonBorderingScenarios;
    int nonBorderScenarioIndex2 = randGen.bounded(chosenNonBorderScenarios2->size());
    QString chosenNonBorderScenario2 = (*chosenNonBorderScenarios2)[nonBorderScenarioIndex2].first;
    float nonBorderScenarioImpact2 = (*chosenNonBorderScenarios2)[nonBorderScenarioIndex2].second;

    // Apply the scenario impact to relations for the bordering country and non-bordering countries
    borderingCountries[borderIndex].second += borderScenarioImpact;
    nonBorderingCountries[nonBorderIndex1].second += nonBorderScenarioImpact1;
    nonBorderingCountries[nonBorderIndex2].second += nonBorderScenarioImpact2;

    // Debug: Check updated relations
    qDebug() << "Updated relations:";
    qDebug() << "Border country relation: " << borderingCountries[borderIndex].second;
    qDebug() << "Non-border country 1 relation: " << nonBorderingCountries[nonBorderIndex1].second;
    qDebug() << "Non-border country 2 relation: " << nonBorderingCountries[nonBorderIndex2].second;

    // Generate news for bordering country
    if (borderingCountries[borderIndex].second < 0) {
        borderingCountries[borderIndex].second = 0; // Minimum relation is zero
        newsArray.append(chosenBorderScenario + " (" + borderingCountry + ")");
    } else {
        newsArray.append(chosenBorderScenario + " (" + borderingCountry + ")");
    }

    // Generate news for non-bordering country 1
    if (nonBorderingCountries[nonBorderIndex1].second < 0) {
        nonBorderingCountries[nonBorderIndex1].second = 0; // Minimum relation is zero
        newsArray.append(chosenNonBorderScenario1 + " (" + nonBorderCountry1 + ")");
    } else {
        newsArray.append(chosenNonBorderScenario1 + " (" + nonBorderCountry1 + ")");
    }

    // Generate news for non-bordering country 2
    if (nonBorderingCountries[nonBorderIndex2].second < 0) {
        nonBorderingCountries[nonBorderIndex2].second = 0; // Minimum relation is zero
        newsArray.append(chosenNonBorderScenario2 + " (" + nonBorderCountry2 + ")");
    } else {
        newsArray.append(chosenNonBorderScenario2 + " (" + nonBorderCountry2 + ")");
    }

    // Example: Output the new diplomatic relations for debugging or logging
    qDebug() << "Diplomatic Relations Update:";
    qDebug() << borderingCountry + " Relations: " + QString::number(borderingCountries[borderIndex].second);
    qDebug() << nonBorderCountry1 + " Relations: " + QString::number(nonBorderingCountries[nonBorderIndex1].second);
    qDebug() << nonBorderCountry2 + " Relations: " + QString::number(nonBorderingCountries[nonBorderIndex2].second);

}

void seedRandomGenerator() {
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned int>(time(0)));
        seeded = true;
    }
}

// Function to get a random index from a list
int getRandomIndex(int maxIndex) {
    if (maxIndex <= 0) {
        return -1;  // Return -1 to indicate an error if the list is empty
    }
    return rand() % maxIndex;
}

// Function to select a random news item based on probabilities
Scenario selectRandomNews(bool negative_news) {
    Scenario selectedScenario;

    // Generate a random number between 0 and 100 to simulate probability
    int randProbability = rand() % 100;

    // Select news based on the probabilities
    if (negative_news) {
        // 75% chance for negative news, 25% for positive
        if (randProbability < 75 && !negativeScenarios.isEmpty()) {
            int randomIndex = getRandomIndex(negativeScenarios.size());
            if (randomIndex != -1) {
                selectedScenario = negativeScenarios[randomIndex];
            }
        } else if (!positiveScenarios.isEmpty()) {
            int randomIndex = getRandomIndex(positiveScenarios.size());
            if (randomIndex != -1) {
                selectedScenario = positiveScenarios[randomIndex];
            }
        }
    } else {
        // 80% chance for positive news, 20% for negative
        if (randProbability < 80 && !positiveScenarios.isEmpty()) {
            int randomIndex = getRandomIndex(positiveScenarios.size());
            if (randomIndex != -1) {
                selectedScenario = positiveScenarios[randomIndex];
            }
        } else if (!negativeScenarios.isEmpty()) {
            int randomIndex = getRandomIndex(negativeScenarios.size());
            if (randomIndex != -1) {
                selectedScenario = negativeScenarios[randomIndex];
            }
        }
    }

    return selectedScenario;
}

// Function to select news and calculate the overall change
void selectNewsAndCalculateChange(bool negative_news) {
    overall_change_internal_chaos = 0.0f; // Reset overall change

    // Seed the random number generator (called only once)
    seedRandomGenerator();

    QList<Scenario> selectedScenarios;

    for (int i = 0; i < 3; ++i) {
        // Select news based on the probabilities and add it to the list
        Scenario selectedScenario = selectRandomNews(negative_news);

        // Debug print to check if the scenario data is valid
        qDebug() << "Selected Scenario Headline: " << selectedScenario.headline;
        qDebug() << "Selected Scenario Change: " << selectedScenario.change;

        selectedScenarios.append(selectedScenario);
        overall_change_internal_chaos += selectedScenario.change;

        // Append the news to the global newsText
        newsText += "Headline: " + selectedScenario.headline +"\n";
    }

    // Update negative_news based on the overall change (before using it again)
    if (overall_change_internal_chaos < 0) {
        negative_news = true;
    }

    // Print the overall change and news text for debugging
    qDebug() << "Overall Change: " << overall_change_internal_chaos;
    qDebug() << "News Text: " << newsText;
}
void updateStockPrices(QList<QPair<QString, QPair<float, float>>>& companies) {
    // Iterate over all companies and adjust stock prices based on the overall market change and their risk factor
    for (int i = 0; i < companies.size(); ++i) {
        // Extract company data
        QString companyName = companies[i].first;
        float stockPrice = companies[i].second.first;  // The stock price is the first element of the inner pair
        float riskFactor = companies[i].second.second; // The risk factor is the second element of the inner pair

        // Calculate the price change based on the risk factor and the overall market change
        float priceChange = stockPrice * (overall_change_internal_chaos * riskFactor);

        // Update the stock price
        stockPrice += priceChange;

        // Print the updated stock price
        qDebug() << "Company: " << companyName
                 << "Old Price: " << companies[i].second.first
                 << "New Price: " << stockPrice
                 << "Risk Factor: " << riskFactor
                 << "Price Change: " << priceChange;

        // Update the stock price in the list
        companies[i].second.first = stockPrice;
    }
}

void stock_simulate(QList<QPair<QString, QPair<float, float>>>& companies) {


    // Simulate stock price changes based on risk factor for each company
    for (int i = 0; i < companies.size(); ++i) {
        float riskFactor = companies[i].second.second;
        float stockPrice = companies[i].second.first;

        // Simulate daily stock price fluctuation based on risk factor
        // Generate a random float between -stockPrice * riskFactor and stockPrice * riskFactor
        float fluctuationRange = stockPrice * riskFactor;
        float dailyFluctuation = QRandomGenerator::global()->generate() / float(UINT_MAX) * (2 * fluctuationRange) - fluctuationRange;

        stockPrice += dailyFluctuation;

        // Ensure stock price doesn't go below 0
        if (stockPrice < 0) stockPrice = 0;

        // Update stock price in the list
        stock_prices[i] = stockPrice;

        qDebug() << stock_prices[i] << "new stock price: " << stockPrice;
    }

    if(countries_at_war_with >= 1)
    {
        for (int i = 0; i < companies.size(); ++i)
        {
            stock_prices[i] = stock_prices[i]-stock_prices[i]*war_impact;

        }
    }

}

void simulate_news_based_change(QList<QPair< int, QPair<QString , double >>> news , int indexes_of_companies[],int size = 4 )
{

    int first_stock = news[indexes_of_companies[0]].first  - 1 ;
    int second_stock = news[indexes_of_companies[1]].first - 1 ;
    int third_stock = news[indexes_of_companies[2]].first  - 1 ;
    int fourth_stock = news[indexes_of_companies[3]].first - 1 ;



    float stockPrice_1 = stock_prices[first_stock];
    float stockPrice_2 = stock_prices[second_stock];
    float stockPrice_3 = stock_prices[third_stock];
    float stockPrice_4 = stock_prices[fourth_stock];


    double change_1 = news[indexes_of_companies[0]].second.second;
    double change_2 = news[indexes_of_companies[1]].second.second;
    double change_3 = news[indexes_of_companies[2]].second.second;
    double change_4 = news[indexes_of_companies[3]].second.second;

    stockPrice_1 = stockPrice_1 + (stockPrice_1)*(change_1/100);
    stockPrice_2 = stockPrice_2 + (stockPrice_2)*(change_2/100);
    stockPrice_3 = stockPrice_3 + (stockPrice_3)*(change_3/100);
    stockPrice_4 = stockPrice_4 + (stockPrice_4)*(change_4/100);

    if (stockPrice_1 < 0)
        stockPrice_1 = 0;

    if (stockPrice_2 < 0)
        stockPrice_2 = 0;

    if (stockPrice_3 < 0)
        stockPrice_3 = 0;

    if (stockPrice_4 < 0)
        stockPrice_4 = 0;


    stock_prices[first_stock] = stockPrice_1 ;
    stock_prices[second_stock] = stockPrice_2 ;
    stock_prices[third_stock] = stockPrice_3 ;
    stock_prices[fourth_stock] = stockPrice_4 ;

}
void simulateCryptoChanges(    QList<QPair<QString,QPair<float, float>>>& cryptos) {
    // Simulate price changes based on risk factor
    for (int i = 0; i < cryptos.size(); ++i) {
        float riskFactor = cryptos[i].second.second;
        float cryptoPrice = cryptos[i].second.first;

        // Generate a random fluctuation within the range of +/- crypto price * risk factor
        float fluctuationRange = cryptoPrice * riskFactor;
        float dailyFluctuation = QRandomGenerator::global()->generate() / float(UINT_MAX) * (2 * fluctuationRange) - fluctuationRange;

        cryptoPrice += dailyFluctuation;

        // Ensure price doesn't go below 0
        if (cryptoPrice < 0) cryptoPrice = 0;

        // Update price in the list
        cryptoPrices[i] = cryptoPrice;

        qDebug() << cryptoPrices << "new price: " << cryptoPrice;
    }
}

void sortCompanies(const QList<QPair<QString, QPair<float, float>>>& companies, QList<QPair<QString, QPair<float, float>>>& companies_table) {
    // Copy the original list to a new list
    companies_table = companies;

    // Sort the copied list based on stock price (descending order)
    std::sort(companies_table.begin(), companies_table.end(), [](const QPair<QString, QPair<float, float>>& a, const QPair<QString, QPair<float, float>>& b) {
        return a.second.first > b.second.first; // Sort by stock price in descending order
    });
}

void updateRealEstateMarket()
{
    // Define the pace at which the market increases each round
    const float marketGrowthRate = 0.01f;  // 1% increase per update (adjust as needed)

    // Check if there is a war and set the war impact on property prices
    float adjustedMarketGrowthRate = marketGrowthRate;
    if (war_impact != 0) {
        // If there's war, reduce or increase the market based on war_impact
        adjustedMarketGrowthRate -= war_impact;  // Subtract the war impact from the market growth
    }

    // Loop through all the properties and update their prices
    for (int i = 0; i < properties.size(); ++i) {
        QString propertyName = properties[i].first;
        QPair<float, float> propertyData = properties[i].second;

        // Get the current property base price and its growth modifier
        float basePrice = propertyData.first;
        float priceModifier = propertyData.second;

        // Increase the base price at a constant pace, adjusted for war impact
        basePrice += basePrice * adjustedMarketGrowthRate;

        // Update the property price in the list
        properties[i].second.first = basePrice;

        // Optionally, you can also adjust the price modifier (e.g., to reflect more volatility)
        priceModifier += adjustedMarketGrowthRate * 0.1f;  // Example: increase volatility slightly
        properties[i].second.second = priceModifier;

        // Optionally, you could log the change or show a message about the updated price
        qDebug() << QString("Updated property: %1, New Price: %2")
                        .arg(propertyName).arg(basePrice);
    }

}

void fill_data(Ui::MainWindow* ui){
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



    for (int i = 0; i < loans.size(); ++i) {
        const auto &loan = loans[i];

        // Set the values in the table
        ui->LOAN_TABLE->setItem(i, 0, new QTableWidgetItem(QString::number(loan.first))); // Loan Amount
        ui->LOAN_TABLE->setItem(i, 1, new QTableWidgetItem(QString::number(loan.second.first))); // TO BE PAID
        ui->LOAN_TABLE->setItem(i, 2, new QTableWidgetItem(QString::number(loan.second.second.first))); // Term
        ui->LOAN_TABLE->setItem(i, 3, new QTableWidgetItem(loan.second.second.second)); // STATUS
    }

    net_balance = (bank_balance - total_loan_taken);

    QList<QPair<QString, QPair<float, float>>> companies;

    for (int i = 0; i < 30; ++i) {
        companies.append(QPair<QString, QPair<float, float>>(company_names[i], QPair<float, float>(stock_prices[i], risk_factors[i])));
    }

    companies.clear();

    for (int i = 0; i < 30; ++i) {
        companies.append(QPair<QString, QPair<float, float>>(company_names[i], QPair<float, float>(stock_prices[i], risk_factors[i])));
    }
    // Populate the table with company data, stock prices, and risk factors
    for (int i = 0; i < companies.size(); ++i) {
        ui->STOCK_TABLE->setItem(i, 0, new QTableWidgetItem(companies[i].first)); // Company Name
        ui->STOCK_TABLE->setItem(i, 1, new QTableWidgetItem(QString::number(companies[i].second.first, 'f', 2))); // Stock Price
        ui->STOCK_TABLE->setItem(i, 2, new QTableWidgetItem(QString::number(companies[i].second.second, 'f', 4))); // Risk Factor
    }
    ui->STOCK_TABLE->resizeColumnsToContents();
    ui->NEWS->setPlainText(newsText);
    QList<QPair<QString, QPair<float, float>>> cryptos;
    for (int i = 0; i < 30; ++i) {
        cryptos.append(QPair<QString, QPair<float, float>>(cryptoNames[i], QPair<float, float>(cryptoPrices[i], cryptoRiskFactors[i])));
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




}
