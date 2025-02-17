#include "testStocks.h"
#include "Stock.h"
#include <iostream>
#include "Purchase.h"
#include "Portfolio.h"
#include <ctime>
#include <cstdlib>

// TEMPORARY TEST APP

testStocks::testStocks() {}

void testStocks::run()
{
    // Set seed for random number generation
    std::srand(std::time(0));

    std::string filename = "data/nasdaq_screener_filtered.csv"; // Assuming the CSV file is named "stocks.csv"
    std::vector<Stock> stocks = parseCSV(filename);

    // Create a Portfolio instance
    Portfolio portfolio;

    // Pick 5 random stocks and add them to the portfolio
    // for (int i = 0; i < 5; ++i)
    // {
    int randomIndex = std::rand() % stocks.size(); // Generate a random index
    Stock &selectedStock = stocks[21];             // Get the selected stock

    // Parse historical data and predict next prices
    selectedStock.parseHistory();
    selectedStock.predictNextX(5200);

    const auto &history = selectedStock.history;

    std::string initialPurchaseDate = selectedStock.history[0].date;

    Purchase myPurchase(selectedStock, 50, selectedStock.history[0].closePrice, initialPurchaseDate, selectedStock.history[0].closePrice);

    portfolio.addPurchase(myPurchase);

    portfolio.printPortfolio();
    for (int i = 1; i <= 1; ++i)
    {

        float newPurchasePrice = selectedStock.history[i].closePrice;
        std::string newPurchaseDate = selectedStock.history[i].date;

        Purchase *existingPurchase = portfolio.getPurchase(selectedStock.symbol);

        if (existingPurchase)
        {
            // Update the existing purchase in the portfolio
            existingPurchase->setCurrentPrice(newPurchasePrice);
            existingPurchase->setTimestamp(newPurchaseDate);
        }
        else
        {
            // Create a new purchase and add it to the portfolio
            Purchase newPurchase(selectedStock, 50, newPurchasePrice, newPurchaseDate, newPurchasePrice);
            portfolio.addPurchase(newPurchase);
        }

        // Calculate profit/loss
        float profitLoss = myPurchase.calculateProfit();
        // std::cout << newPurchaseDate << std::endl;
        // std::cout << "Date: " << newPurchaseDate << ", New Price: $" << newPurchasePrice << std::endl;
    }
    // }

    portfolio.printPortfolio();
}
