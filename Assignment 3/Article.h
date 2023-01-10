#include <iostream>
using namespace std;

class Article
{
private:
    int numberOfArticle;
    string description;
    double costPrice;
    int orderDuration;
public:
    Article(int numberOfArticle, string description, double costPrice, int orderDuration);
    int getNumberOfArticle();
    void setNumberOfArticle(int n);
    string getDescription();
    void setDescription(string desc);
    double getCostPrice();
    void setCostPrice(double price);
    int getOrderDuration();
    void setOrderDuration(int dur);
};

