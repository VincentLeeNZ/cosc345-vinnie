#include <string>
#include <vector>
#ifndef STOCK_H
#define STOCK_H

// ChatGPTed

struct StockHistory
{
    std::string date;
    double closePrice;
};

class Stock
{
public:
    Stock(const std::string &symbol, const std::string &name, int outstanding, int ipoYear, const std::string &sector, const std::string &industry);
    std::string symbol;
    std::string name;
    int outstanding;
    int ipoYear;
    std::string sector;
    std::string industry;
    std::vector<StockHistory> history;
    void parseHistory();
    void predictNextX(int x);
    double purchasePrice;

    double getPriceAtDate(const std::string &date) const;
    // Getters
    std::string getSymbol() const;
    std::string getName() const;
    int getOutstanding() const;
    int getIpoYear() const;
    std::string getSector() const;
    std::string getIndustry() const;
    double getPurchasePrice() const;

    // Setters
    void setSymbol(const std::string &symbol);
    void setName(const std::string &name);
    void setOutstanding(int outstanding);
    void setIpoYear(int ipoYear);
    void setSector(const std::string &sector);
    void setIndustry(const std::string &industry);
    void setPrice(double price);
    // std::string getNextDate(const std::string &date);

private:
};
std::string getNextDate(const std::string &date);
std::vector<Stock> parseCSV(const std::string &filename);

#endif // STOCK_H