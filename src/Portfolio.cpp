#include "Portfolio.h"
#include <iostream>

// Portfolio.cpp

void Portfolio::addPurchase(Purchase purchase)
{
    Purchase *existingPurchase = getPurchase(purchase.getStockSymbol());

    if (existingPurchase)
    {
        // Merge with existing purchase
        existingPurchase->setQuantity(existingPurchase->getQuantity() + purchase.getQuantity());
        existingPurchase->updatePurchasePrice(purchase.getStock.getPrice());

        // Other calculations and updates can be performed here if needed
    }
    else
    {
        // Add a new purchase
        purchases.push_back(purchase);
    }
}

void Portfolio::printPortfolio() const
{
    std::cout << "Portfolio Details:" << std::endl;
    for (const Purchase &purchase : purchases)
    {
        std::cout << "------------------------------" << std::endl;
        purchase.printPurchaseDetails();
    }
}

Purchase *Portfolio::getPurchase(const std::string &stockSymbol)
{
    for (Purchase &purchase : purchases)
    {
        if (purchase.getStockSymbol() == stockSymbol)
        {
            return &purchase;
        }
    }
    return nullptr; // Return nullptr if purchase with the given stock symbol is not found
}

const std::vector<Purchase> Portfolio::getPurchases() const
{
    return purchases;
}

// Portfolio.cpp
