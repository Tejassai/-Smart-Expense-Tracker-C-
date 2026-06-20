#ifndef TRACKER_H
#define TRACKER_H

#include "Expense.h"
#include <vector>
#include <string>

class Tracker {
private:
    std::vector<Expense> expenses;
    const std::string filename = "expenses.txt";
    void loadFromFile();
    void saveToFile() const;

public:
    Tracker();
    void addExpense(const Expense& e);
    void viewAll() const;
    void viewByCategory(const std::string& category) const;
    void showTotalSpent() const;
};

#endif
