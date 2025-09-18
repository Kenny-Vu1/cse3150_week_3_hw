
#include <iostream>
#include <cstring>   // for strlen, strcpy

using std::strcpy, std::cout, std::cin, std::string, std::endl;

// TODO: function prototypes
// TODO: implement addStudent
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity){
	try{
		if(size == capacity){
			throw "over capacity";
		
		}
		names[size] = new char[std::strlen(name) +1];
		strcpy(names[size], name);

		gpas[size] = gpa;
		size +=1;
	}
	catch(...){
		cout << "List full";
                return;
	}
}



// TODO: implement updateGPA
void updateGPA(double* gpaPtr, double newGpa){
	*gpaPtr = newGpa;
}

// TODO: implement printStudent
void printStudent(const char* name, const double& gpa){
	cout << name << " " << gpa << endl; 	
}


// TODO: implement averageGPA
double averageGPA(const double gpas[], int size){
	
	if(size == 0){
	cout << "No students" << endl;
	return 0;
	}

	double total = 0;
	for(int i = 0; i < size; i++){
		total += gpas[i];
	}
	total = total/size;
	return total;
}


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);
    char* names[capacity];
    double gpas[capacity];
    int size = 0;

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1: {
                // TODO: implement menu logic
		string name;
		cout << "Enter a Name";
		cin >> name;
		cout << "Enter a gpa";
		double gpa;
		cin >> gpa;

                addStudent(const_cast<char*>(name.c_str()), gpa, names, gpas, size, capacity);
		break;
            }
            case 2: {
                // TODO: implement menu logic
		cout << "Input student idx";
		double *gpaPtr = nullptr;
		int idx;
		cin >> idx;
                
		cout << "Input new GPA";
		double newGpa;
		cin >> newGpa;

		if(idx <= size){
			gpaPtr = &gpas[idx];
			updateGPA(gpaPtr, newGpa);
		}
		break;
            }
            case 3: {
                // TODO: implement menu logic
                for(int i=0; i<size; i++){
			printStudent(names[i], gpas[i]);
		}

		break;
            }
            case 4: {
                // TODO: implement menu logic
                double avg = averageGPA(gpas, size);
		cout << "Average GPA: " << avg <<endl;
		break;
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);

    // TODO: free memory
	for( int i = 0; i< size; i++){
		delete[] names[i];
	}

    return 0;
}
