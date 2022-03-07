#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "prof.h"


// —“”ƒ≈Ќ“џ!!!

ProfStyd::ProfStyd()
{

}

ProfStyd::~ProfStyd()
{
	//ProfStyd::save_student();
}

void ProfStyd::save_student(int i)
{
	
	std::ofstream fout("profsouz_student.txt", std::ios::app);
	if(i==0){}
	else
		fout << std::endl;
	fout << ProfStyd::get_name() << " " << ProfStyd::get_surname() << " "
		<< ProfStyd::step << " " << ProfStyd::pay;

	
	fout.close();
}


std::string ProfStyd::get_name()
{
	return ProfStyd::name;
}

std::string ProfStyd::get_surname()
{
	return ProfStyd::surname;
}

int ProfStyd::get_step()
{
	return ProfStyd::step;
}

bool ProfStyd::get_pay()
{
	return ProfStyd::pay;
}

void ProfStyd::set_name(std::string student_name)
{
	ProfStyd::name = student_name;
}

void ProfStyd::set_surname(std::string student_surname)
{
	ProfStyd::surname = student_surname;
}

void ProfStyd::set_step(int student_step)
{
	ProfStyd::step = student_step;
}

void ProfStyd::set_pay(bool student_pay)
{
	ProfStyd::pay = student_pay;
}



// —“ј‘‘!!!!

ProfStaff::ProfStaff()
{

}

ProfStaff::~ProfStaff()
{
	//ProfStaff::save_staff();
}

void ProfStaff::save_staff(int i)
{
	std::ofstream fout("profsouz_staff.txt", std::ios::app);
	if (i == 0) {}
	else
		fout << std::endl;
	fout << ProfStaff::get_name() << " " << ProfStaff::get_surname() << " " << ProfStaff::get_pay();

	
	fout.close();
}

std::string ProfStaff::get_name()
{
	return ProfStaff::name;
}

std::string ProfStaff::get_surname()
{
	return ProfStaff::surname;
}

bool ProfStaff::get_pay()
{
	return ProfStaff::pay;
}

void ProfStaff::set_name(std::string staff_name)
{
	ProfStaff::name = staff_name;
}

void ProfStaff::set_surname(std::string staff_surname)
{
	ProfStaff::surname = staff_surname;
}

void ProfStaff::set_pay(bool staff_pay)
{
	ProfStaff::pay = staff_pay;
}


// Ѕёƒ∆≈“!!!!

Budget::Budget()
{

}

Budget::~Budget()
{
	/*Budget::save_budget();*/
}

void Budget::save_budget()
{
	std::ofstream fout("profsouz_budget.txt", std::ios::app);
	fout << Budget::finance_assist << " " << Budget::material_support << " " << Budget::finance_other;

	
	fout.close();
}


void Budget::set_finanse_assist(int fin_assist)
{
	Budget::finance_assist = fin_assist;
}
void Budget::set_mater_sup(int material_sup)
{
	Budget::material_support = material_sup;
}
void Budget::set_finance_other(int fin_other)
{
	Budget::finance_other = fin_other;
}


int Budget::get_finanse_assist()
{
	return Budget::finance_assist;
}
int Budget::get_mater_sup()
{
	return Budget::material_support;
}
int Budget::get_finance_other()
{
	return Budget::finance_other;
}


// ќЅў»≈!!!

std::vector<ProfStyd> Set_list_stud(std::vector<ProfStyd> student)
{
	std::ifstream fin("profsouz_student.txt", std::ios::in);
	if (!fin.is_open()) // если файл не открыт
		std::cout << "Fail open file\n"; // сообщить об этом
	else
	{
		while (!fin.eof())
		{
			ProfStyd buff;
			std::string str_buff;
			int i_buff;
			bool b_buff;

			fin >> str_buff;
			buff.set_name(str_buff);
			//str_buff = "";
			fin >> str_buff;
			buff.set_surname(str_buff);
			fin >> i_buff;
			buff.set_step(i_buff);
			fin >> b_buff;
			buff.set_pay(b_buff);
			student.push_back(buff);
		}
	}

	fin.close();

	std::ifstream fdel("profsouz_student.txt", std::ios::trunc| std::ios::out);
	fdel.close();
	return student;
}


std::vector<ProfStaff> Set_list_staff(std::vector<ProfStaff> staff)
{
	std::ifstream fin("profsouz_staff.txt", std::ios::in);
	if (!fin.is_open()) // если файл не открыт
		std::cout << "Fail open file\n"; // сообщить об этом
	else
	{
		while (!fin.eof())
		{
			ProfStaff buff;
			std::string str_buff;
			bool b_buff;

			fin >> str_buff;
			buff.set_name(str_buff);
			//str_buff = "";
			fin >> str_buff;
			buff.set_surname(str_buff);
			fin >> b_buff;
			buff.set_pay(b_buff);
			staff.push_back(buff);
		}
	}

	fin.close();

	std::ifstream fdel("profsouz_staff.txt", std::ios::trunc | std::ios::out);
	fdel.close();
	return staff;
}

void Budget::Set_budget()
{
	std::ifstream fin("profsouz_budget.txt", std::ios::in);
	if (!fin.is_open()) // если файл не открыт
		std::cout << "Fail open file\n"; // сообщить об этом
	else
	{
		int i_buff;
			
		fin >> i_buff;
		Budget::set_finanse_assist(i_buff);
		fin >> i_buff;
		Budget::set_mater_sup(i_buff);
		fin >> i_buff;
		Budget::set_finance_other(i_buff);
	}

	fin.close();

	std::ifstream fdel("profsouz_budget.txt", std::ios::trunc | std::ios::out);
	fdel.close();

}


std::vector<ProfStyd> add_student(std::vector<ProfStyd> stud)
{
	ProfStyd buff;
	std::string s_buff;
	int i_buff;
	bool b_buff;
	int choice;

	do
	{
		std::cout << "ADD STUDENT" << std::endl;

		std::cout << "name" << std::endl;
		std::cin >> s_buff;
		buff.set_name(s_buff);

		std::cout << "surname" << std::endl;
		std::cin >> s_buff;
		buff.set_surname(s_buff);

		std::cout << "step" << std::endl;
		std::cin >> i_buff;
		buff.set_step(i_buff);

		std::cout << "pay 1/0" << std::endl;
		std::cin >> b_buff;
		buff.set_pay(b_buff);

		stud.push_back(buff);

		std::cout << "student added" << std::endl;
		std::cout << "Do you want add another one?" << std::endl << "1/0" << std::endl;
		std::cin >> choice;
	} while (choice==1);
	return stud;
}

std::vector<ProfStaff> add_staff(std::vector<ProfStaff> staff)
{
	std::cout << "Add staff" << std::endl;
	ProfStaff buff;
	std::string s_buff;
	bool b_buff;
	int choice;

	do
	{
		std::cout << "ADD STAFF" << std::endl;

		std::cout << "name" << std::endl;
		std::cin >> s_buff;
		buff.set_name(s_buff);

		std::cout << "surname" << std::endl;
		std::cin >> s_buff;
		buff.set_surname(s_buff);

		std::cout << "pay 1/0" << std::endl;
		std::cin >> b_buff;
		buff.set_pay(b_buff);

		staff.push_back(buff);

		std::cout << "staff added" << std::endl;
		std::cout << "Do you want add another one?" << std::endl << "1/0" << std::endl;
		std::cin >> choice;
	} while (choice == 1);
	return staff;
}

//FINANCE

void application_for_fin_ass(SU su,Budget* budget)
{
	std::cout << "Application for finance assist" << std::endl;
	if (su.pay == 0)
	{
		std::cout << "make a membership fee" << std::endl;
	}
	else
	{
		std::cout << "Choose your categories:" << std::endl
			<< "1.Accommodation in Chernobyl" << std::endl
			<< "2.Breadwinner" << std::endl
			<< "3.The large family" << std::endl
			<< "4.Orphans" << std::endl
			<< "5.Disabled parents, citizens" << std::endl
			<< "6.Students with children" << std::endl
			<< "7.Single mother, parents divorce" << std::endl
			<< "8.Dispensary accounting" << std::endl;
		int choice;
		std::string category;
		std::cin >> choice;
		switch (choice)
		{
			default:
				break;
			case 1:
			{
				category = "Accommodation in Chernobyl";
				break;
			}
			case 2:
			{
				category = "Breadwinner";
			}
			case 3:
			{
				category = "The large family";
			}
			case 4:
			{
				category = "Orphans";
			}
			case 5:
			{
				category = "Disabled parents, citizens";
			}
			case 6:
			{
				category = "Students with children";
			}
			case 7:
			{
				category = "Single mother, parents divorce";
			}
			case 8:
			{
				category = "Dispensary accounting";
			}
		}

		take_fin_ass(budget);
		std::ofstream fout("application for finance assist.txt", std::ios::app);
		fout << su.name << " " << su.surname << " " << category << std::endl;

		fout.close();
	}
}

void application_for_mat_sup(SU su,Budget* budget)
{
	std::cout << "application for material support" << std::endl;
	if (su.pay == 0)
	{
		std::cout << "make a membership fee" << std::endl;
	}
	else
	{
		take_mat_sup(budget);

		std::ofstream fout("application for material_support.txt", std::ios::app);
		fout << su.name << " " << su.surname << std::endl;

		fout.close();
	}
}

void look_budget(Budget* budget)
{
	std::cout << "Look budget" << std::endl;
	std::cout << "finance assist= " << budget->get_finanse_assist() << std::endl
		<< "material support= " << budget->get_mater_sup() << std::endl
		<< "finance other= " << budget->get_finance_other() << std::endl;
}

void add_money(Budget* budget)
{
	std::cout << "Add money" << std::endl;
	int i_choice;
	std::cout << "Choose a section:" << std::endl
		<< "1.finance assist" << std::endl
		<< "2.material support" << std::endl
		<< "3.finance other" << std::endl;
	std::cin >> i_choice;
	std::cout << "How much do you want to deposit?" << std::endl;
	int money;
	std::cin >> money;
	if (i_choice == 1)
	{
		budget->set_finanse_assist(budget->get_finanse_assist() + money);
	}
	else
		if (i_choice == 2)
		{
			budget->set_mater_sup(budget->get_mater_sup() + money);
		}
		else
			if (i_choice == 3)
			{
				budget->set_finance_other(budget->get_finance_other() + money);
			}
			else
				std::cout << "not existing category selected" << std::endl;
	look_budget(budget);
}

//EVENT!!

std::vector<Event> Set_event_list(std::vector<Event> event)
{
	std::ifstream fin("event.txt", std::ios::in);
	if (!fin.is_open()) // если файл не открыт
		std::cout << "Fail open file\n"; // сообщить об этом
	else
	{
		Event buff;
		std::string s_buff;
		int i_buff;

		while (!fin.eof())
		{
			fin >> s_buff;
			buff.title = s_buff;
			fin >> i_buff;
			buff.max_participants = i_buff;
			fin >> i_buff;
			buff.current_participants = i_buff;
			fin >> i_buff;
			buff.budget = i_buff;

			event.push_back(buff);
		}
	}

	fin.close();

	std::ifstream fdel("event.txt", std::ios::trunc | std::ios::out);
	fdel.close();
	return event;
}


void save_event(std::vector<Event> event)
{

	std::ofstream fout("event.txt", std::ios::app);
	for (int i = 0; i < event.size(); i++)
	{
		if (i == 0) {}
		else
			fout << std::endl;
		fout << event[i].title << " " <<event[i].max_participants << " "<< event[i].current_participants << " " << event[i].budget;

	}
	fout.close();
}

std::vector<Event> add_event(std::vector <Event> event, Budget* budget)
{
	std::cout << "Add event" << std::endl;
	std::string s_buff;
	int i_buff;
	Event buff;

	std::cout << "write budget" << std::endl;
	std::cin >> i_buff;
	if (i_buff <= budget->get_finanse_assist())
	{
		buff.budget = i_buff;
		std::cout << "write title event" << std::endl;
		std::cin >> s_buff;
		buff.title = s_buff;
		std::cout << "write max participants" << std::endl;
		std::cin >> i_buff;
		buff.max_participants = i_buff;
		buff.current_participants = 0;

		event.push_back(buff);

		i_buff = budget->get_finance_other() - buff.budget;
		budget->set_finance_other(i_buff);
		std::cout << "Event added" << std::endl;
	}
	else
		std::cout << "not enough money" << std::endl;
	
	
	return event;
}

std::vector<Event> Entry_to_event(std::vector<Event> event, SU su)
{
	std::cout << "Entry to the event" << std::endl;
	if (su.pay == 0)
	{
		std::cout << "make a membership fee" << std::endl;
	}
	else
	{
		Event_rec even;
		std::string title;

		std::cout << "Choose event:" << std::endl;
		for (int i = 0; i < event.size(); i++)
		{
			std::cout << i + 1 << "." << event[i].title << std::endl;
		}

		int choice;
		std::cin >> choice;
		if (event[choice - 1].current_participants < event[choice - 1].max_participants)
		{
			std::cout << "Congratulations. you are registered for the event" << std::endl;

			event[choice - 1].current_participants++;
		}
		else
			std::cout << "Sorry, places are over" << std::endl;
		even.title = event[choice-1].title;
		even.name = su.name;
		even.surname = su.surname;

		std::ofstream fout("event_registr.txt", std::ios::app);
			
		fout << even.title << " " << even.name << " " << even.surname;
		fout << std::endl;
		fout.close();
	}
	return event;
}


void take_fin_ass(Budget* budget)
{
	if (budget->get_finanse_assist() >= 1500)
	{
		std::cout << "Come for the money" << std::endl;
		budget->set_finanse_assist(budget->get_finanse_assist() - 1500);
	}
	else
	{
		std::cout << "Wait in line" << std::endl;
	}
}

void take_mat_sup(Budget* budget)
{
	if (budget->get_mater_sup() >= 1500)
	{
		std::cout << "Ccome for the money" << std::endl;
		budget->set_mater_sup(budget->get_mater_sup() - 1500);
	}
	else
	{
		std::cout << "Wait in line" << std::endl;
	}
}

void menu_stud()
{
	std::cout << "1.Register student" << std::endl
		<< "2.application for finance assist	" << std::endl
		<< "3.application for material support" << std::endl
		<< "4.Entry to the event" << std::endl;
}

void menu_staff()
{
	std::cout << "1.Register student" << std::endl
		<< "2.Register staff" << std::endl
		<< "3.application for material support" << std::endl
		<< "4.Add event" << std::endl
		<< "5.Entry to the event" << std::endl
		<< "6.look at the current budget" << std::endl
		<< "7.add money to the budget" << std::endl;
}
