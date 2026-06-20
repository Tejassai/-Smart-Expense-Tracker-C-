#include "Tracker.h"
#include <iostream>
#include <limits>

void displayMenu() {
    std::cout << "\n--- Smart Expense Tracker ---\n";
    std::cout << "1. Add Expense\n";
    std::cout << "2. View All Expenses\n";
    std::cout << "3. View Expenses by Category\n";
    std::cout << "4. Show Total Statistics\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter choice: ";
}

int main() {
    Tracker myTracker;
    int choice;

    while (true) {
        displayMenu();
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice == 5) break;

        if (choice == 1) {
            Expense e;
            std::cout << "Enter date (YYYY-MM-DD): ";
            std::cin >> e.date;
            std::cout << "Enter category (e.g., Food, Rent, Transport): ";
            std::cin >> e.category;
            std::cin.ignore();
            std::cout << "Enter description: ";
            std::getline(std::cin, e.description);
            std::cout << "Enter amount: ";
            while (!(std::cin >> e.amount) || e.amount < 0) {
                std::cout << "Invalid amount. Enter a valid positive number: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            myTracker.addExpense(e);
        } 
        else if (choice == 2) {
            myTracker.viewAll();
        } 
        else if (choice == 3) {
            std::string category;
            std::cout << "Enter category to filter: ";
            std::cin >> category;
            myTracker.viewByCategory(category);
        } 
        else if (choice == 4) {
            myTracker.showTotalSpent();
        } 
        else {
            std::cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
