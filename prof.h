#pragma once
#include <string>
#include <vector>

class ProfStyd {
	public:
		ProfStyd();
		~ProfStyd();

		void save_student(int);
		

		std::string get_name();
		std::string get_surname();
		int get_step();
		bool get_pay();

		void set_name(std::string);
		void set_surname(std::string);
		void set_step(int);
		void set_pay(bool);
		
	private:
		std::string name;
		std::string surname;
		//курс
		int step;
		bool pay;
};

class ProfStaff {
	public:
		ProfStaff();
		~ProfStaff();

		void save_staff(int);


		std::string get_name();
		std::string get_surname();
		bool get_pay();

		void set_name(std::string);
		void set_surname(std::string);
		void set_pay(bool);
		

	private:
		std::string name;
		std::string surname;
		bool pay;
};

class Budget {
	public:
		Budget();
		~Budget();

		void Set_budget();

		void save_budget();

		
		int get_finanse_assist();
		int get_mater_sup();
		int get_finance_other();

		
		void set_finanse_assist(int);
		void set_mater_sup(int);
		void set_finance_other(int);


	private:
		
		//мат помощь по категориям
		int finance_assist;
		//мат поддрежка
		int material_support;
		//др
		int finance_other;
};
struct SU
{
	std::string name;
	std::string surname;
	bool pay;
};
struct Event
{
	std::string title;
	int max_participants;
	int current_participants;
	int budget;
};
struct Event_rec
{
	std::string title;
	std::string name;
	std::string surname;
};

std::vector<Event> Set_event_list(std::vector<Event>);
void save_event(std::vector<Event>);
std::vector<Event> add_event(std::vector <Event>, Budget* budget);
std::vector<Event> Entry_to_event(std::vector<Event>, SU);

void application_for_fin_ass(SU,Budget*);
void application_for_mat_sup(SU,Budget*);

std::vector<ProfStyd> Set_list_stud(std::vector<ProfStyd>);
std::vector<ProfStaff> Set_list_staff(std::vector<ProfStaff>);



std::vector<ProfStyd> add_student(std::vector<ProfStyd>);
std::vector<ProfStaff> add_staff(std::vector<ProfStaff>);
std::vector<Event> add_event(std::vector <Event>);

void menu_stud();
void menu_staff();

void look_budget(Budget*);
void add_money(Budget*);
void take_fin_ass(Budget*);
void take_mat_sup(Budget*);