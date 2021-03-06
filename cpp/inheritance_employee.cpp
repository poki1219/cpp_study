#include	<iostream>

class Employee{
protected:
	std::string name;
	int age;
	std::string position;
	int rank;
public:
	Employee(std::string name, int age, std::string position, int rank)
		:name(name), age(age), position(position), rank(rank){}

	Employee(const Employee& employee){
		name = employee.name;
		age = employee.age;
		position = employee.position;
		rank = employee.rank;
	}

	Employee(){}

	virtual void print_info(){
		std::cout << name << "(" << position << ", " << age << ") ==> " << calculate_pay() << std::endl;
	}

	virtual int calculate_pay() {
		return 200 + rank * 50;
	}

};

class Manager : public Employee{
private:
	int year_of_serv;

public:
	Manager(std::string name, int age, std::string position, int rank, int year_of_serv)
		:Employee(name, age, position, rank), year_of_serv(year_of_serv){}

	Manager(const Manager& manager){
		Employee(manager.name, manager.age, manager.position, manager.rank);
		year_of_serv = manager.year_of_serv;
	}

	Manager() {
		Employee();
	}

	int calculate_pay() override{
		return 200 + rank * 50 + 5* year_of_serv;
	}

	void print_info() override{
		std::cout << name << "(" << position << ", " << age << ", " << year_of_serv << ") ==> " << calculate_pay() << std::endl;
	}
};

class EmployeeList{
	int alloc_employee;
	int current_employee;
	Employee** employee_list;

public:
	EmployeeList(int alloc_employee) : alloc_employee(alloc_employee){
		employee_list = new Employee*[alloc_employee];

		current_employee = 0;
	}

	void add_employee(Employee* employee){
		employee_list[current_employee] = employee;
		current_employee++;
	}

	int current_employee_num(){
		return current_employee;
	}

	void print_employee_info(){
		int total_pay = 0;
		for(int i=0 ; i<current_employee ; i++){
			employee_list[i]->print_info();
			total_pay += employee_list[i]->calculate_pay();
		}

		std::cout << "total: " << total_pay << std::endl;
	}

	~EmployeeList(){
		for(int i=0 ; i<current_employee ; i++)
			delete employee_list[i];
		delete [] employee_list;
	}
};

int main(){
	EmployeeList emp_list(10);	
	emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
	emp_list.add_employee(new Employee("하하", 34, "평사원", 1));
	emp_list.add_employee(new Manager("유재석", 41, "부장", 7, 12));	//sdf
	emp_list.add_employee(new Manager("정준하", 43, "과장", 4, 15));	//upcasting이 이루어짐
	emp_list.add_employee(new Manager("박명수", 43, "차장", 5, 13));	//->manager class의 calculate_pay를 호출하지 못함
	emp_list.add_employee(new Employee("정형돈", 36, "대리", 2));
	emp_list.add_employee(new Employee("길", 36, "인턴", -2));

	emp_list.print_employee_info();
	return 0;
}
