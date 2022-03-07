#include <iostream>
#include <vector>
#include "prof.h"



int main() 
{
	std::vector<ProfStyd> student;
	std::vector<ProfStaff> staff;
	Budget* budget=new Budget;
	SU su;
	std::vector<Event> event;


	student=Set_list_stud(student);
	staff = Set_list_staff(staff);
	budget->Set_budget();
	event=Set_event_list(event);


	std::string choice;
	int number;

	do
	{

		std::cout << "Who are you?" << std::endl << "student or staff" << std::endl;
		
		std::cin >> choice;

		
		if (strcmp(choice.c_str(), "exit") == 0)
		{
			break;
		}
		

		if (strcmp(choice.c_str(), "student") == 0)
		{
			std::cout << "Enter your name" << std::endl;
			std::cin >> su.name;
			std::cout << "Enter your surname" << std::endl;
			std::cin >> su.surname;
			int k = 0;
			for (int i = 0; i < student.size(); i++)
			{
				if (strcmp(su.name.c_str(), student[i].get_name().c_str()) == 0)
				{
					if (strcmp(su.surname.c_str(), student[i].get_surname().c_str()) == 0)
					{
						number = i;
						k++;
					}
					
				}
			}
			if (k != 0)
			{

				su.pay = student[number].get_pay();


				//Menu!!!
				menu_stud();
				int i_choice;
				std::cin >> i_choice;
				switch (i_choice)
				{
					default:
						break;
					case 1:
					{
						student = add_student(student);
						break;
					}
					case 2:
					{
						application_for_fin_ass(su,budget);
						break;
					}
					case 3:
					{
						application_for_mat_sup(su,budget);
						break;
					}
					case 4:
					{
						event=Entry_to_event(event, su);
						break;
					}
				}
			}
			else
			{
				std::cout << "Do you want register?" << std::endl << "y/n" << std::endl;
				std::string choice1;
				std::cin >> choice1;
				if (strcmp(choice1.c_str(), "y") == 0)

					student=add_student(student);
			}
		}
		
		if ((strcmp(choice.c_str(), "staff") == 0))
		{
			std::cout << "Enter your name" << std::endl;
			std::cin >> su.name;
			std::cout << "Enter your surname" << std::endl;
			std::cin >> su.surname;
			int k=0;
			for (int i = 0; i < staff.size(); i++)
			{
					if (strcmp(su.name.c_str(), staff[i].get_name().c_str()) == 0)
					{
						if (strcmp(su.surname.c_str(), staff[i].get_surname().c_str()) == 0)
						{
							number = i;
							k++;
						}
					}				
			}
			if (k != 0)
			{
				su.pay = staff[number].get_pay();

				menu_staff();
				int i_choice;
				std::cin >> i_choice;
				switch (i_choice)
				{
					default:
						break;
					case 1:
					{
						student = add_student(student);
						break;
					}
					case 2:
					{
						staff = add_staff(staff);
						break;
					}
					case 3:
					{
						application_for_mat_sup(su,budget);
						break;
					}
					case 4:
					{
						event=add_event(event, budget);
						break;
					}
					case 5:
					{
						event=Entry_to_event(event, su);
						break;
					}
					case 6:
					{
						look_budget(budget);
						break;
					}
					case 7:
					{
						add_money(budget);
						break;
					}
				}
			}
			else
			{
				std::cout << "You are not in the system" << std::endl << "Contact a registered employee for help" << std::endl;
			}
		}
		else
		{
				std::cout << "Rewrite your choice" << std::endl;
		}
		
	} while (true);

	/*std::cout << "stud" << std::endl;
	for (int i = 0; i < stud_size; i++)
	{
		std::cout << student[i].get_name() << " " << student[i].get_surname() << " " << student[i].get_step() << " " << student[i].get_pay() << std::endl;
	}
	
	std::cout << "staff" << std::endl;
	for (int i = 0; i < staff_size; i++)
	{
		std::cout << staff[i].get_name() << " " << staff[i].get_surname() << " " << staff[i].get_pay() << std::endl;
	}

	std::cout << "budget" << std::endl;
	
		std::cout << budget->get_finanse_assist() 
			<< " " << budget->get_mater_sup() << " " << budget->get_finance_other() << std::endl;*/
	
		

	

	for (int i = 0; i < student.size(); i++)
	{
		student[i].save_student(i);
	}
	for (int i = 0; i < staff.size(); i++)
	{
		staff[i].save_staff(i);
	}
	budget->save_budget();
	save_event(event);

	student.clear();
	staff.clear();
	delete budget;
	event.clear();
	system("pause");
	return 0;
}