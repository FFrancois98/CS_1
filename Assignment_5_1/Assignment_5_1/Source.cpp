#include <iostream> 
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string word1, word2, word3, word4, sentence; //declares variables
	int space_pos1, space_pos2, space_pos3, period_pos;
	cout << "Enter a four word sentence with spaces to separate each word: " << endl; //prompt the user
	getline(cin, sentence); //get the sentence from the user
	space_pos1 = sentence.find(" "); //find the first space
	word1 = sentence.substr(0, space_pos1); //get the first word
	sentence = sentence.substr(space_pos1 + 1, sentence.size() - space_pos1); //reduce the string by one word
	cout << word1 << endl; //display the first word
	space_pos2 = sentence.find(" "); //find the second space
	word2 = sentence.substr(0, space_pos2); //get the second word
	sentence = sentence.substr(space_pos2 + 1, sentence.size() - space_pos2); //reduce the string by one word
	cout << word2 << endl; //display the second word
	space_pos3 = sentence.find(" "); //find the third space
	word3 = sentence.substr(0, space_pos3); //get the third word
	sentence = sentence.substr(space_pos3 + 1, sentence.size() - space_pos3); //reduce the string by one word
	cout << word3 << endl; //display the third word
	period_pos = sentence.find("."); //find the period
	word4 = sentence.substr(0, period_pos); //get the fourth word
	cout << word4 << endl; //display the fourth word
	return 0;
}
/*
Enter a four word sentence with spaces to separate each word:
The fox ran fast.
The
fox
ran
fast
Press any key to continue . . .
*/