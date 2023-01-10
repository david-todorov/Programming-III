
/**
 * @file Test.cpp
 * @author David Todorov
 * @brief This program gets input from the user which is about Articles in imaginary warehouse and puts the data in "record" file in abular form
 */
#include <iostream>
#include "Article.h"
#include "Stock.h"
#include <fstream>
using namespace std;

/// @brief This functions adds white spaces n times
/// @param n Number of white spaces to be added
/// @return String which consists of n white paces
string addingWhiteSpaces(int n){
    string res = "";
    for (int i = 0; i < n; i++)
    {
        res+=" ";
    }
    return res;
}

/**
 * @brief This functions creates a stream to local file and inserts the information in tabular form
 * 
 * @return int 
 */
int main(){
    //! Number of entities which will be inserted
    int numberOfInputs;
    cout << "Please enter the number of inputs you would like to insert ";
    cin >> numberOfInputs;
    cout << endl;
    cout << endl;

    //! Opening the stream to local file record
    ofstream infile("record");
    //! Deleting all previous records of this file
    infile << "";

    //! Creating the header of the table
    infile << "| No | Description | Actual_Stock | Maximum_Stock | Cost_Price | Consump_Day | Order_Duration | Reorder_point | Order_Proposal " << endl;
    
    for (int i = 1; i <= numberOfInputs; i++)
    {
        //! Getting the number of an Article
        int numberOfArticle; 
        cout << "Please enter the number of an article ";
        cin >> numberOfArticle;

        //! Getting the description of an Article
        string description;
        cout << "Please enter the description of an article ";
        cin.ignore();
        getline(cin,description);
        
        //! Getting the actual stock of a Stock
        int actualStock;
        cout << "Please enter the actual stock ";
        cin >> actualStock;

        //! Getting the maximum stock of a Stock
        int maximumStock;
        cout << "Please enter the maximum stock ";
        cin >> maximumStock;

        //! Getting the price of a Stock
        double price;
        cout << "Please enter the price of an article ";
        cin >> price;
        
        //! Getting the consumption of a Stock
        int consumption;
        cout << "Please enter the consumption ";
        cin >> consumption;

        //! Getting the order of duration of a Stock
        int orderDuration;
        cout << "Please enter the order of duration of an article ";
        cin >> orderDuration;

        //! Calculating total price, but it is never used
        double totalStockValue = actualStock * price;

        //! Calculating the reorderPoint
        int reorderPoint = (orderDuration + 2) + consumption;
        int orderProposal = 0;

        if(actualStock <= reorderPoint){
            orderProposal = actualStock - reorderPoint;

        }
        //! Creating the objects Article and Stock
        Article art(numberOfArticle, description, price, orderDuration);
        Stock stock(numberOfArticle, actualStock ,maximumStock, consumption);
        
        //! Creating string with format "| {var}    ", where the white spaces are calculated using the header colum length minus the number of digit or characters
        string no = "|" + to_string(art.getNumberOfArticle()) + addingWhiteSpaces(4 - to_string(art.getNumberOfArticle()).length());
        string descriptionStr = "|" + art.getDescription() + addingWhiteSpaces(13 - art.getDescription().length());
        string actualStockStr = "|" + to_string(stock.getActualStock()) + addingWhiteSpaces(14 - to_string(stock.getActualStock()).length());
        string maxStock = "|" + to_string(stock.getMaximumStock())+addingWhiteSpaces(15 - to_string(stock.getMaximumStock()).length());
        string costPrice = "|" +  to_string(art.getCostPrice()) + addingWhiteSpaces(12 - to_string(art.getCostPrice()).length());
        string comPerday = "|" + to_string(stock.getConsumption()) + addingWhiteSpaces(13 - to_string(stock.getConsumption()).length());
        string order = "|" + to_string(art.getOrderDuration()) + addingWhiteSpaces(16 - to_string(art.getOrderDuration()).length());
        string reorderPointStr = "|" + to_string(reorderPoint) + addingWhiteSpaces(15 - to_string(reorderPoint).length());
        string orderProposalStr = "|" + to_string(orderProposal) + addingWhiteSpaces(16 - to_string(orderProposal).length());

        //! Adding the entities' information into the table as single row
        infile << no << descriptionStr << actualStockStr << maxStock << costPrice << comPerday << order << reorderPointStr << orderProposalStr << endl;


        //! This is for input pupose to separate the lines in the console
        if(i<numberOfInputs){
            cout << endl;
            cout << "--------------------------" << endl;
            cout << endl;
        } 
       
    }
    infile.close();
    return 0;
}