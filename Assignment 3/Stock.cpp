/**
 * @file Stock.cpp
 * @author David Todorov
 * @brief Stores the information about a Stock
 */
#include "Stock.h"
/**
 * @brief Construct a new Stock object
 * 
 * @param articleNumber special number to identify an article
 * @param actualStock   number of actual stock of an article 
 * @param maximumStock  number of maximum stock of an article
 * @param consumption   consumption per day
 */
Stock::Stock(int articleNumber, int actualStock, int maximumStock, int consumption){
    this->articleNumber = articleNumber;
    this->actualStock = actualStock;
    this->maximumStock = maximumStock;
    this->consumption = consumption;
}

/**
 * @brief Getting the number of a given stock / article
 * 
 * @return Number of a stock / article 
 */
int Stock::getArticleNumber(){
     return this->articleNumber;
}

/**
 * @brief Setting the number of a given stock / article
 * 
 */
void Stock::setArticleNumber(int num){
    this->articleNumber = num;
}

/**
 * @brief Getting the actual stock of a given stock / article
 * 
 * @return Actual stock of a stock / article 
 */
int Stock::getActualStock(){
     return this->actualStock;
}

/**
 * @brief Setting the actual stock of a given stock / article
 * 
 */
void Stock::setActualStock(int stock){
    this->actualStock = stock;
}

/**
 * @brief Getting the maximum stock of a given stock / article
 * 
 * @return Maximum stock of a stock / article 
 */
int Stock::getMaximumStock(){
     return this->maximumStock;
}

/**
 * @brief Setting the maximum stock of a given stock / article
 * 
 */
void Stock::setMaximumStock(int maximumStock){
    this->maximumStock = maximumStock;
}

/**
 * @brief Getting the consumption of a given stock / article
 * 
 */
int Stock::getConsumption(){
     return this->consumption;
}

/**
 * @brief Setting the consumption stock of a given stock / article
 * 
 */
void Stock::setConsumption(int consumption){
    this->maximumStock = consumption;
}
