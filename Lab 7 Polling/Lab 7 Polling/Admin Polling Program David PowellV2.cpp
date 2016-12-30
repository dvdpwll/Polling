//David Powell
//CIT-120
//12/13/14
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
-calculate results and display statistics (+)
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
	const int POLL_ANSWERS = 5;
	int answers[POLL_ANSWERS] = { 1, 1, 1, 1, 1 };
	int userData[19];
	int savedData[19];
	int count = 0;
	char restart;
	int choice = 0;
	char question1[100];
	char question2[100];
	char q1a1[20];
	char q1a2[20];
	char q1a3[20];
	char q1a4[20];
	char q2a1[20];
	char q2a2[20];
	char q2a3[20];
	char q2a4[20];
	string questionAdd[10];


	//restart program
	do
	{
		//ask if they want to see data or edit questions
		while (true)
		{
			cout << "Do you want to add questions to poll or see results of the poll. \n";
			cout << "1) View results. \n2) Add questions.\n";
			cout << "Selection:";
			string tmp;
			getline(cin, tmp);
			if (stringstream(tmp) >> choice)
				break;
		};

		if (choice == 1)
		{	
			//view the results of the poll.
			//open file and store previously saved data to an array
			ifstream inSaveDataFile;
			inSaveDataFile.open("pollDataFile.txt");
			while (count < 27 && inSaveDataFile >> savedData[count])
				count++;
			inSaveDataFile.close();


			//write the new saveData to a file
			ofstream outSaveDataFile;
			outSaveDataFile.open("pollDataFile.txt");
			for (count = 0; count < 27; count++)
				outSaveDataFile << savedData[count] << endl;
			outSaveDataFile.close();

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
		else if (choice == 2)
		{
			//add code to add questions to user polls
			cout << "\nYou may add up to two new questions.";

			//write the new saveData to a file
			ofstream outQuestions;
			outQuestions.open("AddQuestions.txt");
			for (count = 1; count < 3; count++)
			{
				cout << "\nEnter your question for #" << count << ".\n";
				cin.getline(question1,100);
				outQuestions << question1 << endl;

				cout << "\nEnter answer 1 for question #" << count << ".\n";
				cin.getline(q1a1,20);
				outQuestions << q1a1 << endl;
				cout << "\nEnter answer 2 for question #" << count << ".\n";
				cin.getline(q1a2,20);
				outQuestions << q1a2 << endl;
				cout << "\nEnter answer 3 for question #" << count << ".\n";
				cin.getline(q1a3,20);
				outQuestions << q1a3 << endl;
				cout << "\nEnter answer 4 for question #" << count << ".\n";
				cin.getline(q1a4,20);
				outQuestions << q1a4 << endl;
			}
			outQuestions.close();

			cout << "Do you want to restart? (y/n): ";
			cin >> restart;
		}
		else
		{
			cout << "Selection invalid.\n";
			cout << "Do you want to restart? (y/n): ";
			cin >> restart;

		}
	} while (restart != 'n');

	//end program
	system("pause");
	return 0;
}