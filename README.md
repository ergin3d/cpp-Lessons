Create a program in C++ to manage different types of employees in a company: full-time employees, part-time employees, and interns.

Full-time employees have a name, ID, salary, and years of experience.
Part-time employees have a name, ID, salary, and hours worked per week.
Interns have a name, ID, and college.
Implement the following functionalities:

Create a base class Employee with private attributes for name, ID, and salary. Provide functions to set and get these attributes.
Derive three classes FullTimeEmployee, PartTimeEmployee, and Intern from Employee. Each derived class should have additional attributes as mentioned above.
Overload a function to calculate the monthly salary for each type of employee:
Full-time employees' salary includes a bonus based on years of experience (e.g., 5% bonus per year).
Part-time employees' salary is based on their hourly rate and hours worked per week.
Interns do not receive a salary.
Ensure proper encapsulation by using private data members and providing public member functions for accessing and modifying data.

Write a sample program that creates instances of each type of employee, sets their attributes, calculates their monthly salaries using function overloading, and displays their details along with monthly salary.
