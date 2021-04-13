#include "Simple_window.h" // get access to our window library
#include "Graph.h" // get access to our graphics library facilities

struct Person
{
	private:
		string first_name,second_name;
		int age;

	public:
	

			//constructor
			Person(string aFirstName,string aSecondName , int aAge)
			{
				first_name = aFirstName;
				second_name = aSecondName;
				age = aAge;

			}

			//setters
			void setFirstName(string fnev)
			{
				first_name = fnev;

			}
			void setSecondName(string snev)
			{
				second_name = snev;
				
			}
			void setAge(int kor)
			{
				age = kor;
			}

			//getters
			string getFirstName()
			{
				return first_name;
			}
			string getSecondName()
			{
				return second_name;
			}
			int getAge()
			{
				return age;
			}
};

istream& operator>> (istream& in, Person& data)
	{
		string first_name, second_name;
		int age;

		in>>first_name>>second_name>>age;

		if(age>150 || age<0)
			error("What?");

		string deviant = {';',':','"','[',']','*','&','^','%','$','#','@','!'};
		for(auto letter:deviant)
			{
				if(first_name.find(letter)<first_name.length())
					error("Incorrect character in First Name!");
			}

		for(auto letter:deviant)
			{
				if(second_name.find(letter)<second_name.length())
					error("Incorrect character in Second Name!");
			}
		data.setFirstName(first_name);
		data.setSecondName(second_name);
		data.setAge(age);

		return in;
	}

ostream& operator<< (ostream& ou, Person& data)
	{

		ou<<data.getFirstName()<<' '<<data.getSecondName()<<' '<<data.getAge()<<endl;
		return ou;
	}



int main()
{
/*
Person p1;

	cin >> p1;
   cout << p1;
*/
Person first;

vector <Person> Villagers;
while(cin >> first)
{
	Villagers.push_back(first);
	cout << Villagers[Villagers.size()-1];
}

}
