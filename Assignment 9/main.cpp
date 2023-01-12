#include <iostream>
#include <map>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;



int main() {
	srand(time(NULL));

	multimap<string, string> vocTrainer;
	vocTrainer.insert(pair<string, string>("date", "das Datum"));
	vocTrainer.insert(pair<string, string>("date", "das Date"));
	vocTrainer.insert(pair<string, string>("bite", "beissen"));

	vocTrainer.insert(pair<string, string>("read", "lesen"));
	vocTrainer.insert(pair<string, string>("afford", "leisten"));
	vocTrainer.insert(pair<string, string>("adapt", "anpassen"));
	vocTrainer.insert(pair<string, string>("compare", "vergleichen"));
	vocTrainer.insert(pair<string, string>("voice", "die Stimme"));
	vocTrainer.insert(pair<string, string>("last", "zuletzt"));
	vocTrainer.insert(pair<string, string>("last", "dauern"));

	// this is how you iterate the map however the multiple values of 1 key are duplicated
//	multimap<string, string>::iterator iter;
//	string s;
//	for (iter = vocTrainer.begin(); iter != vocTrainer.end(); ++iter) {
//		s = iter->first;
//		pair<multimap<string, string>::iterator, multimap<string, string>::iterator> range = vocTrainer.equal_range(s);
//		 for (std::multimap<string,string>::iterator it=range.first; it!=range.second; ++it)
//		      std::cout <<it->first<< ' ' << it->second<<endl;
//
//	}
	int a = 0;
	string index;
	multimap<string, string>::iterator iter;
	for (iter = vocTrainer.begin(); iter != vocTrainer.end(); ++iter) {

		a = rand() % 2 + 1;
		if (a == 1) {
			index = iter->first;
		} else {
			index = iter->second;
		}
		cout << index << "    please enter translation: " << endl;
		string userInput;
		getline(cin, userInput);
		if (a == 2) {
			if (userInput.compare(iter->first) == 0)
				cout << "True " << endl;
			else {
				cout << "False the correct is: " << iter->first << endl;
			}
		} else {
			// this way I can extract multiple values attached to one key
			pair<multimap<string, string>::iterator,
					multimap<string, string>::iterator> range =
					vocTrainer.equal_range(iter->first);
			//some basic programflow functionalities
			bool flag = false;
			for (std::multimap<string, string>::iterator it = range.first;
					it != range.second; ++it) {
				if (userInput.compare(it->second) == 0) {
					cout << "True " << endl;
					flag = true;
					break;
				}
			}
			if (flag == true) {
				cout << "also correct answers are : ";
			} else {
				cout << "False the correct answers are: ";
			}
			for (std::multimap<string, string>::iterator it = range.first;
					it != range.second; ++it) {
				cout << " " << it->second;
			}
			cout << endl;

		}
	}
	return 0;
}
