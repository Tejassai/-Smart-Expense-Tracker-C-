#include "Tracker.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

Tracker::Tracker() {
    loadFromFile();
}

void Tracker::loadFromFile() {
    std::ifstream file(filename);
    if (!file.is_open()) return;

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Expense e;
        std::string amountStr;

        if (std::getline(ss, e.date, ',') &&
            std::getline(ss, e.category, ',') &&
            std::getline(ss, e.description, ',') &&
            std::getline(ss, amountStr)) {
            e.amount = std::stod(amountStr);
            expenses.push_back(e);
        }
    }
    file.close();
}

void Tracker::saveToFile() const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error saving to file!\n";
        return;
    }
    for (const auto& e : expenses) {
        file << e.date << "," << e.category << "," << e.description << "," << e.amount << "\n";
    }
}

void Tracker::addExpense(const Expense& e) {
    expenses.push_back(e);
    saveToFile();
    std::cout << "Expense added successfully!\n";
}

void Tracker::viewAll() const {
    if (expenses.empty()) {
        std::cout << "No expenses recorded yet.\n";
        return;
    }
    std::cout << "\n---------------------------------------------------------\n";
    std::cout << std::left << std::setw(12) << "Date" << std::setw(15) << "Category" 
              << std::setw(20) << "Description" << "Amount\n";
    std::cout << "---------------------------------------------------------\n";
    for (const auto& e : expenses) {
        std::cout << std::left << std::setw(12) << e.date << std::setw(15) << e.category 
                  << std::setw(20) << e.description << "$" << std::fixed << std::setsetprecision(2) << e.amount << "\n";
    }
}

void Tracker::viewByCategory(const std::string& category) const {
    double total = 0;
    bool found = false;
    for (const auto& e : expenses) {
        if (e.category == category) {
            if (!found) {
                std::cout << "\nExpenses for category: " << category << "\n";
                found = true;
            }
            std::cout << e.date << " - " << e.description << ": $" << e.amount << "\n";
            total += e.amount;
        }
    }
    if (!found) std::cout << "No expenses found in this category.\n";
    else std::cout << "Total category spent: $" << total << "\n";
}

void Tracker::showTotalSpent() const {
    double total = 0;
    for (const auto& e : expenses) {
        total += e.amount;
    }
    std::cout << "\nTotal Cumulative Expenses: $" << total << "\n";
}

