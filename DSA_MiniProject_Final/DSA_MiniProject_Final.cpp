//try class with public X, Y coordinates
//change status to bool var

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <list>
#include <iterator>
#include <deque>
using namespace std;

//function prototypes

int findMin(int d) {
	int dist = 0;
	if (d != 0) {
		dist = dist + d;
	}
	else 
		if (d == 0){

	}
	cout << "dist is " << dist << endl;
	return dist;
}
	
			//cout << "else dist is " << dist << endl;
		//}
		
			
		
	





//class declarations
class lage {
public:
	lage(int, int, bool, int);
	int X = 0;
	int Y = 0;
	bool S = 0;
	int D = 0;
};

//constructors - automatically create class object
//do we need this?
lage::lage(int x, int y, bool s, int d) {
	X = x;
	Y = y;
	S = s;
	D = d;
}

//main function
int main() {

	//File output
	ifstream locFile, sizeFile;
	string line, total_no;
	locFile.open("coordinates.txt"); //open coordinates file
	sizeFile.open("size.txt"); //open rack size file
	getline(sizeFile, total_no);
	cout << "size = " << total_no << endl;


	bool status = 0;
	int distance = 0;
	int mind = 0;
	list<lage> lagen;
	list<lage>::iterator pos;

	for (int i = 0; i < total_no[0] - 48; i++) {
		getline(locFile, line);
		int X = line[0] - 48;
		int Y = line[2] - 48;
		bool S = status;
		int D = distance;

		lagen.push_back(lage(X, Y, S, D));
	}

	cout << "\nX-coordinate " << "\t" << "Y-coordinate " << "\t" << "Status" << "\t\t" << "Distance" << endl;
	for (pos = lagen.begin(); pos != lagen.end(); pos++) {
		cout << pos->X << "\t\t";
		cout << pos->Y << "\t\t";   //(*pos).X
		cout << pos->S << "\t\t";
		cout << pos->D << endl;
	}
	cout << endl;

	//this is the for-loop that works (only one iterator++)
	for (pos = lagen.begin(); pos != lagen.end(); )
	{
	
		int x1 = pos->X;
		int y1 = pos->Y;
		pos++;

		for (pos = lagen.begin(); pos != lagen.end(); pos++)
		{
			int x2 = pos->X;
			int y2 = pos->Y;
			

			int xval = x1 - x2;
			cout << "xval =" << xval << endl;
			int yval = y1 - y2;
			cout << "yval =" << yval << endl;
			pos->D = abs(xval + yval);
			cout << "dist: " << pos->D << endl << endl;
			/*
			mind = findMin(pos->D);
			cout << "Minimum Distance is " << mind;
			*/
		}

	}
	cout << "\nX-coordinate " << "\t" << "Y-coordinate " << "\t" << "Status" << "\t\t" << "Distance" << endl;
	for (pos = lagen.begin(); pos != lagen.end(); pos++) {
		cout << pos->X << "\t\t";
		cout << pos->Y << "\t\t";
		cout << pos->S << "\t\t";
		cout << pos->D << endl;
	}
	cout << endl;

	
	deque<lage> queue;
	deque<lage>::iterator qpos;

	for (pos = lagen.begin(); pos != lagen.end(); pos++ ) {

			queue.push_back(*pos);
			mind = findMin(pos->D);
			
			
	}
	
	
	
	cout << "\n\nIn queue: " << endl;
	cout << "\nX-coordinate " << "\t" << "Y-coordinate " << "\t" << "Status" << "\t\t" << "Distance" << endl;
	for (qpos = queue.begin(); qpos != queue.end(); qpos++) {
		cout << qpos->X << "\t\t";
		cout << qpos->Y << "\t\t";
		cout << qpos->S << "\t\t";
		cout << qpos->D << endl;
	}
	cout << endl;
	cout << "Minimum Distance is " << mind;

}




