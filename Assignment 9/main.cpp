/**
 * @file main.cpp
 * @author your name David Todorov
 * @brief Small program which gives basic functionalities of vocabulary training
 */
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	

	/**
	 * @brief Initialization of the dictionary
	 * 
	 */
	multimap<string, string> dictionary;
	dictionary.insert(pair<string, string>("week", "die Woche"));
	dictionary.insert(pair<string, string>("year", "das Jahr"));
	dictionary.insert(pair<string, string>("Calender", "der Kalender"));
	dictionary.insert(pair<string, string>("second", "die Sekunde"));
	dictionary.insert(pair<string, string>("hour", "die Stunde"));
	dictionary.insert(pair<string, string>("minute", "die Minute"));
	dictionary.insert(pair<string, string>("o'clock", "die Uhr"));
	dictionary.insert(pair<string, string>("use", "benutzen"));
	dictionary.insert(pair<string, string>("go", "gehen"));
	dictionary.insert(pair<string, string>("laugh", "lachen"));
	dictionary.insert(pair<string, string>("make", "machen"));
	dictionary.insert(pair<string, string>("see", "sehen"));
	dictionary.insert(pair<string, string>("far", "weit"));
	dictionary.insert(pair<string, string>("small", "klein"));
	dictionary.insert(pair<string, string>("beautiful", "schön"));
	dictionary.insert(pair<string, string>("hard", "schwierig"));
	dictionary.insert(pair<string, string>("bad", "schlecht"));
	dictionary.insert(pair<string, string>("near", "nahe"));
	dictionary.insert(pair<string, string>("hello", "hallo"));

    multimap<string, string>::iterator iter;

	/**
	 * @brief Asking the user from which to which language would like to train 
	 * 
	 */
	cout << "Welcome to our vocabulary training, please follow the instructions" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "Please choose from which language to which you would like to train." << endl;
	cout << "Available options are from English to German and from German to English e.g. type E-G or G-E" << endl;
	string fromTo;
	getline(cin, fromTo);
	if (fromTo == "E-G")
	{
		cout << "Congratulations you have choosen from English to German" << endl;
		cout << endl;
		/**
		 * @brief Iterating over the dictionary
		 * 
		 */
		for (iter = dictionary.begin(); iter != dictionary.end(); iter++)
		{

			cout << "Please write the folowing word in German plus the artikel -> " << iter->first << endl;
			string userWord;
			std::getline(cin, userWord);
			if (userWord == iter->second)
			{
				cout << "Congratulations the translation is right!" << endl;
			}
			else
			{
				cout << "Ooops wrong answer..." << endl;
				cout << "The right answer is -> " << iter->second << endl;
			}
			cout << "---------------------------------------------" << endl;
		}
		
	}
	else if (fromTo == "G-E")
	{
		cout << "Congratulations you have choosen from German to English" << endl;
		cout << endl;
		/**
		 * @brief Iterating over the dictionary
		 * 
		 */
		for (iter = dictionary.begin(); iter != dictionary.end(); iter++)
		{

			cout << "Please write the folowing word in English -> " << iter->second << endl;
			string userWord;
			std::getline(cin, userWord);
			if (userWord == iter->first)
			{
				cout << "Congratulations the translation is right!" << endl;
			}
			else
			{
				cout << "Ooops wrong answer..." << endl;
				cout << "The right answer is -> " << iter->first << endl;
			}
			cout << "---------------------------------------------" << endl;
		}
	}
	cout << "Your training is done... bye bye!!!" << endl;
	return 0;
}
