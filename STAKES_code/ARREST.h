void checkReputation(float reputation,QWidget *parent);
void filePetition(QWidget *parent);
void chooseLawyer(QWidget *parent);

// Function to handle reputation check and arrest
void checkReputation(float reputation,QWidget *parent) {

    // Round the float value to nearest integer
    int roundedReputation = static_cast<int>(std::round(reputation));

    switch (roundedReputation) {
    case 30: arrestProbability = 1; break;  // 1% chance of arrest
    case 29: arrestProbability = 2; break;  // 2% chance of arrest
    case 28: arrestProbability = 3; break;  // 3% chance of arrest
    case 27: arrestProbability = 4; break;  // 4% chance of arrest
    case 26: arrestProbability = 5; break;  // 5% chance of arrest
    case 25: arrestProbability = 6; break;  // 6% chance of arrest
    case 24: arrestProbability = 7; break;  // 7% chance of arrest
    case 23: arrestProbability = 8; break;  // 8% chance of arrest
    case 22: arrestProbability = 9; break;  // 9% chance of arrest
    case 21: arrestProbability = 10; break; // 10% chance of arrest
    case 20: arrestProbability = 11; break; // 11% chance of arrest
    case 19: arrestProbability = 12; break; // 12% chance of arrest
    case 18: arrestProbability = 13; break; // 13% chance of arrest
    case 17: arrestProbability = 14; break; // 14% chance of arrest
    case 16: arrestProbability = 15; break; // 15% chance of arrest
    case 15: arrestProbability = 16; break; // 16% chance of arrest
    case 14: arrestProbability = 17; break; // 17% chance of arrest
    case 13: arrestProbability = 18; break; // 18% chance of arrest
    case 12: arrestProbability = 19; break; // 19% chance of arrest
    case 11: arrestProbability = 20; break; // 20% chance of arrest
    case 10: arrestProbability = 21; break; // 21% chance of arrest
    case 9: arrestProbability = 22; break;  // 22% chance of arrest
    case 8: arrestProbability = 23; break;  // 23% chance of arrest
    case 7: arrestProbability = 24; break;  // 24% chance of arrest
    case 6: arrestProbability = 25; break;  // 25% chance of arrest
    case 5: arrestProbability = 26; break;  // 26% chance of arrest
    case 4: arrestProbability = 27; break;  // 27% chance of arrest
    case 3: arrestProbability = 28; break;  // 28% chance of arrest
    case 2: arrestProbability = 29; break;  // 29% chance of arrest
    case 1: arrestProbability = 30; break;  // 30% chance of arrest
    case 0: arrestProbability = 40; break;  // 40% chance of arrest
    default:
        if (reputation > 30)
            arrestProbability = 0;  // No chance if reputation > 30
        else if (reputation < 0)
            arrestProbability = 100; // 100% chance if reputation < 0
        else
            arrestProbability = 10; // Default chance for unhandled cases
        break;
    }

    srand(time(0));
    // Generate a random number to simulate the chance of arrest
    int randomChance = rand() % 100; // Random number between 0 and 99

    // Check if the random number is less than or equal to the arrest probability
    if (randomChance <= arrestProbability) {
        QMessageBox::information(nullptr, "Arrest Information",
                                 QString("You have been arrested. Your reputation was: %1").arg(reputation));
        // Ask if they want to file a petition
        filePetition(parent);
    }


}

// Function to handle the petition process
void filePetition(QWidget *parent) {
    bool filePetition = QMessageBox::question(nullptr, "File Petition",
                                              "Would you like to file a petition in court?",
                                              QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes;

    if (filePetition) {
        chooseLawyer(parent); // Allow the user to choose a lawyer
    } else {
        bool exit = QMessageBox::question(parent,"Good Game","Nice try fed ... Want to give it another try ?", QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes ;
        if(!exit)
        {
            bool confirmed_quit = QMessageBox::question(parent,"Quit","Are you sure you wanna quit the game ? \n Wo mard nai ho dar jaye halat k khoni manzar sy \n Jis door main jeena mushkil ho us door main jeena lazim ha",QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes ;
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

// Function to allow the user to choose a lawyer
void chooseLawyer(QWidget *parent) {

    int lawyerFees = 0;
    int successRate = 0;


    // Define the lawyer options
    QStringList lawyerOptions = {
        "Lawyer A ($"+QString::number(LAWYER)+") - 50% success",
        "Lawyer B ($"+QString::number(LAWYER*2)+") - 60% success",
        "Lawyer C ($"+QString::number(LAWYER*3)+"30,000) - 70% success",
        "Lawyer D ($"+QString::number(LAWYER*4)+"40,000) - 80% success",
        "Lawyer E ($"+QString::number(LAWYER*5)+" - 100% success (Guaranteed Bail)"
    };

    // Use QInputDialog to ask the user to choose a lawyer
    bool ok;
    QString lawyerChoiceString = QInputDialog::getItem(nullptr, "Choose Lawyer", "Select a lawyer:", lawyerOptions, 0, false, &ok);

        // Map the QString lawyerChoiceString to an int value representing the selected lawyer
        int lawyerChoice = lawyerOptions.indexOf(lawyerChoiceString); // Get the index of the selected item in the list

        // Determine lawyer fees and success rate based on the choice
        switch (lawyerChoice) {
        case 0: // Lawyer A
            lawyerFees = LAWYER;
            successRate = 50;
            break;
        case 1: // Lawyer B
            lawyerFees = LAWYER*2;
            successRate = 60;
            break;
        case 2: // Lawyer C
            lawyerFees = LAWYER*3;
            successRate = 70;
            break;
        case 3: // Lawyer D
            lawyerFees = LAWYER*4;
            successRate = 80;
            break;
        case 4: // Lawyer E
            lawyerFees = LAWYER*5;
            successRate = 100; // 100% success (guaranteed bail)
            break;
        default:
            QMessageBox::information(nullptr, "Invalid Choice", "Invalid lawyer choice. Exiting program.");
            return;  // Exit the function if an invalid choice is made
        }


    // Update the number of petitions filed
    number_of_petitions++;

    // Random chance to win based on success rate
    int randomChance = rand() % 100; // Random number between 0 and 99

    // Check if the lawyer was successful in court
    if (randomChance <= successRate) {
        QMessageBox::information(nullptr, "Court Result",
                                 QString("You won the case! Lawyer Fee: $%1. Number of petitions filed: %2.")
                                     .arg(lawyerFees).arg(number_of_petitions));
        bank_balance = bank_balance - lawyerFees ;
        LAWYER += LAWYER;
    } else {
        QMessageBox::information(nullptr, "Court Result",
                                 QString("You lost the case. Lawyer Fee: $%1. Number of petitions filed: %2.")
                                     .arg(lawyerFees).arg(number_of_petitions));

        bool exit = QMessageBox::question(parent,"Good Game","Nice try fed ... Want to give it another try ?", QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes ;
        if(!exit)
        {
            bool confirmed_quit = QMessageBox::question(parent,"Quit","Are you sure you wanna quit the game ? \n Wo mard nai ho dar jaye halat k khoni manzar sy \n Jis door main jeena mushkil ho us door main jeena lazim ha",QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes ;
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
