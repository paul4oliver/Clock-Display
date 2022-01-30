// Created by: Paul Oliver 

#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<conio.h>
#include <string>

#include<stdlib.h>

// To do : in line comments, appropriate naming, more functions if possible, add "12-Hour Clock" and "24-Hour Clock"
using namespace std;

// Print top border with ** and 12 hour/12 hour on line below
void borderTop() {
	cout << std::setfill('*') << setw(15) << '*' << "   "  << std::setfill('*') << setw(15) << '*' << endl;
	cout << "*   12 HOUR   *   *   24 HOUR   *" << endl;
}

// Print bottom border 
void borderBottom() {
	cout << std::setfill('*') << setw(15) << '*' << "   " << std::setfill('*') << setw(15) << '*' << endl;
}

// Print display menu
void displayMenu() {
	cout << std::setfill('*') << setw(30) << '*' << endl;
	cout << '*' << std::left << setfill(' ') << setw(30 - 2) << " 1 - Add One Hour" << '*' << endl;
	cout << '*' << std::left << setfill(' ') << setw(30 - 2) << " 2 - Add One Minute" << '*' << endl;
	cout << '*' << std::left << setfill(' ') << setw(30 - 2) << " 3 - Add One Second" << '*' << endl;
	cout << '*' << std::left << setfill(' ') << setw(30 - 2) << " 4 - Exit Program" << '*' << endl;
	cout << std::setfill('*') << setw(30) << '*' << endl;
}

// Display clock until keybpard button hit.
void displayClock(int hour, int minute, int seconds, int mHour, int mMinute, int mSeconds) {
	string addZero = "0";
	string pm = " PM *   *  ";
	string am = " AM *   *  ";
	bool stayOnClock = true;
	int stdHour = hour, stdMinute = minute, stdSeconds = seconds;
	int zuluHour = mHour, zuluMinute = mMinute, zuluSeconds = mSeconds;

	/* While displaying clock: 
	 *		Wait 1 second, clear screen, increment standard second (12 hr) and zulu second (24 hr)
	 *		Change seconds and minutes back to 0 when 60 is reached, and increment minute or hour
	 *		Change standard hour (12 hr) to 1 when 13 reached
	 *		Change zulu hour (24 hr) to 1 when 24 reached*/

	while (stayOnClock) {

		if (stdSeconds == 60) {
			stdSeconds = 0;
			zuluSeconds = 0;
			stdMinute++;
			zuluMinute++;
		}

		if (stdMinute == 60) {
			stdMinute = 0;
			zuluMinute = 0;
			stdHour++;
			zuluHour++;
		}

		if (stdHour == 13) {
			stdHour = 1;
		}

		if (zuluHour == 24) {
			zuluHour = 0;
		}


		system("CLS");
		// STANDARD TIME 12 HOUR FORMAT
		// If standard hour is between 1 and 9, display a zero before the hour
		if (stdHour > 0 && stdHour < 10) {
			// If standard hour and minute are between 1 and 9 display a zero before the hour and minute
			if (stdMinute >= 0 && stdMinute < 10) {
				// If standard hour, minute, and seconds are between 1 and 9 , display a zero before the hour, minute, and second
				if (stdSeconds >= 0 && stdSeconds < 10) {
					borderTop();
					// If zulu hour (24 hour) between 13 and 23, dispay PM else display AM
					// 0#:0#:0#
					if (zuluHour >= 12 && zuluHour <= 23) {
						cout << "* " << addZero << stdHour << ":" << addZero << stdMinute << ":" << addZero << stdSeconds << pm;
					}
					else {
						cout << "* " << addZero << stdHour << ":" << addZero << stdMinute << ":" << addZero << stdSeconds << am;
					}
				}

				else {
					borderTop();
					// 0#:0#:##
					if (zuluHour >= 12 && zuluHour <= 23) {
						cout << "* " << addZero << stdHour << ":" << addZero << stdMinute << ":" << stdSeconds << pm;
					}
					else {
						cout << "* " << addZero << stdHour << ":" << addZero << stdMinute << ":" << stdSeconds << am;
					}
				}
			}
			else {
				// 0#:##:##
				borderTop();
				if (zuluHour >= 12 && zuluHour <= 23) {
					cout << "* " << addZero << stdHour << ":" << stdMinute << ":" << stdSeconds << pm;
				}
				else {
					cout << "* " << addZero << stdHour << ":" << stdMinute << ":" << stdSeconds << am;
				}
			}
		}

		else if (stdMinute >= 0 && stdMinute < 10) {
			if (stdSeconds >= 0 && stdSeconds < 10) {
				// ##:0#:0#
				borderTop();
				if (zuluHour >= 12 && zuluHour <= 23) {
					cout << "* " << stdHour << ":" << addZero << stdMinute << ":" << addZero << stdSeconds << pm;
				}

				else {
					cout << "* " << stdHour << ":" << addZero << stdMinute << ":" << addZero << stdSeconds << am;
				}
			}

			else {
				// ##:0#:##
				borderTop();
				if (zuluHour >= 12 && zuluHour <= 23) {
					cout << "* " << stdHour << ":" << addZero << stdMinute << ":" << stdSeconds << pm;
				}
				else {
					cout << "* " << stdHour << ":" << addZero << stdMinute << ":" << stdSeconds << am;
				}
			}
		}

		else if (stdSeconds >= 0 && stdSeconds < 10) {
			// ##:##:0#
			borderTop();
			if (zuluHour >= 12 && zuluHour <= 23) {
				cout << "* " << stdHour << ":" << stdMinute << ":" << addZero << stdSeconds << pm;
			}
			else {
				cout << "* " << stdHour << ":" << stdMinute << ":" << addZero << stdSeconds << am;
			}
		}

		else {
			// ##:##:##
			borderTop();
			if (zuluHour >= 12 && zuluHour <= 23) {
				cout << "* " << stdHour << ":" << stdMinute << ":" << stdSeconds << pm;
			}
			else {
				cout << "* " << stdHour << ":" << stdMinute << ":" << stdSeconds << am;
			}
		}

		// ZULU TIME 24 HOUR FORMAT
		if (zuluHour >= 0 && zuluHour < 10) {
			if (zuluMinute >= 0 && zuluMinute < 10) {
				// 0#:0#:0#
				if (zuluSeconds >= 0 && zuluSeconds < 10) {
					cout << addZero << zuluHour << ":" << addZero << zuluMinute << ":" << addZero << zuluSeconds << "   *" << endl;
					borderBottom();
				}

				// 0#:0#:##
				else {
					cout << addZero << zuluHour << ":" << addZero << zuluMinute << ":" << zuluSeconds << "   *" << endl;
					borderBottom();
				}
			}

			// 0#:##:##
			else {
				cout << addZero << zuluHour << ":" << zuluMinute << ":" << zuluSeconds << "   *" << endl;
				borderBottom();
			}
		}


		else if (zuluMinute >= 0 && zuluMinute < 10) {
			// ##:0#:0#
			if (zuluSeconds >= 0 && zuluSeconds < 10) {
				cout << zuluHour << ":" << addZero << zuluMinute << ":" << addZero << zuluSeconds << "   *" << endl;
				borderBottom();
			}

			// ##:0#:##
			else {
				cout << zuluHour << ":" << addZero << zuluMinute << ":" << zuluSeconds << "   *" << endl;
				borderBottom();
			}
		}

		// ##:##:0#
		else if (zuluSeconds >= 0 && zuluSeconds < 10) {
			cout << zuluHour << ":" << zuluMinute << ":" << addZero << zuluSeconds << "   *" << endl;
			borderBottom();
		}

		// ##:##:##
		else {
			cout << zuluHour << ":" << zuluMinute << ":" << zuluSeconds << "   *" << endl;
			borderBottom();
		}

		// Wait one second, then increment seconds
		Sleep(1000);
		stdSeconds++;
		zuluSeconds++;

		/*	If keyboard is hit display menu is triggered and user asked for input: add hour, minute, second, or exit
		*	Switch statement takesz appropriate action and can increment time values
		*	When keyboard is hit, _getch() will take in character pressed and it will not display to user.
		*	Clear screen so clock is not displaying when menu is displayed 
		*	After selection made, screen returns to clock (unless 4 - exit selected, then program quits)
		*	If key pressed not on menu, clock display returns unaffected */
		if (_kbhit()) {
			char userInput;
			_getch(); 
			// 
			system("CLS");
			displayMenu();

			cin >> userInput;

			switch (userInput) {
			case '1':
				stdHour = stdHour++;
				zuluHour = zuluHour++;
				break;


			case '2':
				stdMinute = stdMinute++;
				zuluMinute = zuluMinute++;
				break;

			case '3':
				stdSeconds = stdSeconds++;
				zuluSeconds = zuluSeconds++;
				break;

			// Exit program, boolean stayOnClock triggers end of function
			case '4':
				stayOnClock = false;
				system("CLS");
				break;

			default:
				break;
			}
		}
	}

	// Print goodbye message if function exited
	if (!stayOnClock) {
		cout << "Goodbye.";
	}
}

// Main passes integer values that are the starting time for the clocks
void main() {
	int hour = 11, minute = 59, seconds = 55;
	int mHour = 23, mMinute = 59, mSeconds = 55;
	
	displayClock(hour, minute, seconds, mHour, mMinute, mSeconds);
	cout << endl << endl;
	//Program ends when function is exited

}


		






