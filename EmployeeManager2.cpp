#include <iostream>
#include <string>

using namespace std;

//Create a base class Employee with private attributes for name, ID, and salary. Provide functions to set and get these attributes.
class Employee 
{
	private:
		int id;
		string name;
		double salary;

	public:
	        // Constructor
	        Employee(string initName, int initId, double initSalary) : name(initName), id(initId), salary(initSalary) {}
	
	        // Setters
	        void setName(string newName) {
	            name = newName;
	        }
	
	        void setId(int newId) {
	            id = newId;
	        }
	
	        void setSalary(double newSalary) {
	            salary = newSalary;
	        }
	
	        // Getters
	        string getName() const {
	            return name;
	        }
	
	        int getId() const {
	            return id;
	        }
	
	        double getSalary() const {
	            return salary;
	        }

		//Function to calculate the salary of an employee. This function should be virtual
		virtual double calculateSalary() const {
			return 0;
		}
};

class FullTimeEmployee : public Employee 
{
    private:
        int yearsOfExperience;

    public:
        // Constructor
        FullTimeEmployee(std::string initName, int initId, double initSalary, int initYearsOfExperience)
            : Employee(initName, initId, initSalary), yearsOfExperience(initYearsOfExperience) {}

        // Setter
        void setYearsOfExperience(int newYearsOfExperience) {
            yearsOfExperience = newYearsOfExperience;
        }

        // Getter
        int getYearsOfExperience() const {
            return yearsOfExperience;
        }

		// Calculate salary Full-time employees' salary includes a bonus based on years of experience (e.g., 5% bonus per year).
		double calculateSalary() const {
			double bonus = 0.05 * yearsOfExperience * getSalary();
			return getSalary() + bonus;
		}
};

class PartTimeEmployee : public Employee
{
    private:
	double hourlyRate;
	int hoursWorkedPerWeek;

    public:
	// Constructor
        PartTimeEmployee(std::string initName, int initId, double initHourlyRate, int initHoursWorkedPerWeek)
            : Employee(initName, initId, 0), hourlyRate(initHourlyRate), hoursWorkedPerWeek(initHoursWorkedPerWeek) {}
		
        // Setters
        void setHourlyRate(double newHourlyRate) {
			hourlyRate = newHourlyRate;
        }

		void setHoursWorkedPerWeek(int newHoursWorkedPerWeek) {
			hoursWorkedPerWeek = newHoursWorkedPerWeek;
		}

		// Getters
		double getHourlyRate() const {
			return hourlyRate;
		}

		int getHoursWorkedPerWeek() const {
			return hoursWorkedPerWeek;
		}

		// Calculate salary Part-time employees' salary is based on their hourly rate and hours worked per week.
        virtual double calculateSalary() const override {
            return hourlyRate * hoursWorkedPerWeek * 4; // Assuming 4 weeks in a month
        }

};

// Derive Intern from Employee.Interns have a name, ID, and college.

class Intern : public Employee
{
    
    private:
	string college;

    public:
	// Constructor
	Intern(string initName, int initId, string initCollege)
		: Employee(initName, initId, 0), college(initCollege) {}

	// Setter
	void setCollege(string newCollege) {
		college = newCollege;
	}

	// Getter
	string getCollege() const {
		return college;
	}

};

int main() 
{
    //Write a sample program that creates instances of each type of employee, sets their attributes, calculates their monthly salaries using function overloading, and displays their details along with monthly salary.

	int orginalSalary = 2000;

	FullTimeEmployee fullTimeEmployee("John Doe", 1, orginalSalary, 5);
	PartTimeEmployee partTimeEmployee("Jane Smith", 2, 20, 20);
	Intern intern("Alice Johnson", 3, "XYZ College");

	cout << "Full-time Employee:" << endl;
	cout << "Name: " << fullTimeEmployee.getName() << endl;
	cout << "ID: " << fullTimeEmployee.getId() << endl;
	cout << "Years of Experience: " << fullTimeEmployee.getYearsOfExperience() << endl;
	cout << "Montly Salary: " << orginalSalary << endl;
	cout << "Montly Salary with Bonus: " << fullTimeEmployee.calculateSalary() << endl;

	cout << endl;

	cout << "Part-time Employee:" << endl;
	cout << "Name: " << partTimeEmployee.getName() << endl;
	cout << "ID: " << partTimeEmployee.getId() << endl;
	cout << "Hourly Rate: " << partTimeEmployee.getHourlyRate() << endl;
	cout << "Hours Worked Per Week: " << partTimeEmployee.getHoursWorkedPerWeek() << endl;
	cout << "Montly Salary: " << partTimeEmployee.calculateSalary() << endl;

	cout << endl;

	cout << "Intern:" << endl;
	cout << "Name: " << intern.getName() << endl;
	cout << "ID: " << intern.getId() << endl;
	cout << "College: " << intern.getCollege() << endl;
	cout << "Montly Salary: " << intern.calculateSalary() << endl;
	
    return 0;
}
