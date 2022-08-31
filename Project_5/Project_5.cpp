//Joseph Coleman
//COP2000.0M1
//This program will read from an input file and output categorized results

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;
ifstream inputFile;
using std::setprecision;
using std::fixed;

//Prototypes go here
void openFile();
void testFile();
void readFile(string studentNum, int credits, char res, float& total, float iTuition, float oTuition, int recordcounter, int hours, float cost);
float calcTuition(int hours, float iTuition, float oTuition, float cost, char res);
float addTotal(float total, float cost);
void displayStudent(string studentNum, float cost);
void closeFile();
void displayTotal(float total, float cost);


int main()
{




	//variables

	string studentNum;
	char res = 'I';
	int credits = 0;
	float total = 0;
	float iTuition = 206.77f;
	float oTuition = 482.90f;
	int recordcounter = 0;
	int hours = 0;
	float cost =  0;

	cout << "Pricey College\n" << "Tuition Due Spring 2021\n" << endl; // intro statement

	openFile(); //open the data file

	testFile(); //verify that the file was able to open

	readFile(studentNum, credits, res, total, iTuition, oTuition, recordcounter, hours, cost); // read the file and calculate the tuition


	closeFile(); // close the file

	displayTotal(total, cost); //display the total tuition cost

	cout << endl << endl << "End of results\n\n"; // closing statement

	return 0;


}


void openFile()
{
	inputFile.open("SpringTuition.txt"); //opening the file
}

void testFile()
{
	if (!inputFile) //file did not open
	{
		cout << "Input file did not open" << endl;
		exit(1000);
			
	}

}

void readFile(string studentNum, int credits, char res, float& total, float iTuition, float oTuition, int recordcounter, int hours, float cost)
{
	if (inputFile.is_open())
	{
		while (inputFile >> studentNum) // start read loop
		{
			if (recordcounter < 27) // loop for reading file
			{
				
				inputFile >> res;
				inputFile >> credits;
				hours == credits;

				cost = calcTuition(credits, iTuition, oTuition, cost, res);
				total = addTotal(total, cost);
				displayStudent(studentNum, cost);
				recordcounter += 3;
				
				
			}

		}
	}
}


float calcTuition(int credits, float iTuition, float oTuition, float cost, char res)
{
	if (res == 'I')
	{
		cost = (credits * iTuition);
	}
	else 
	{
		cost = (credits * oTuition);
	}

	return cost;
}

float addTotal(float total, float cost)
{
	total += cost;

	return total;
}

void displayStudent(string studentNum, float cost)
{
	cout << studentNum << "   " << fixed << setprecision(2) << cost << endl;
}

void closeFile()
{
	inputFile.close();
}

void displayTotal(float total, float cost)
{
	cout << endl << endl << "Total: " << "$" << setprecision(2) << total;
}