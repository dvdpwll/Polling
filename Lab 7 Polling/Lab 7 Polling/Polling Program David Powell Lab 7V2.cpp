//David Powell
//CIT-120
//10/25/14
//
//Create an interactive polling program.
//Your poll must ask at least 5 questions.
//At least 3 questions cannot be True / False or Yes / No.
//You must display the number of people that have taken the poll.
//You must display the results of your poll at the end of the poll, using percentages and whole numbers for each question asked.
//Your display must include the question and the answers.
//In addition to a numeric display for each question, display a histogram of the data for each question.
///////////////////////////////////////////////////////////////////////////////////////////

/*
Psudo Code:
-use arrays, functions, and open/close files
-declare variables
-ask user for input (5-7 questions)
-put input into a file
-display the number of ppl who have taken the poll
-display the results of the poll using %

**Topic: purchaseing habits**
1) Have you purchased a game in the last 12 months? (yes/no)
2) What type of games do you play the most? (PC/Xbox/Playstation/Wii)
3) What genre of games do you play the most? (FPS/RPG/Stratagy/other)
4) What is your age? (0-10/11-20/21-30/31+)
5) How many hours do you play per week? (0-2/3-4/5-6/7+)
6) other



Things to add for the final:
-Seperate into two seperate programs. (User program and admin program)
User Program:
-asks questions (+)
-calculate results (+)
-display statistics (+)
Admin Program:
-ability to add additional questions and answers to poll ()
-calculate results (+)
-display statistics (+)
General:
-use functions (+)
-use comments (+)
-have psudo code (+)
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

int main()
{	//list of variables
	const int POLL_ANSWERS = 7;
	int answers[POLL_ANSWERS] = { 1, 1, 1, 1, 1, 1, 1 };
	int userData[27];
	int savedData[27];
	int count = 0;
	char restart;
	string questionAdd[10];
	
	
	//restart program
	do
	{
		//obtain user choices
		//Q1
		do
		{
			while (true)
			{
				cout << "Have you purchased a game in the last 6 months? \n1) Yes\n2) No" << endl;
				cout << "Enter choice: ";
				string tmp;
				getline(cin, tmp);
				if (stringstream(tmp) >> answers[0])
					break;
			};
		} while (answers[0] != 1 && answers[0] != 2);

		//Q2
		do
		{
			while (true)
			{
				cout << "\n\nWhat type of system do you play the most on? \n1) PC \n2) Xbox\n3) Playstation\n4) Wii" << endl;
				cout << "Enter choice: ";
				string tmp;
				getline(cin, tmp);
				if (stringstream(tmp) >> answers[1])
					break;
			};
		} while (answers[1] != 1 && answers[1] != 2 && answers[1] != 3 && answers[1] != 4);

		//Q3
		do
		{
			while (true)
			{
				cout << "\n\nWhat genre of games do you play the most? \n1) FPS \n2) RPG\n3) Strategy\n4) Other" << endl;
				cout << "Enter choice: ";
				string tmp;
				getline(cin, tmp);
				if (stringstream(tmp) >> answers[2])
					break;
			};
		} while (answers[2] != 1 && answers[2] != 2 && answers[2] != 3 && answers[2] != 4);

		//Q4
		do
		{
			while (true)
			{
				cout << "\n\nWhat is your age? \n1) >10 \n2) 11-20\n3) 21-30\n4) 31+" << endl;
				cout << "Enter choice: ";
				string tmp;
				getline(cin, tmp);
				if (stringstream(tmp) >> answers[3])
					break;
			};
		} while (answers[3] != 1 && answers[3] != 2 && answers[3] != 3 && answers[3] != 4);

		//Q5
		do
		{
			while (true)
			{
				cout << "\n\nHow many hours do you play per week? \n1) 0-1 \n2) 2-4\n3) 5-7\n4) 8+" << endl;
				cout << "Enter choice: ";
				string tmp;
				getline(cin, tmp);
				if (stringstream(tmp) >> answers[4])
					break;
			};
		} while (answers[4] != 1 && answers[4] != 2 && answers[4] != 3 && answers[4] != 4);

		//Q6
		//open file and read new questions
		ifstream inQuestions;
		inQuestions.open("AddQuestions.txt");
		while (!inQuestions.eof() && count < 10)
			{
				getline(inQuestions, questionAdd[count], '\n');
				count++;
			}
		inQuestions.close();
		cout << "\n\nData read from AddQuestions.txt" << endl;

		//Q6
		do
		{
			while (true)
			{
				cout << questionAdd[0] << endl << questionAdd[1] << endl << questionAdd[2] << endl << questionAdd[3] << endl << questionAdd[4] << endl;
				cout << "Enter choice: ";
				string tmp;
				getline(cin, tmp);
				if (stringstream(tmp) >> answers[5])
					break;
			};
		} while (answers[5] != 1 && answers[5] != 2 && answers[5] != 3 && answers[5] != 4);

		//Q7
		do
		{
			while (true)
			{
				cout << questionAdd[5] << endl << questionAdd[6] << endl << questionAdd[7] << endl << questionAdd[8] << endl << questionAdd[9] << endl;
				cout << "Enter choice: ";
				string tmp;
				getline(cin, tmp);
				if (stringstream(tmp) >> answers[6])
					break;
			};
		} while (answers[6] != 1 && answers[6] != 2 && answers[6] != 3 && answers[6] != 4);

		count = 0;
		//if statement for Q1
		//uses userData[0] and userData[1]
		if (answers[0] == 1)
		{
			userData[0] = 1;
			userData[1] = 0;
		}
		else if (answers[0] == 2)
		{
			userData[0] = 0;
			userData[1] = 1;
		}
		else
		{
			cout << "Please enter a vaild choice for question 1." << endl;
			system("pause");
			return 0;
		}

		//if statement for Q2
		//uses userData[2] and userData[3] and userData[4] and userData[5]
		if (answers[1] == 1)
		{
			userData[2] = 1;
			userData[3] = 0;
			userData[4] = 0;
			userData[5] = 0;
		}
		else if (answers[1] == 2)
		{
			userData[2] = 0;
			userData[3] = 1;
			userData[4] = 0;
			userData[5] = 0;
		}
		else if (answers[1] == 3)
		{
			userData[2] = 0;
			userData[3] = 0;
			userData[4] = 1;
			userData[5] = 0;
		}
		else if (answers[1] == 4)
		{
			userData[2] = 0;
			userData[3] = 0;
			userData[4] = 0;
			userData[5] = 1;
		}
		else
		{
			cout << "Please enter a vaild choice for question 2." << endl;
			system("pause");
			return 0;
		}

		//if statement for Q3
		//uses userData[6] and userData[7] and userData[8] and userData[9]
		if (answers[2] == 1)
		{
			userData[6] = 1;
			userData[7] = 0;
			userData[8] = 0;
			userData[9] = 0;
		}
		else if (answers[2] == 2)
		{
			userData[6] = 0;
			userData[7] = 1;
			userData[8] = 0;
			userData[9] = 0;
		}
		else if (answers[2] == 3)
		{
			userData[6] = 0;
			userData[7] = 0;
			userData[8] = 1;
			userData[9] = 0;
		}
		else if (answers[2] == 4)
		{
			userData[6] = 0;
			userData[7] = 0;
			userData[8] = 0;
			userData[9] = 1;
		}
		else
		{
			cout << "Please enter a vaild choice for question 3." << endl;
			system("pause");
			return 0;
		}

		//if statement for Q4
		//uses userData[10] and userData[11] and userData[12] and userData[13]
		if (answers[3] == 1)
		{
			userData[10] = 1;
			userData[11] = 0;
			userData[12] = 0;
			userData[13] = 0;
		}
		else if (answers[3] == 2)
		{
			userData[10] = 0;
			userData[11] = 1;
			userData[12] = 0;
			userData[13] = 0;
		}
		else if (answers[3] == 3)
		{
			userData[10] = 0;
			userData[11] = 0;
			userData[12] = 1;
			userData[13] = 0;
		}
		else if (answers[3] == 4)
		{
			userData[10] = 0;
			userData[11] = 0;
			userData[12] = 0;
			userData[13] = 1;
		}
		else
		{
			cout << "Please enter a vaild choice for question 4." << endl;
			system("pause");
			return 0;
		}

		//if statement for Q5
		//uses userData[14] and userData[15] and userData[16] and userData[17]
		if (answers[4] == 1)
		{
			userData[14] = 1;
			userData[15] = 0;
			userData[16] = 0;
			userData[17] = 0;
		}
		else if (answers[4] == 2)
		{
			userData[14] = 0;
			userData[15] = 1;
			userData[16] = 0;
			userData[17] = 0;
		}
		else if (answers[4] == 3)
		{
			userData[14] = 0;
			userData[15] = 0;
			userData[16] = 1;
			userData[17] = 0;
		}
		else if (answers[4] == 4)
		{
			userData[14] = 0;
			userData[15] = 0;
			userData[16] = 0;
			userData[17] = 1;
		}
		else
		{
			cout << "Please enter a vaild choice for question 5." << endl;
			system("pause");
			return 0;
		}
		//if statement for Q6
		//uses userData[18] and userData[19] and userData[20] and userData[21]
		if (answers[5] == 1)
		{
			userData[18] = 1;
			userData[19] = 0;
			userData[20] = 0;
			userData[21] = 0;
		}
		else if (answers[5] == 2)
		{
			userData[18] = 0;
			userData[19] = 1;
			userData[20] = 0;
			userData[21] = 0;
		}
		else if (answers[5] == 3)
		{
			userData[18] = 0;
			userData[19] = 0;
			userData[20] = 1;
			userData[21] = 0;
		}
		else if (answers[5] == 4)
		{
			userData[18] = 0;
			userData[19] = 0;
			userData[20] = 0;
			userData[21] = 1;
		}
		else
		{
			cout << "Please enter a vaild choice for question 6." << endl;
			system("pause");
			return 0;
		}
		//if statement for Q7
		//uses userData[22] and userData[23] and userData[24] and userData[25]
		if (answers[6] == 1)
		{
			userData[22] = 1;
			userData[23] = 0;
			userData[24] = 0;
			userData[25] = 0;
		}
		else if (answers[6] == 2)
		{
			userData[22] = 0;
			userData[23] = 1;
			userData[24] = 0;
			userData[25] = 0;
		}
		else if (answers[6] == 3)
		{
			userData[22] = 0;
			userData[23] = 0;
			userData[24] = 1;
			userData[25] = 0;
		}
		else if (answers[6] == 4)
		{
			userData[22] = 0;
			userData[23] = 0;
			userData[24] = 0;
			userData[25] = 1;
		}
		else
		{
			cout << "Please enter a vaild choice for question 7." << endl;
			system("pause");
			return 0;
		}

		//a check for when a user fills out data to find how many people took survey
		userData[26] = 1;

		//open file and store previously saved data to an array
		ifstream inSaveDataFile;
		inSaveDataFile.open("pollDataFile.txt");
		while (count < 27 && inSaveDataFile >> savedData[count])
			count++;
		inSaveDataFile.close();
		cout << "\n\nData read from pollDataFile.txt" << endl;

		//add userData to saveData to get a total
		for (count = 0; count < 27; count++)
			savedData[count] = savedData[count] + userData[count];

		//write the new saveData to a file
		ofstream outSaveDataFile;
		outSaveDataFile.open("pollDataFile.txt");
		for (count = 0; count < 27; count++)
			outSaveDataFile << savedData[count] << endl;
		outSaveDataFile.close();
		cout << "Data stored to pollDataFile.txt" << endl << endl;

		//Display Statistics
		cout << "\n-----------------------------------------------------------------\n";

		cout << "Including you, this poll has been taken " << savedData[26] << " times." << endl << endl;

		cout << "QUESTION 1" << endl;
		cout << "Have you purchased a game in the last 6 months?" << endl;
		cout << "Yes\t\tNo" << endl;
		cout << setprecision(4) << savedData[0] << ", (" << ((savedData[0] / static_cast<double>(savedData[26])) * 100) << "%)";
		cout << setprecision(4) << "\t" << savedData[1] << ", (" << ((savedData[1] / static_cast<double>(savedData[26])) * 100) << "%)" << endl;

		cout << "\n\nQUESTION 2" << endl;
		cout << "What type of system do you play the most on?" << endl;
		cout << "PC\t\tXbox\t\tPlaystation\tWii" << endl;
		cout << setprecision(4) << savedData[2] << ", (" << ((savedData[2] / static_cast<double>(savedData[26])) * 100) << "%)";
		cout << setprecision(4) << "\t" << savedData[3] << ", (" << ((savedData[3] / static_cast<double>(savedData[26])) * 100) << "%)";
		cout << setprecision(4) << "\t" << savedData[4] << ", (" << ((savedData[4] / static_cast<double>(savedData[26])) * 100) << "%)";
		cout << setprecision(4) << "\t" << savedData[5] << ", (" << ((savedData[5] / static_cast<double>(savedData[26])) * 100) << "%)" << endl;

		cout << "\n\nQUESTION 3" << endl;
		cout << "What genre of games do you play the most?" << endl;
		cout << "FPS\t\tRPG\t\tStrategy\tOther" << endl;
		cout << setprecision(4) << savedData[6] << ", (" << ((savedData[6] / static_cast<double>(savedData[26])) * 100) << "%)";
		cout << setprecision(4) << "\t" << savedData[7] << ", (" << ((savedData[7] / static_cast<double>(savedData[26])) * 100) << "%)";
		cout << setprecision(4) << "\t" << savedData[8] << ", (" << ((savedData[8] / static_cast<double>(savedData[26])) * 100) << "%)";
		cout << setprecision(4) << "\t" << savedData[9] << ", (" << ((savedData[9] / static_cast<double>(savedData[26])) * 100) << "%)" << endl;

		cout << "\n\nQUESTION 4" << endl;
		cout << "What is your age?" << endl;
		cout << ">10\t\t11-20\t\t21-30\t\t31+" << endl;
		cout << setprecision(4) << savedData[10] << ", (" << ((savedData[10] / static_cast<double>(savedData[26])) * 100) << "%)";
		cout << setprecision(4) << "\t" << savedData[11] << ", (" << ((savedData[11] / static_cast<double>(savedData[26])) * 100) << "%)";
		cout << setprecision(4) << "\t" << savedData[12] << ", (" << ((savedData[12] / static_cast<double>(savedData[26])) * 100) << "%)";
		cout << setprecision(4) << "\t" << savedData[13] << ", (" << ((savedData[13] / static_cast<double>(savedData[26])) * 100) << "%)" << endl;

		cout << "\n\nQUESTION 5" << endl;
		cout << "How many hours do you play per week?" << endl;
		cout << "0-1\t\t2-4\t\t5-7\t\t8+" << endl;
		cout << setprecision(4) << savedData[14] << ", (" << ((savedData[14] / static_cast<double>(savedData[26])) * 100) << "%)";
		cout << setprecision(4) << "\t" << savedData[15] << ", (" << ((savedData[15] / static_cast<double>(savedData[26])) * 100) << "%)";
		cout << setprecision(4) << "\t" << savedData[16] << ", (" << ((savedData[16] / static_cast<double>(savedData[26])) * 100) << "%)";
		cout << setprecision(4) << "\t" << savedData[17] << ", (" << ((savedData[17] / static_cast<double>(savedData[26])) * 100) << "%)" << endl;

		cout << "\n\nQUESTION 6" << endl;
		cout << questionAdd[0] << endl;
		cout << questionAdd[1] << "\t" << questionAdd[2] << "\t" << questionAdd[3] << "\t" << questionAdd[4] << endl;
		cout << setprecision(4) << savedData[18] << ", (" << ((savedData[18] / static_cast<double>(savedData[26])) * 100) << "%)";
		cout << setprecision(4) << "\t" << savedData[19] << ", (" << ((savedData[19] / static_cast<double>(savedData[26])) * 100) << "%)";
		cout << setprecision(4) << "\t" << savedData[20] << ", (" << ((savedData[20] / static_cast<double>(savedData[26])) * 100) << "%)";
		cout << setprecision(4) << "\t" << savedData[21] << ", (" << ((savedData[21] / static_cast<double>(savedData[26])) * 100) << "%)" << endl;

		cout << "\n\nQUESTION 7" << endl;
		cout << questionAdd[5] << endl;
		cout << questionAdd[6] << "\t" << questionAdd[7] << "\t" << questionAdd[8] << "\t" << questionAdd[9] << endl;
		cout << setprecision(4) << savedData[22] << ", (" << ((savedData[22] / static_cast<double>(savedData[26])) * 100) << "%)";
		cout << setprecision(4) << "\t" << savedData[23] << ", (" << ((savedData[23] / static_cast<double>(savedData[26])) * 100) << "%)";
		cout << setprecision(4) << "\t" << savedData[24] << ", (" << ((savedData[24] / static_cast<double>(savedData[26])) * 100) << "%)";
		cout << setprecision(4) << "\t" << savedData[25] << ", (" << ((savedData[25] / static_cast<double>(savedData[26])) * 100) << "%)" << endl;


		//histogram
		cout << "\n-------------------------------------------------------------\n";
		//Q1
		cout << "Question 1:" << endl << "Have you purchased a game in the last 12 months?" << endl;
		cout << "Yes\t|";
		for (int i = 0; i < savedData[0]; i++)
		{
			cout << "x";
		}
		cout << "\nNo\t|";
		for (int i = 0; i < savedData[1]; i++)
		{
			cout << "x";
		}

		//Q2
		cout << "\n\nQuestion 2:" << endl << "What type of system do you play the most on?" << endl;
		cout << "PC\t|";
		for (int i = 0; i < savedData[2]; i++)
		{
			cout << "x";
		}
		cout << "\nXbox\t|";
		for (int i = 0; i < savedData[3]; i++)
		{
			cout << "x";
		}
		cout << "\nPlaystat|";
		for (int i = 0; i < savedData[4]; i++)
		{
			cout << "x";
		}
		cout << "\nWii\t|";
		for (int i = 0; i < savedData[5]; i++)
		{
			cout << "x";
		}

		//Q3
		cout << "\n\nQuestion 3:" << endl << "What genre of games do you play the most?" << endl;
		cout << "FPS\t|";
		for (int i = 0; i < savedData[6]; i++)
		{
			cout << "x";
		}
		cout << "\nRPG\t|";
		for (int i = 0; i < savedData[7]; i++)
		{
			cout << "x";
		}
		cout << "\nStrategy|";
		for (int i = 0; i < savedData[8]; i++)
		{
			cout << "x";
		}
		cout << "\nOther\t|";
		for (int i = 0; i < savedData[9]; i++)
		{
			cout << "x";
		}

		//Q4
		cout << "\n\nQuestion 4:" << endl << "What is your age?" << endl;
		cout << "0-10\t|";
		for (int i = 0; i < savedData[10]; i++)
		{
			cout << "x";
		}
		cout << "\n11-20\t|";
		for (int i = 0; i < savedData[11]; i++)
		{
			cout << "x";
		}
		cout << "\n21-30\t|";
		for (int i = 0; i < savedData[12]; i++)
		{
			cout << "x";
		}
		cout << "\n31+\t|";
		for (int i = 0; i < savedData[13]; i++)
		{
			cout << "x";
		}

		//Q5
		cout << "\n\nQuestion 5:" << endl << "How many hours do you play per week?" << endl;
		cout << "0-1\t|";
		for (int i = 0; i < savedData[14]; i++)
		{
			cout << "x";
		}
		cout << "\n2-4\t|";
		for (int i = 0; i < savedData[15]; i++)
		{
			cout << "x";
		}
		cout << "\n5-7\t|";
		for (int i = 0; i < savedData[16]; i++)
		{
			cout << "x";
		}
		cout << "\n8+\t|";
		for (int i = 0; i < savedData[17]; i++)
		{
			cout << "x";
		}

		//Q6
		cout << "\n\nQuestion 6:" << endl << questionAdd[0] << endl;
		cout << endl << questionAdd[1] << "\t|";
		for (int i = 0; i < savedData[18]; i++)
		{
			cout << "x";
		}
		cout << endl << questionAdd[2] << "\t|";
		for (int i = 0; i < savedData[19]; i++)
		{
			cout << "x";
		}
		cout << endl << questionAdd[3] << "\t|";
		for (int i = 0; i < savedData[20]; i++)
		{
			cout << "x";
		}
		cout << endl << questionAdd[4] << "\t|";
		for (int i = 0; i < savedData[21]; i++)
		{
			cout << "x";
		}

		//Q7
		cout << "\n\nQuestion 7:" << endl << questionAdd[5] << endl;
		cout << endl << questionAdd[6] << "\t|";
		for (int i = 0; i < savedData[22]; i++)
		{
			cout << "x";
		}
		cout << endl << questionAdd[7] << "\t|";
		for (int i = 0; i < savedData[23]; i++)
		{
			cout << "x";
		}
		cout << endl << questionAdd[8] << "\t|";
		for (int i = 0; i < savedData[24]; i++)
		{
			cout << "x";
		}
		cout << endl << questionAdd[9] << "\t|";
		for (int i = 0; i < savedData[25]; i++)
		{
			cout << "x";
		}

		cout << "\n\n";
		cout << "Do you want to restart? (y/n): ";
		cin >> restart;
	}
	while (restart != 'n');

	//end program
	system("pause");
	return 0;
}