void MainWindow::on_SAVE_clicked()
{
    bool ok;
    int slot_selected = QInputDialog::getInt(nullptr, "Save Game", "Select a save slot (1-3):", 1, 1, 3, 1, &ok);
    qDebug() << "Slot selected: " << slot_selected; // Debugging the input slot
    if (ok) {
        qDebug() << "Calling saveState for slot: " << slot_selected;
        saveGameState ( slot_selected ) ;
    } else {
        qDebug() << "User cancelled or invalid slot selected";  // Add this to track user cancellation
    }

}


void MainWindow::on_LOAD_clicked()
{
    bool ok;
    int slot = QInputDialog::getInt(nullptr, "Load Game", "Select a load slot (1-3):", 1, 1, 3, 1, &ok);
    if (ok) {
        loadGameState(slot,ui);
    }
}
