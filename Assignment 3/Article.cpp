/**
 * @file Article.cpp
 * @author David Todorov
 * @brief Stores the information about an article
 */
#include "Article.h"
/**
 * @brief Construct a new Article object
 * 
 * @param numberOfArticle special number to identify an article
 * @param description string which describes an article
 * @param costPrice price of an article
 * @param orderDuration order of duration of an article
 */
Article::Article(int numberOfArticle, string description, double costPrice, int orderDuration){
    this->numberOfArticle = numberOfArticle;
    this->description = description;
    this->costPrice = costPrice;
    this->orderDuration = orderDuration;
}

/**
 * @brief Getting the number of a given article
 * 
 * @return Number of a article 
 */
int Article::getNumberOfArticle(){
     return this->numberOfArticle;
}

/**
 * @brief Setting the number of a given article
 * 
 * 
 */
void Article::setNumberOfArticle(int num){
    this->numberOfArticle = num;
}

/**
 * @brief Getting the description of a given article
 * 
 * @return Description of a article 
 */
string Article::getDescription(){
     return this->description;
}

/**
 * @brief Setting the description of a given article
 * 
 * 
 */
void Article::setDescription(string desc){
    this->description = description;
}

/**
 * @brief Getting the price of a given article
 * 
 * @return Price of a article 
 */
double Article::getCostPrice(){
     return this->costPrice;
}

/**
 * @brief Setting the number of a given article
 * 
 */
void Article::setCostPrice(double price){
    this->costPrice = price;
}

/**
 * @brief Getting the order of duration of a given article
 * 
 * @return Order of duration of a article 
 */
int Article::getOrderDuration(){
     return this->orderDuration;
}

/**
 * @brief Setting the order of duration of a given article
 * 
 */
void Article::setOrderDuration(int dur){
    this->orderDuration = dur;
}