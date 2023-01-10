class Stock
{
private:
    int articleNumber;
    int actualStock;
    int maximumStock;
    int consumption;
public:
    Stock(int articleNumber, int actualStock, int maximumStock, int consumption);
    int getArticleNumber();
    void setArticleNumber(int n);
    int getActualStock();
    void setActualStock(int actualStock);
    int getMaximumStock();
    void setMaximumStock(int maximumStock);
    int getConsumption();
    void setConsumption(int consumption);
};


