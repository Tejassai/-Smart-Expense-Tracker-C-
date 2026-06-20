#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>

struct Expense {
    std::string date; // YYYY-MM-DD
    std::string category;
    std::string description;
    double amount;
};

#endif
