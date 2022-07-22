#include <iostream>

#include <fstream>

#include <string>

#include <ctime>



using namespace std;



struct Task {

	string name;

	int dueDay;

	int dueMonth;

	int dueYear;

	bool isComplete = false;

	int priority;

};

enum Actions { stop = 0, view = 1, remove_r = 2, add = 3, mark = 4 };

void input(Task*, int&);

void viewTasks(Task*, int);

void addTasks(Task*,int&);

void removeTasks(Task*,int&);

const int MAX_SIZE = 15;



int main() {

	Task* pList;
  static Task tasks[MAX_SIZE];
  int numOfTasks=0;
	int action;
  input(tasks, numOfTasks);
  pList=tasks;

	do {

		cout << "\nMenu:" << endl;

		cout << "0 - exit" << endl;

		cout << "1 - view tasks" << endl;

		cout << "2 - remove a task" << endl;

		cout << "3 - add a tasks" << endl;

		cout << "4 - mark task as completed" << endl;

		cout << "What would you like to do next? Enter a number: ";

		cin >> action;



		switch (action) {

		case stop:

			cout << "Thank you for choosing Anderson Inc. Hope to see you soon!" << endl;

			break;

		case view:

			viewTasks(pList, numOfTasks);

			break;

		case remove_r:

			removeTasks(pList, numOfTasks);

			break;

		case add:

			addTasks(pList,numOfTasks);

			break;

		case mark:

			break;

		}



	} while (action != stop);

	return 0;







}

void input(Task* tasks, int &numOfTasks)

{

	//read in the tasks records from a file

	string result = "not completed";

	ifstream ifs("tasksRecords.txt");

	string name;

	int dueDay, dueMonth, dueYear, priority;



	if (ifs.fail()) {

		cout << "Error opening tasks records file (tasksRecords.txt)" << endl;

		exit(1);

	}

	while (!ifs.eof()) {

		ifs >> name >> dueDay >> dueMonth >> dueYear >> priority;



		tasks[numOfTasks].name = name;

		tasks[numOfTasks].dueDay = dueDay;

		tasks[numOfTasks].dueMonth = dueMonth;

		tasks[numOfTasks].dueYear = dueYear;

		tasks[numOfTasks].priority = priority;

		numOfTasks++;

	}

	ifs.close();

}

void removeTasks(Task* tasks, int &numOfTasks) {

	string name;

	cout << "Enter the name of the task you want to remove"<<endl;

	cin >> name;

	for (int i = 0; i < numOfTasks; i++)

	{

		if (tasks[i].name == name)

		{

			tasks[i] = tasks[numOfTasks - 1];

			numOfTasks--;

		}

	}



}

void addTasks(Task* tasks, int &numOfTasks) {

	string n;

	int d, m, y, p;

	if (numOfTasks < MAX_SIZE)

	{

		cout << "Enter the name of the task, the priority, and then the date in the format: 'name priority month day year'" << endl;

		cin >> n >> p >> m >> d >> y;

		Task t;

		t.name = n;

		t.dueMonth = m;

		t.dueDay = d;

		t.dueYear = y;

		t.priority = p;

		tasks[numOfTasks] = t;

		numOfTasks++;

	}

}

void viewTasks(Task* tasks, int numOfTasks) 
{
	cout << numOfTasks << " tasks records read ... " << endl;

	cout << "name" << '\t' << "dueDay/dueMonth/dueYear" << '\t' << "priority" << endl;

	for (int j = 0; j < numOfTasks; j++) {



		cout << tasks[j].name << '\t' << tasks[j].dueDay << '/' << tasks[j].dueMonth << '/' << tasks[j].dueYear << '\t' << tasks[j].priority << endl;

	}

}







