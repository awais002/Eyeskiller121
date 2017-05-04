#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<sstream>
#include <windows.h>
#include <conio.h>
using namespace std;
void Menu(string);
void techdel();
void applicationforum();
void studdel();
void Studeacc(int mov);
void Grades();
void AllStudentsSubjects();
void datesheet();
void saveresult();
void failsubjpapers(int applicationlineno);
void studgrades(int applicationlineno);
void failedstudres();
void Main();
int *spacefounda(string);
void failedstudres();
void username();
void Acceptedapp();
void funcal();
void budget();
void teacheacc();
void times(int);
void basicinfo(string);
class Boardmember
{
protected:
	string Name, phone_No, Address, email, Qualification, Designation, Clause, id, workinghour, cnic, pass;
};
class CHAIRMAN :public Boardmember
{
public:
	void funcal()
	{
		int l = 0, m = 0, n = 0;
		int i = 0;
		int p = 0;
		int t = 0;
		int a = 0, b = 0;
		string line;
		ofstream ins;
		ifstream re;
		re.open("Accepted.txt", ios::app);
		while (getline(re, line))
		{
			t++;
		}
		re.close();
		re.open("AllStudentsApp.txt", ios::app);
		system("cls");
		while (getline(re, line))
		{
			if (t == 0)
			{
				cout << line << endl;
				i++;
			}
			else
			{
				t--;
			}
		}
		if (i != 0)
		{
			cout << "How many applications you want to proceed" << endl;
			cin >> p;
			if (p > i)
			{
				p = i;
			}
			int h;
			re.close();
			ins.open("Accepted.txt", ios::app);
			for (int i = 0; i < p; i++)
			{
				cout << "You were agreed (((111)))) or not((((000))) with " << i << "Application" << endl;
				cin >> h;
				if (h == 1)
				{
					ins << "Agreed" << endl;
				}
				else if (h == 0)
				{
					ins << "Not Agreed" << endl;
				}
				else
				{
					funcal();
				}
			}
		}
		ins.close();
	}
	void budget()
	{
		long long int as = 0;
		string line;
		ifstream re;
		string l;
		re.open("TEACHEACCEP.txt", ios::app);
		while (getline(re, line))
		{
			int found, i = 0;
			string test[8];
			string tests;
			tests = line;
			while (tests != "\0")
			{
				found = tests.find(" ");
				for (int f = 0; f < found; f++)
				{
					test[i] += tests[f];
				}
				tests.erase(0, found + 1);
				i++;
			}
			l = test[7];
			as += atof(l.c_str());
		}
		l = " ";
		re.close();
		re.open("AppAccepted.txt", ios::app);
		while (getline(re, line))
		{
			long long int ts = 0;;
			string t;
			string test[13];
			int found = 0, i = 0;
			string tests;
			tests = line;
			while (tests != "\0")
			{
				found = tests.find("<<");
				for (int f = 0; f < found; f++)
				{
					test[i] += tests[f];
				}
				tests.erase(0, found + 2);
				i++;
			}
			t = test[12];
			ts += atof(t.c_str());
			as = as - ts;
		}
		int conv = 0;
		re.close();
		re.open("BUDGET.txt", ios::app);
		while (getline(re, line))
		{
			conv = atof(line.c_str());
		}
		if (as > conv)
		{
			cout << "Your budget is increasing" << endl;
		}
		else
		{
			cout << "Your budget is decreasing" << endl;
		}
		ofstream in;
		in.open("BUDGET.txt", ios::trunc);
		in.close();
		as = conv - as;
		in.open("BUDGET.txt", ios::app);
		in << as << endl;
		cout << "Your Budget is " << as << endl;
	}
	void times(int times1)
	{
		int c = 0;
		string line;
		int date = 0;
		time_t now;
		struct tm nowLocal;
		now = time(NULL);
		nowLocal = *localtime(&now);//get time from OS
		cout << "TIme is:" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << endl;
		cin.get();
		int hr = 0, min = 0, sec = 0;
		cout << "Enter Hour" << endl;
		cin >> hr;
		if (hr > 24 && hr < 0)
		{
			times(times1);
		}
		cout << "Enter Minute" << endl;
		cin >> min;
		if (min > 60 && min < 0)
		{
			times(times1);
		}
		ofstream in;
		ifstream re;
		in.open("CM.txt", ios::app);
		in << hr << "." << min << "." << sec << "." << endl;
		if (hr == nowLocal.tm_hour&&min == nowLocal.tm_min&&sec == nowLocal.tm_sec)
		{
			date = 1;
		}
		if (date == 1 && times1 == 1)
		{
			re.close();
			in.open("CMT.txt", ios::trunc);
			in.close();
			in.open("CMT.txt");
			re.open("CM.txt", ios::app);
			while (getline(re, line))
			{
				in << line << endl;
				c++;
				if (c == 4)
				{
					in.close();
					re.close();
					in.open("CM.txt", ios::trunc);
					in.close();
					in.open("CM.txt");
					re.open("CMT.txt", ios::app);
					while (getline(re, line))
					{
						in << line << endl;
					}
				}
			}
		}
	}
	void datesheet()
	{
		int bc = 0;
		ofstream in;
		ifstream re;
		string lines;
		re.open("datesheet.txt", ios::app);
		while (getline(re, lines))
		{
			bc++;
		}
		if (bc == 0)
		{
			in.open("datesheet.txt", ios::app);
			int day, mont, year;
			time_t now;
			struct tm nowLocal;
			now = time(NULL);
			nowLocal = *localtime(&now);//get time from OS
			cout << "Date is:" << nowLocal.tm_mday << ":" << nowLocal.tm_mon + 1 << ":" << nowLocal.tm_year + 1900 << endl;
			cout << "TIme is:" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << endl;
			cin.get();
			cout << "Enter Month " << endl;
			cin >> mont;
			if (mont <= 12)
			{
				if (mont == nowLocal.tm_mon + 1 && 3 + nowLocal.tm_mon <= 12)//if (mont ==4+ nowLocal.tm_mon + 1 && 3 + nowLocal.tm_mon <= 12) after 4 months paper
				{
					cout << "Enter Year" << endl;
					cin >> year;
					if (year == nowLocal.tm_year + 1900)
					{
						cout << "Enter Day" << endl;
						cin >> day;
						in << year << " " << mont << " " << day << " " << endl;
					}
				}
			}
		}
		else
		{
			cout << "Date sheet is defined already or get result" << endl;
			Sleep(2000);
			system("cls");
		}
	}
	void studdel()
	{
		int i = 0;
		string line;
		ifstream re;
		ofstream in;
		int no;
		int aa, bb, cc, dd, ee;
		in.open("TEMP.txt", ios::trunc);
		in.close();
		in.open("TEMP.txt");
		re.open("AppAccepted.txt", ios::app);
		while (getline(re, line))
		{
			i++;
			cout << line << endl;
		}
		cout << "Which Student You want to delete" << endl;
		cin >> no;
		while (no == 0)
		{
			cout << "Enter Corret no" << endl;
			cin >> no;
		}
		if (no > i)
		{
			no = i;
		}
		aa = bb = cc = dd = ee = no;
		re.close();
		re.open("AppAccepted.txt", ios::app);
		while (getline(re, line))
		{
			if (no == 1)
			{
				no = 0;
			}
			else
			{
				no--;
				in << line << endl;
			}
		}
		in.close();
		re.close();
		in.open("AppAccepted.txt", ios::trunc);
		in.close();
		re.open("TEMP.txt", ios::app);
		in.open("AppAccepted.txt");
		while (getline(re, line))
		{
			in << line << endl;
		}
		in.close();
		re.close();
		in.open("TEMP.txt", ios::trunc);
		in.close();
		//App deleted;
		in.open("TEMP.txt");
		re.open("studentresult.txt", ios::app);
		while (getline(re, line))
		{
			if (aa == 1)
			{
				aa = 0;
			}
			else
			{
				aa--;
				in << line << endl;
			}
		}
		in.close();
		re.close();
		in.open("studentresult.txt", ios::trunc);
		in.close();
		re.open("TEMP.txt", ios::app);
		in.open("studentresult.txt");
		while (getline(re, line))
		{
			in << line << endl;
		}
		in.close();
		re.close();
		in.open("TEMP.txt", ios::trunc);
		in.close();
		//result deleted
		in.open("TEMP.txt");
		re.open("Accepted.txt", ios::app);
		while (getline(re, line))
		{
			if (bb == 1)
			{
				bb = 0;
			}
			else
			{
				bb--;
				in << line << endl;
			}
		}
		in.close();
		re.close();
		in.open("Accepted.txt", ios::trunc);
		in.close();
		re.open("TEMP.txt", ios::app);
		in.open("Accepted.txt");
		while (getline(re, line))
		{
			in << line << endl;
		}
		in.close();
		re.close();
		in.open("TEMP.txt", ios::trunc);
		in.close();
		//Agreed and not agreed deleted
		in.open("TEMP.txt");
		re.open("GRADES.txt", ios::app);
		while (getline(re, line))
		{
			if (ee == 1)
			{
				ee = 0;
			}
			else
			{
				ee--;
				in << line << endl;
			}
		}
		in.close();
		re.close();
		in.open("GRADES.txt", ios::trunc);
		in.close();
		re.open("TEMP.txt", ios::app);
		in.open("GRADES.txt");
		while (getline(re, line))
		{
			in << line << endl;
		}
		in.close();
		re.close();
		in.open("TEMP.txt", ios::trunc);
		in.close();
		////
		in.open("TEMP.txt");
		re.open("AllStudentsSubjec.txt", ios::app);
		while (getline(re, line))
		{
			if (dd == 1)
			{
				dd = 0;
			}
			else
			{
				dd--;
				in << line << endl;
			}
		}
		in.close();
		re.close();
		in.open("AllStudentsSubjec.txt", ios::trunc);
		in.close();
		re.open("TEMP.txt", ios::app);
		in.open("AllStudentsSubjec.txt");
		while (getline(re, line))
		{
			in << line << endl;
		}
		in.close();
		re.close();
		in.open("TEMP.txt", ios::trunc);
		in.close();
		////
		in.open("TEMP.txt");
		re.open("AllStudentsApp.txt", ios::app);
		while (getline(re, line))
		{
			if (cc == 1)
			{
				cc = 0;
			}
			else
			{
				cc--;
				in << line << endl;
			}
		}
		in.close();
		re.close();
		in.open("AllStudentsApp.txt", ios::trunc);
		in.close();
		re.open("TEMP.txt", ios::app);
		in.open("AllStudentsApp.txt");
		while (getline(re, line))
		{
			in << line << endl;
		}
		in.close();
		re.close();
		in.open("TEMP.txt", ios::trunc);
		in.close();
	}
	void techdel()
	{
		int i = 0;
		string line;
		ifstream re;
		ofstream in;
		int no;
		int aa, bb, cc, dd, ee;
		in.open("TEMP.txt");
		re.open("TEACHEACCEP.txt", ios::app);
		while (getline(re, line))
		{
			i++;
			cout << line << endl;
		}
		cout << "Which Teacher You want to delete" << endl;
		cin >> no;
		while (no == 0)
		{
			cout << "Enter Corret no" << endl;
			cin >> no;
		}
		if (no > i)
		{
			no = i;
		}
		aa = bb = cc = dd = ee = no;
		re.close();
		re.open("TEACHEACCEP.txt", ios::app);
		while (getline(re, line))
		{
			if (no == 1)
			{
				no = 0;
			}
			else
			{
				no--;
				in << line << endl;
			}
		}
		in.close();
		re.close();
		in.open("TEACHEACCEP.txt", ios::trunc);
		in.close();
		re.open("TEMP.txt", ios::app);
		in.open("TEACHEACCEP.txt");
		while (getline(re, line))
		{
			in << line << endl;
		}
		in.close();
		re.close();
		in.open("TEMP.txt", ios::trunc);
		in.close();
		//App deleted;
		in.open("TEMP.txt");
		re.open("ALLTEACHERAPP.txt", ios::app);
		while (getline(re, line))
		{
			if (aa == 1)
			{
				aa = 0;
			}
			else
			{
				aa--;
				in << line << endl;
			}
		}
		in.close();
		re.close();
		in.open("ALLTEACHERAPP.txt", ios::trunc);
		in.close();
		re.open("TEMP.txt", ios::app);
		in.open("ALLTEACHERAPP.txt");
		while (getline(re, line))
		{
			in << line << endl;
		}
		in.close();
		re.close();
		in.open("TEMP.txt", ios::trunc);
		in.close();
		//result deleted
		in.open("TEMP.txt");
		re.open("ACCEPTECHAPP.txt", ios::app);
		while (getline(re, line))
		{
			if (bb == 1)
			{
				bb = 0;
			}
			else
			{
				bb--;
				in << line << endl;
			}
		}
		in.close();
		re.close();
		in.open("ACCEPTECHAPP.txt", ios::trunc);
		in.close();
		re.open("TEMP.txt", ios::app);
		in.open("ACCEPTECHAPP.txt");
		while (getline(re, line))
		{
			in << line << endl;
		}
		in.close();
		re.close();
		in.open("TEMP.txt", ios::trunc);
		in.close();
		//Agreed and not agreed deleted
	}
	int idsamcechecker(string id)
	{
		string line;
		int k = 0;
		int t = 0;
		ifstream re;
		re.open("CM.txt", ios::app);
		while (getline(re, line) && t <= 2)
		{
			t++;
			if (t == 2)
			{
				if (id == line)
				{
					return 0;
				}
				else
				{
					re.close();
					re.open("BM.txt", ios::app);
					t = 0;
					while (getline(re, line) && t <= 2)
					{
						t++;
						if (t == 2)
						{
							if (id == line)
							{
								return 0;
							}
							else
							{
								k = 1;
							}
						}
					}
				}
			}
		}
		if (k == 1)
		{
			re.close();
			re.open("AllStudentsApp.txt", ios::app);
			while (getline(re, line))
			{
				int found, i = 0;
				string test2;
				test2 = line;
				string rest[14];
				while (test2 != "\0")
				{
					found = test2.find("<<");
					for (int f = 0; f < found; f++)
					{
						rest[i] += test2[f];
					}
					test2.erase(0, found + 2);
					i++;
				}
				if (rest[10] == id)
				{
					return 0;
				}
			}
			k = 2;
		}
		if (k == 2)
		{
			re.close();
			re.open("ALLTEACHERAPP.txt", ios::app);
			while (getline(re, line))
			{
				int found, i = 0;
				string test2;
				test2 = line;
				string rest[8];
				while (test2 != "\0")
				{
					found = test2.find(" ");
					for (int f = 0; f < found; f++)
					{
						rest[i] += test2[f];
					}
					test2.erase(0, found + 1);
					i++;
				}
				if (rest[5] == id)
				{
					return 0;
				}
			}
			k = 3;
			//return 1;
		}
		if (k == 3)
		{
			re.close();
			re.open("papercheckerallapplication.txt", ios::app);
			while (getline(re, line))
			{
				int found, i = 0;
				string test2;
				test2 = line;
				string rest[5];
				while (test2 != "\0")
				{
					found = test2.find(" ");
					for (int f = 0; f < found; f++)
					{
						rest[i] += test2[f];
					}
					test2.erase(0, found + 1);
					i++;
				}
				if (rest[2] == id)
				{
					return 0;
				}
			}
			return 1;
		}
	}
	int *spacefound(string line)
	{
		int a[3];
		string test[3];
		int found, i = 0;
		string tests;
		tests = line;
		while (tests != "\0")
		{
			found = tests.find(".");
			for (int f = 0; f < found; f++)
			{
				test[i] += tests[f];
			}
			tests.erase(0, found + 1);
			i++;
		}
		cout << "Last Day and time " << endl;
		for (int d = 0; d < i; d++)
		{
			a[d] = atof(test[d].c_str());
			cout << test[d] << " ";
		}
		cout << endl;
		cout << a[0] << endl;
		cout << a[1] << endl;
		cout << a[2] << endl;
		int *p = a;
		return p;
	}
	void bm()
	{
		ofstream bmi;
		bmi.open("BM.txt", ios::app);
		cout << "Enter name" << endl;
		cin >> Name;
		bmi << Name;
		bmi << " ";
		cout << "Enter Clause" << endl;
		cin >> Clause;
		bmi << Clause;
		bmi << " ";
		cout << "Enter addreas" << endl;
		cin >> Address;
		bmi << Address;
		bmi << " ";
		cout << "Enter Designation" << endl;
		cin >> Designation;
		bmi << Designation;
		bmi << " " << endl;;
		string a;
		a = idformat();
		bmi << a << endl;
		Pass("BM");
		bmi.close();
		username();
	}
	void csce(string name)//info about chairman,secretery,teacher,paperchecker
	{
		string line;
		int check = 0;
		ofstream in;
		ifstream re;
		if (name == "CM")
		{
			in.open("CM.txt", ios::app);
		}
		else if (name == "TE")
		{
			in.open("ALLTEACHER DATA.txt", ios::app);
		}
		if (check == 0)
		{
			cout << "Enter name" << endl;
			cin >> Name;
			in << Name;
			in << " ";
			cout << "Enter Phone No" << endl;
			cin >> phone_No;
			in << phone_No;
			in << " ";
			cout << "Enter addreas" << endl;
			cin >> Address;
			in << Address;
			in << " ";
			cout << "Enter email" << endl;
			cin >> email;
			in << email;
			in << " ";
			cout << "Enter Qualification" << endl;
			cin >> Qualification;
			in << Qualification;
			in << " ";
			in << endl;
			if (name == "TE")
			{
				in.close();
				teacheremailchecker();
				Pass("TE");
				username();
			}
			else
			{
				string a;
				a = idformat();
				in << a << endl;
				Pass("CM");
				username();
			}
		}
	}
	string idformat()
	{
		int check = 0;
		string id = " ";
		ofstream in;
		cout << "Enter id" << endl;
		cin >> id;
		for (int i = 0; i < id.length(); i++)
		{
			if (id[i] == '@')
			{
				check++;
			}
			if (id[i] == '.' && id[i + 1] == 'c' && id[i + 2] == 'o' && id[i + 3] == 'm')
			{
				check++;
			}
		}
		if (check == 2)
		{
			return id;
		}
		else
		{
			cout << "Your format not good" << endl;
			Sleep(2000);
			return " ";
		}
	}
	void teacheremailchecker()
	{
		int check = 0;
		string id;
		int tidc = 1;
		string line;
		ifstream re;
		ofstream in;
		cout << "Enter id" << endl;
		cin >> id;
		for (int i = 0; i < id.length(); i++)
		{
			if (id[i] == '@')
			{
				check++;
			}
			if (id[i] == '.' && id[i + 1] == 'c' && id[i + 2] == 'o' && id[i + 3] == 'm')
			{
				check++;
			}
		}
		if (check == 2)
		{
			re.open("ALLTEACHER DATA.txt", ios::app);
			while (getline(re, line))
			{
				if (tidc % 3 == 0)
				{
					if (line == id)
					{
						cout << "This emailaddreas already exist" << endl;
						Sleep(2000);
						system("cls");
						teacheremailchecker();
					}
					else tidc++;
				}
			}
			re.close();
			in.open("ALLTEACHER DATA.txt", ios::app);
			in << id << endl;
		}
		else
		{
			cout << "YOUR ID DOESNOT HAVE CORRECT FORMAT" << endl;
			Sleep(2000);
			teacheremailchecker();
		}
	}
	void Pass(string name1)
	{
		int check = 0;
		string line;
		string pass = "", confpass = "", name;;
		char ch;
		cout << "Enter Password " << endl;
		ch = _getch();//getch only take one input but not display it
		while (ch != 13)//8 for backspace 13 for enter x
		{
			pass.push_back(ch);
			cout << '*';
			ch = _getch();//getch only take one input but not display it so ch has always one character
		}
		cout << "Enter CONFIRM Password " << endl;
		ch = _getch();//getch only take one input but not display it
		while (ch != 13)//8 for backspace 13 for enter x
		{
			confpass.push_back(ch);
			cout << '*';
			ch = _getch();//getch only take one input but not display it so ch has always one character
		}
		if (pass != confpass)
		{
			Pass(name1);
		}
		else if (pass == confpass)
		{
			ifstream re;
			ofstream in;
			if (name1 == "BM")
			{
				ifstream re;
				ofstream in;
				if (name1 == "BM")
				{
					in.open("BM.txt", ios::app);
					in << pass << endl;
					in.close();
				}
			}
			else if (name1 == "CM")
			{
				in.open("CM.txt", ios::app);
				in << pass << endl;
				in.close();
			}
			else if (name == "TE")
			{
				ofstream in;
				in.open("ALLTEACHER DATA.txt", ios::app);
				in << pass << endl;
				in.close();
			}
		}
	}
};
class STUDENTSINFO :public  CHAIRMAN
{
	string Name, Level, Institute, Address, CNIC, City, Parentsinfo, Year, Rollno, Password, e_mail, subject;
public:
	void failedstudres()
	{
		int check = 0;
		ofstream inst;
		inst.open("failedstudentsresultandapplicationno.txt");
		string lines;
		ifstream ret, rest;
		ret.open("AppAccepted.txt", ios::app);
		rest.open("studentresult.txt", ios::app);
		string tests;
		while (getline(rest, lines))
		{
			int found, i = 0;
			int file2 = 0;
			check++;
			string test[8];
			tests = lines;
			while (tests != "\0"&& file2 == 0)
			{
				found = tests.find(" ");
				for (int f = 0; f < found; f++)
				{
					test[i] += tests[f];
				}
				string as = test[i];
				for (int i = 0; i < as.length(); i++)
				{
					if (as[i] == 'F')
					{
						file2 = 1;
					}
				}
				tests.erase(0, found + 1);
				i++;
			}
			if (file2 == 1)
			{
				inst << check << " " << lines << endl;
			}
		}
		inst.close();
	}
	void failsubjpapers(int applicationlineno)//afr kisi bache ka f hai to us ka result mae tempfailed result mae save kr dun ga age pehle save nai hai
	{
		int ts = 0;
		int paqa = 0;
		int pk = 0;
		ifstream res;
		string linesw;
		res.open("tempfailedstudentresult.txt", ios::app);
		while (getline(res, linesw))
		{
			ts = 0;
			int found, i = 0;
			string test[3];
			string tests;
			tests = linesw;
			while (tests != "\0"&&ts == 0 && paqa == 0)
			{
				found = tests.find(" ");
				for (int f = 0; f < found; f++)
				{
					test[i] += tests[f];
				}
				string as = test[0];
				int asq = atoi(as.c_str());
				if (asq == applicationlineno)
				{
					paqa = 1;
				}
				else
				{
					ts = 1;
				}
				tests.erase(0, found + 1);
				i++;
			}
		}
		if (paqa == 0)
		{
			ofstream te;
			te.open("tempfailedstudentresult.txt", ios::app);
			int tc = 0;
			int y = 0;
			ifstream rea1;
			ifstream raea;
			string linw;
			rea1.open("failedstudentsresultandapplicationno.txt");
			raea.open("AppAccepted.txt");
			while (getline(rea1, linw) && y == 0)
			{
				tc = 0;
				string test[1];
				int found, i = 0;
				string tests = linw;
				while (tests != "\0"&&y == 0 && tc == 0)
				{
					found = tests.find(" ");
					for (int f = 0; f < found; f++)
					{
						test[i] += tests[f];
					}
					tests.erase(0, found + 1);
					i++;
					string conv = test[0];
					int cd = atoi(conv.c_str());
					tc = 1;
					if (cd == applicationlineno)
					{
						y = 1;
						//te << linw << endl; it is ok
						string test[10];
						int found, i = 0;
						string tests;
						tests = linw;
						while (tests != "\0")
						{
							found = tests.find(" ");
							for (int f = 0; f < found; f++)
							{
								test[i] += tests[f];
							}
							tests.erase(0, found + 1);
							string ss;
							ss = test[i];
							for (int i = 0; i < ss.length(); i++)
							{
								if (ss[i] == 'F')
								{
									pk = 1;
								}
							}
							if (pk == 0)
							{
								te << test[i] << " ";
							}
							if (pk == 1)
							{
								te << ss << " ";
							}
							pk = 0;
							i++;
						}
						te << endl;
						te.close();
					}
				}
			}
			te.close();
		}
		else
		{
			cout << "This type of papers is submitted " << endl;
		}
	}
	void Grades()
	{
		ofstream in;
		in.open("GRADES.txt", ios::trunc);
		in.close();
		in.open("GRADES.txt");
		string line;
		ifstream read;
		read.open("studentresult.txt", ios::app);
		while (getline(read, line))
		{
			string test[10];
			int found, i = 0;
			string tests;
			tests = line;
			while (tests != "\0")
			{
				found = tests.find(" ");
				for (int f = 0; f < found; f++)
				{
					test[i] += tests[f];
				}
				tests.erase(0, found + 1);
				int as = atof(test[i].c_str());
				if (as >= 90)
				{
					in << "A+ ";
				}
				else if (as >= 85)
				{
					in << "A ";
				}
				else if (as >= 80)
				{
					in << "B+ ";
				}
				else if (as >= 75)
				{
					in << "B ";
				}
				else if (as >= 70)
				{
					in << "C+ ";
				}
				else if (as >= 65)
				{
					in << "C ";
				}
				else if (as >= 60)
				{
					in << "C- ";
				}
				else if (as >= 50)
				{
					in << "D+ ";
				}
				else if (as >= 45)
				{
					in << "D- ";
				}
				else if (as >= 40)
				{
					in << "D ";
				}
				else if (as < 40)
				{
					in << "F ";
				}
				i++;
			}
			in << endl;
		}
	}
	void Acceptedapp()
	{
		int check1 = 0;
		int check = 0;
		string lines;
		string lines1;
		ifstream read;
		ofstream in;
		in.open("AppAccepted.txt", ios::app);
		in.close();
		ifstream read12;
		read.open("AppAccepted.txt", ios::app);
		while (getline(read, lines))
		{
			check++;
		}
		read.close();
		read12.open("AppNotAccepted.txt", ios::app);
		while (getline(read12, lines1))
		{
			check1++;
		}
		read12.close();
		int saa = check + check1;
		string line;
		string line2;
		string line3;
		ifstream r1;
		ifstream r2, r3;
		ofstream in1, in2, in3;
		r1.open("Accepted.txt", ios::app);
		r2.open("AllStudentsApp.txt", ios::app);
		in1.open("AppAccepted.txt", ios::app);
		in2.open("AppNotAccepted.txt", ios::app);
		in3.open("Teacherpay.txt", ios::app);
		int ba = saa;
		while (getline(r1, line))
		{
			(getline(r2, line2));
			if (saa == 0)
			{
				if (line == "Agreed")
				{
					in1 << line2 << endl;;
				}
				else if (line == "Not Agreed")
				{
					in2 << line2 << endl;;
				}
			}
			else
			{
				saa--;
			}
		}
		r1.close();
		r2.close();
		in1.close();
		in2.close();
		AllStudentsSubjects();
	}
	void rechecking()
	{
		string subj;
		string comp = { "Urdu English Math Comp Phy Che SSt Isl " };
		string bio = { "Urdu English Math Bio Phy Che SSt Isl " };
		string reg = { "Urdu English Math Science SSt Isl " };
		string comp1 = { "Urdu(0) English(1) Math(2) Comp(3) Phy(4) Che(5) SSt(6) Isl(7) " };
		string bio1 = { "Urdu(0) English(1) Math(2) Bio(3) Phy(4) Che(5) SSt(6) Isl(7) " };
		string reg1 = { "Urdu(0) English(1) Math(2) Science(3) SSt(4) Isl(5) " };
		ifstream re1;
		re1.open("AllStudentsSubjec.txt", ios::app);
		string lines;
		cout << "Enter Studnt Name " << endl;
		cin >> Name;
		cout << "Enter your year" << endl;
		cin >> Level;
		cout << "Enter your roll_no" << endl;
		cin >> Rollno;
		cout << "Enter Institute" << endl;
		cin >> Institute;
		cout << "ENter Addreas" << endl;
		cin >> Address;
		cout << " ENter Cnic" << endl;
		cin >> CNIC;
		cout << "Enter password" << endl;
		cin >> Password;
		cout << "Enter City" << endl;
		cin >> City;
		int ids = 0;
		string lm = " ";
		while (lm == " ")
		{
			lm = idformat();
		}
		cout << "Enter Parents INfo" << endl;
		cin >> Parentsinfo;
		cout << "Enter which no of Subjects You want to recheck" << endl;
		ifstream res;
		res.open("AppAccepted.txt", ios::app);
		string line;
		string test1[13];
		int found, i = 0;
		string tests;
		tests = line;
		int check = 0;
		while (getline(res, line))
		{
			int i = 0;
			getline(re1, lines);
			string test1[13];
			tests = " ";
			tests = line;
			while (tests != "\0")
			{
				found = tests.find("<<");
				for (int f = 0; f < found; f++)
				{
					test1[i] += tests[f];
				}
				tests.erase(0, found + 2);
				i++;
			}
			if (test1[0] == Name && test1[1] == Rollno && test1[3] == Institute &&test1[4] == Address&&test1[5] == CNIC && test1[6] == City&&test1[7] == Parentsinfo&&test1[8] == Level&&test1[10] == lm)
			{
				check = 1;
				if (lines == comp)
				{
					cout << comp1;
					cout << "Which subject you want to recheck " << endl;
					cout << "example 01 to recheck urdu and English" << endl;
					cin >> subj;
					rechecks(subj, line);
				}
				else if (lines == bio)
				{
					cout << bio1;
					cout << "Which subject you want to recheck " << endl;
					cout << "example 01 to recheck urdu and English" << endl;
					cin >> subj;
					rechecks(subj, line);
				}
				else if (lines == reg)
				{
					cout << reg1;
					cout << "Which subject you want to recheck " << endl;
					cout << "example 01 to recheck urdu and English" << endl;
					cin >> subj;
					rechecks(subj, line);
				}
			}
		}
	}
	void applicationforum()
	{
		int a = 0;
		string line;
		ifstream f4;
		ofstream f5;

		f4.open("CM.txt", ios::app);
		if (getline(f4, line))
		{
			a = 1;
		}
		if (a == 1)//yeni dono files mae data hai
		{
			f4.close();
			STUDENTSINFO i;
			i.sets();
		}
		else
		{
			cout << "This Program is under Construction" << endl;
			cout << "Visit after some time" << endl;
			Sleep(2000);
			Main();
		}
	}
	void rechecks(string recheck_subj, string appliation)
	{
		srand(time(NULL));
		int iii = 0;
		int a = recheck_subj.length();
		int *arr = new int[a];
		string lines;
		ifstream res1;
		res1.open("studentresult.txt", ios::app);
		string linet;
		ofstream ins1;
		ins1.open("tempresult.txt", ios::app);
		ifstream retw;
		retw.open("AppAccepted.txt", ios::app);
		while (getline(retw, linet))//application agle
		{
			if (linet == appliation)//agr application a gai to us application ke samne jo result ho ga use space ki bana pe tor do ga
			{
				getline(res1, lines);
				string test[8];
				int found, i = 0;
				string tests;
				tests = lines;//result wali line
				while (tests != "\0")
				{
					found = tests.find(" ");
					for (int f = 0; f < found; f++)
					{
						test[i] += tests[f];
					}
					tests.erase(0, found + 1);
					i++;
				}
				for (int k = 0; k < recheck_subj.length(); k++)//recheck_subj ye recking ke lie subject hai
				{
					string ss;
					ss = recheck_subj[k];
					arr[k] = atoi(ss.c_str());
					system("cls");
					cout << arr[k];
				}
				for (int k = 0; k < 8; k++)
				{
					if (k == arr[iii])
					{
						int aaa = 100;
						int b = rand() % 50;
						int s = aaa - b;
						if (s < 33)
						{
							ins1 << s << "F ";
						}
						else
						{
							ins1 << s << " ";
						}
						iii++;
					}
					else//yeni arr[k]mae koi value nai hai
					{
						ins1 << test[k] << " ";
					}
					if (k == 7)
					{
						ins1 << endl;
					}
				}
			}
			else
			{
				getline(res1, lines);
				ins1 << lines << endl;//nai to resultnwaise ka waise hi tempresult wali file mae

			}
		}
		string line;
		ins1.close();
		ins1.open("studentresult.txt", ios::trunc);
		ins1.close();
		ins1.open("studentresult.txt");
		ifstream res;
		res.open("tempresult.txt", ios::app);
		while (getline(res, line))
		{
			ins1 << line << endl;
		}
		ins1.close();
		res.close();
		ins1.open("tempresult.txt", ios::trunc);
		ins1.close();
	}
	void sets()
	{
		int dd = 8000;//student fees
		int mo;
		int ha;
		int *p, *q;;
		int dat = 0;
		int t = 0;
		time_t now;
		struct tm nowLocal;
		now = time(NULL);
		nowLocal = *localtime(&now);//get time from OS
		cout << "Date is:" << nowLocal.tm_mday << ":" << nowLocal.tm_mon + 1 << ":" << nowLocal.tm_year + 1900 << endl;
		cout << "TIme is:" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << endl;
		cin.get();
		string line;
		int l = 0;
		ofstream writes;
		ifstream read;
		read.open("CM.txt", ios::app);
		while (getline(read, line))
		{
			l++;
			if (l == 4)//matlab line mae kuch hai yeni date DATE
			{
				int s = 0, v = 0, r = 0;
				string a;
				a = line;
				CHAIRMAN da;
				p = da.spacefound(a);
				if (p[2] >= (nowLocal.tm_year + 1900))
				{
					if (p[1] >= (nowLocal.tm_mon + 1))
					{
						if (p[0] >= (nowLocal.tm_mday))
						{
							t = 1;//yeni date hai
						}
						else
						{
							if (p[1] > (nowLocal.tm_mon + 1))
							{
								t = 1;//yeni date hai
							}
						}
					}
					ha = p[1];
					mo = p[0];
				}
			}
			if (t == 1)
			{
				if (l == 5)//matlab line mae kuch hai yeni date TIME
				{
					int s = 0, v = 0, r = 0;
					string b;
					b = line;
					q = spacefound(b);
					if (q[0] >= nowLocal.tm_hour)
					{
						if (q[1] >= (nowLocal.tm_min + 1))//minute chote
						{
							dat = 1;//yeni time hai
						}
						else
						{
							if (mo == (nowLocal.tm_mday) && ((ha == (nowLocal.tm_mon + 1))) && (q[0] <= nowLocal.tm_hour))
							{
								t = 0;
							}
							else
							{
								t = 1;
								dat = 1;
							}
						}
					}
					if (ha > (nowLocal.tm_mon + 1))
					{
						t = 1; dat = 1;
					}
				}
			}
		}
		if (t == 0 & dat == 0)
		{
			int s = 0;
			string line;
			ifstream re;
			ofstream in;
			re.open("CM.txt", ios::app);
			in.open("CMT.txt");
			while (getline(re, line))
			{
				if (s < 3)
				{
					in << line << endl;
				}
				else
				{
					s++;
				}
			}
			in.close();
			re.close();
			in.open("CM.txt");
			re.open("CMT.txt", ios::app);
			while (getline(re, line))
			{
				in << line << endl;
			}
			in.close();
			re.close();
		}
		if (t == 1 && dat == 1)
		{
			if (l == 5)
			{
				int sfml = 0;
				int ids = 0;
				int rolls = 0;
				writes.open("rollnohelper.txt", ios::app);
				int store = 0;
				cout << "Enter Studnt Name " << endl;
				cin >> Name;
				while (sfml == 0)
				{
					try
					{
						for (int her = 0; her < Name.length(); her++)
						{
							if (Name[her] == '0' || Name[her] == '1' || Name[her] == '2' || Name[her] == '3' || Name[her] == '4' || Name[her] == '5' ||
								Name[her] == '6' || Name[her] == '7' || Name[her] == '8' || Name[her] == '9')
							{
								throw Name;
							}
						}
						sfml = 1;

					}
					catch (string sad)
					{
						cin >> Name;
					}
				}
				cout << "ENter Level " << endl;
				int aaa = 0;
				cin >> aaa;
				if (aaa > 10)
				{
					cout << "Ylevel not be greate 10" << endl;
					Sleep(2000);
					username();
				}
				else if (aaa > 8)
				{
					cout << "Enter yout subjects" << endl;
					string as;
					cin >> as;
					if (as == "Comp")
					{
						subject = "c";
					}
					else if (as == "Bio")
					{
						subject = "b";
					}
					else
					{
						cout << "Your application is harab " << endl;
						Sleep(2000);
						exit(0);
					}
				}
				else if (aaa <= 8)
				{
					subject = "r";
					dd = 6000;
				}
				cout << "Enter Institute" << endl;
				cin >> Institute;
				cout << "ENter Addreas" << endl;
				cin >> Address;
				cout << " ENter Cnic" << endl;
				cin >> CNIC;
				writes << Name << "<<";
				cout << "Enter password" << endl;
				cin >> Password;
				writes << Password;
				writes.close();
				string lm = " ";
				while (lm == " ")
				{
					lm = idformat();
				}
				while (ids == 0)
				{
					ids = idsamcechecker(lm);
					if (ids == 0)
					{
						lm = idformat();
					}
				}
				string lined;
				ifstream re1;
				re1.open("rollnohelper.txt", ios::app);
				while (getline(re1, lined))
				{
					rolls++;
				}
				re1.close();
				string Result;          // string which will contain the result
				ostringstream convert;   // stream used for the conversion
				convert << rolls;      // insert the textual representation of 'Number' in the characters in the stream
				Result = convert.str();
				Rollno = Result;
				writes.open("rollnohelper.txt", ios::app);
				writes << Rollno << endl;
				writes.close();
				read.close();
				cout << "ENter City" << endl;
				cin >> City;
				cout << "ENter Parents Information" << endl;
				cin >> Parentsinfo;
				cout << "Enter Year " << endl;
				cin >> Year;
				cout << "your fees is  " << dd << endl;
				cout << "You want to submit it(((1))) or not" << endl;
				int sub;
				cin >> sub;
				if (sub == 1)
				{
					string newfilename;
					string newfilename1;
					newfilename = Institute + Level + "F" + Year + ".txt";
					newfilename1 = Institute + Level + "S" + Year + ".txt";
					ifstream reads;
					string line;
					reads.open(newfilename1.c_str(), ios::app);
					while (getline(reads, line))
					{
						if (line == newfilename1)
						{
							cout << "You have got an F  So be punctual" << endl;
							store = 1;//yeni in fail file student is registered
						}
					}
					reads.close();
					if (store == 0)//yeni in fail file mae student nai hai
					{
						reads.close();
						ofstream write;
						write.open(newfilename.c_str(), ios::app);//to fresh file open kar ke us mae sari aplication store karwa di
						write << Name << "<<" << Rollno << "<<" << aaa << "<<" << Institute << "<<" << Address << "<<" << CNIC << "<<" << City << "<<" << Parentsinfo << "<<" << Year << "<<" << subject << "<<" << lm << "<<" << endl;
						write.close();
						writes.open("AllStudentsApp.txt", ios::app);
						writes << Name << "<<" << Rollno << "<<" << aaa << "<<" << Institute << "<<" << Address << "<<" << CNIC << "<<" << City << "<<" << Parentsinfo << "<<" << Year << "<<" << subject << "<<" << lm << "<<" << Password << "<<" << dd << "<<" << endl;
						writes.close();
					}
					else//yeni time nai hai CM ki file mae;
					{
						cout << "This Program is under construction" << endl;
						Sleep(2000);
						username();
					}

				}
				else
				{
					Main();
				}
			}
		}
	}
	void studentresult(int n)
	{
		int check = 0;
		string no;
		ifstream re1;
		re1.open("studentresult.txt", ios::app);
		string no1;
		string lines;
		string line;
		int sea;
		if (n == 1)
		{
			cout << "You want to get resul by your roll no(((111))) or by e-mail(((000)))" << endl;
			cin >> sea;
			if (sea == 1)
			{
				cout << "ENter our roll no" << endl;
				cin >> no;
			}
			if (sea == 0)
			{
				cout << "ENter our e-mail " << endl;
				cin >> no1;
			}
			ifstream re;
			re.open("AppAccepted.txt", ios::app);
			while (getline(re, line) && check == 0)
			{
				if (getline(re1, lines))
				{

				}
				int found, i = 0;
				string test2;
				test2 = line;
				string rest[13];
				while (test2 != "\0")
				{
					found = test2.find("<<");
					for (int f = 0; f < found; f++)
					{
						rest[i] += test2[f];
					}
					test2.erase(0, found + 2);
					i++;
				}
				if (sea == 1)
				{
					if (rest[2] == no)
					{
						check = 1;
						cout << "Your result is " << lines << endl;
					}
				}
				if (sea == 0)
				{
					if (rest[10] == no1)
					{
						check = 1;
						cout << "Your result is " << lines << endl;
					}
				}
			}
		}
	}
	void studgrades(int applicationlineno)
	{
		int i = 0;
		string line;
		ifstream re;
		re.open("GRADES.txt", ios::app);
		while (getline(re, line))
		{
			i++;
			if (i == applicationlineno)
			{
				cout << line << endl;
			}
		}
	}
	void AllStudentsSubjects()
	{
		int check = 0;
		string lines;
		ifstream res;
		res.open("AllStudentsSubjec.txt", ios::app);
		while (getline(res, lines))
		{
			check++;
		}
		res.close();
		string comp = { "Urdu English Math Comp Phy Che SSt Isl " };
		string bio = { "Urdu English Math Bio Phy Che SSt Isl " };
		string reg = { "Urdu English Math Science SSt Isl " };
		string line;
		ifstream re;
		ofstream in;
		in.open("AllStudentsSubjec.txt", ios::app);
		re.open("AppAccepted.txt", ios::app);
		while (getline(re, line))
		{
			if (check == 0)
			{
				int found, i = 0;
				string test2;
				test2 = line;
				string rest[13];
				while (test2 != "\0")
				{
					found = test2.find("<<");
					for (int f = 0; f < found; f++)
					{
						rest[i] += test2[f];
					}
					test2.erase(0, found + 2);
					i++;
				}
				if (rest[9] == "r")
				{
					in << reg << endl;
				}
				else if (rest[9] == "c")
				{
					in << comp << endl;
				}
				else if (rest[9] == "b")
				{
					in << bio << endl;
				}
			}
			else
			{
				check--;
			}
		}
	}
	void Studeacc(int applicationlineno)
	{
		int tc = 0;
		int y = 0;
		int n;
		string linw;
		int a11 = 0, b11 = 0;
		string line11, line12;
		ifstream raea, raea1;
		ifstream insa;
		insa.open("failedstudentsresultandapplicationno.txt");
		raea.open("AppAccepted.txt");
		while (getline(insa, linw) && y == 0)
		{
			tc = 0;
			string test[1];
			int found, i = 0;
			string tests = linw;
			while (tests != "\0"&&y == 0 && tc == 0)
			{
				found = tests.find(" ");
				for (int f = 0; f < found; f++)
				{
					test[i] += tests[f];
				}
				tests.erase(0, found + 1);
				i++;
				string conv = test[0];
				int cd = atoi(conv.c_str());
				tc = 1;
				if (cd == applicationlineno)
				{
					y = 1;
				}
			}
		}
		raea1.open("studentresult.txt");
		while (getline(raea, line11))
		{
			a11++;
		}
		while (getline(raea1, line12))
		{
			b11++;
		}
		if (a11 == b11)
		{
			cout << "1 for gertresult 2 for rechecking and 4 to see grades" << endl;
			if (y == 1)
			{
				cout << " 3 about supply papaers" << endl;
			}

			cin >> n;
			if (n == 1)
			{
				STUDENTSINFO a;
				a.studentresult(n);
			}
			else if (n == 2)
			{
				STUDENTSINFO a;
				a.rechecking();
			}
			else if (n == 3)
			{
				ofstream in;
				in.open("Papersinfo.txt", ios::app);
				int re;
				cout << "Kuch karte hain" << endl;
				cout << "You want to giva all papers((1)) or only supply((0)) " << endl;
				cin >> re;
				if (re == 1)
				{
					in << "A" << endl;
				}
				else if (re == 0)
				{
					in << "S" << endl;
				}
				failsubjpapers(applicationlineno);
			}
			else if (n == 4)
			{
				Grades();
				studgrades(applicationlineno);
			}
			else
			{
			
				Studeacc(applicationlineno);
			}
		}
		else
		{
			cout << "First given the result of all students" << endl;
		}
	}
	
	void saveresult()
	{
		system("cls");
		int kb = 0;
		string re;
		ifstream res, re1, re2, rens, renp;
		string l, l1, l2;
		ofstream in, inss;
		in.open("changingresult.txt", ios::trunc);
		in.close();
		rens.open("changingresult.txt", ios::app);
		res.open("changinfailedstudentresult.txt", ios::app);

		while (getline(res, l))
		{
			re1.close();
			re1.open("studentresult.txt", ios::app);
			in.close();
			re = "";
			in.open("changingresult.txt");
			string test[13];
			int found, i = 0;
			string tests;
			tests = l;
			while (tests != "\0")
			{
				found = tests.find(" ");
				for (int f = 0; f < found; f++)
				{
					test[i] += tests[f];
				}
				tests.erase(0, found + 1);
				i++;
			}
			for (int k = 0; k < i; k++)
			{
				if (k == 0)
				{
					string a = test[0];
					kb = atof(a.c_str());
				}
				else
				{
					re += test[k] + " ";
				}
			}
			while (getline(re1, l1))//student result mae 4 lines hai n
			{
				if (kb == 1)
				{
					in << re << endl;
					kb = 0;
					cout << re << endl << endl << endl;;
				}
				else
				{
					in << l1 << endl;//changing result mae sac=ve krwa lia
					kb--;
					cout << l1 << endl << endl << endl;
				}
			}
			rens.close();
			rens.open("changingresult.txt", ios::app);
			in.close();
			in.open("studentresult.txt", ios::trunc);//student and changing result me passes
			in.close();
			in.open("studentresult.txt");
			in.close();
			(getline(res, l));//failed students mae se line le ga
			if (l != "")
			{
				string testsa[13];
				i = 0;
				tests = "";
				tests = l;
				inss.open("studentresult.txt", ios::app);
				while (tests != "\0")
				{
					found = tests.find(" ");
					for (int f = 0; f < found; f++)
					{
						testsa[i] += tests[f];
					}
					tests.erase(0, found + 1);
					i++;
				}
				re = "";
				for (int k = 0; k < i; k++)
				{
					if (k == 0)
					{
						string a;
						a = testsa[0];
						kb = atof(a.c_str());
					}
					else
					{
						re += testsa[k] + " ";
					}
				}
				while (getline(rens, l2))//changin result mae se line le ga
				{
					if (kb == 1)
					{
						inss << re << endl;//all result mae save0
						kb = 0;
					}
					else
					{
						inss << l2 << endl;//student result mae save
						kb--;
					}
				}
				inss.close();
				in.open("changingresult.txt");
				in.close();
				system("cls");
			}
		}
		ofstream ina, ina1, ina2;
		ina.open("tempfailedstudentresult.txt", ios::trunc);
		ina.close();
		ifstream rw;
		string ls;
		ina.open("changinfailedstudentresult.txt", ios::trunc);
		ina.close();;
		int tk = 0;;
		rw.open("studentresult.txt", ios::app);
		while (getline(rw, ls))
		{
			tk++;
		}
		if (tk == 0)
		{
			ofstream insaa;
			insaa.open("studentresult.txt", ios::app);
			rw.close();
			rw.open("changingresult.txt", ios::app);
			while (getline(rw, ls))
			{
				insaa << ls << endl;
			}
		}
		in.open("changingresult.txt", ios::trunc);
		in.close();
		ina.open("changingresult.txt", ios::trunc);
		ina.close();
		ina.open("Papersinfo.txt", ios::trunc);
		ina.close();
		failedstudres();
	}

};
class Employee :public CHAIRMAN
{
public:
	void Paperscheck()
	{
		int km = 0;
		ifstream red;
		red.open("tempfailedstudentresult.txt", ios::app);
		string line;
		while (getline(red, line))
		{
			km++;
		}
		int p = 0;
		string lm; ifstream re;
		ifstream rae;
		if (km == 0)
		{
			cout << "If You Want to check new students papers press 1 " << endl;
			cin >> p;
			while (p != 1)
			{
				cout << "Your input is not correct " << endl;
				cin >> p;
			}
		}
		else if (km >= 1)
		{
			cout << "If You Want to check supplymentry papaers press 2" << endl;
			cin >> p;
			while (p != 2)
			{
				cout << "Your input is not correct " << endl;
				cin >> p;
			}
		}
		ofstream in;
		re.open("tempfailedstudentresult.txt", ios::app);
		rae.open("Papersinfo.txt", ios::app);
		while (getline(re, line))
		{
			(getline(rae, lm) && p == 2);
			if (p == 2 && lm == "S")
			{
				int tak = 0;
				int paq = 0;
				in.open("changinfailedstudentresult.txt", ios::app);
				string tests;
				string test[12];
				int found, i = 0;
				tests = line;
				while (tests != "\0"&&tak == 0)
				{
					found = tests.find(" ");
					if (found >= 0)//bcz i dont kono how many subjects he read so i take maximum array 13 when at last is subject 5 found is -1
					{
						for (int f = 0; f < found; f++)
						{
							test[i] += tests[f];
						}
						tests.erase(0, found + 1);
						string as;
						as = test[i];
						for (int k = 0; k < as.length(); k++)
						{
							if (as[k] == 'F')
							{
								paq = 1;
							}
						}
						if (paq == 1)
						{
							int ss = rand() % 20 + 50;
							if (ss < 33)
							{
								in << ss << "F ";
							}
							else
							{
								in << ss << " ";
							}
						}
						else
						{
							in << test[i] << " ";
						}
						paq = 0;
						i++;
					}
					else
					{
						tak = 1;
					}
				}
				in << endl;
				//yeni yahan tak mae ne jitne bachon ne failed subjects dobara dne ko kaha tha wo teacher ne check ker liye ab in sare result ko studentresult me application 
				//form kw samne save kerna haij
				//	saveresult();
			}

			else if (p == 2 && lm == "A")
			{
				int tak = 0;
				int paq = 0;
				ofstream ink;
				ink.open("changinfailedstudentresult.txt", ios::app);
				string tests;
				string test[12];
				int found, i = 0;
				tests = line;
				while (tests != "\0"&&tak == 0)
				{
					found = tests.find(" ");
					if (found >= 0)//bcz i dont kono how many subjects he read so i take maximum array 13 when at last is subject 5 found is -1
					{
						for (int f = 0; f < found; f++)
						{
							test[i] += tests[f];
						}
						tests.erase(0, found + 1);
						i++;
					}
				}
				for (int kk = 0; kk < i; kk++)
				{
					if (kk != 0)
					{
						int sa = rand() % 25 + 50;
						if (sa < 33)
						{
							ink << sa << "F ";
						}
						else
						{
							ink << sa << " ";
						}
					}
					else if (kk == 0)
					{
						ink << test[kk] << " ";
					}
				}
				ink << endl;
			}
			//saveresult();
		}
		STUDENTSINFO rqd;
		rqd.saveresult();
		if (p == 1)
		{
			srand(time(NULL));
			ofstream in;
			in.open("datesheet.txt", ios::trunc);
			in.close();
			int p = 0;
			int size = 0;
			int a = 0;
			ifstream re;
			string line;
			re.open("AppAccepted.txt", ios::app);
			while (getline(re, line))
			{
				a++;
			}
			re.close();
			re.open("studentresult.txt", ios::app);
			while (getline(re, line))
			{
				p++;
			}
			re.close();
			if (p == a)
			{
				cout << "Sorry there is no more students" << endl;
			}
			else
			{
				ofstream in;
				in.open("studentresult.txt", ios::app);
				re.open("AppAccepted.txt", ios::app);
				while (getline(re, line))
				{
					if (p == 0)
					{
						cout << line;
						long long int ts = 0;;
						string t;
						string test[13];
						int found = 0, i = 0;
						string tests;
						tests = line;
						while (tests != "\0")
						{
							found = tests.find("<<");
							for (int f = 0; f < found; f++)
							{
								test[i] += tests[f];
							}
							tests.erase(0, found + 2);
							i++;
						}
						t = test[9];
						if (t == "r")
						{
							size = 6;
						}
						else
						{
							size = 8;
						}
						int *p = new int[size];
						for (int i = 0; i < size; i++)
						{
							int aaa = 100;
							int b = rand() % 90;
							p[i] = aaa - b;
							if (p[i] < 33)
							{
								in << p[i] << "F ";
							}
							else
							{
								in << p[i] << " ";
							}
							if (i == size - 1)
							{
								in << endl;
							}
						}
					}
					else
					{
						p--;
					}
				}
			}
			STUDENTSINFO wqer;
			wqer.failedstudres();
		}
	}
};
class Teacher :public Employee
{
public:
	void techapp()
	{
		int tc = 0;
		int pay = rand() % 20000 + 10000;
		int ids = 0;
		int te;
		cout << "Enter NAme" << endl;
		cin >> Name;
		cout << "Enter Addreas" << endl;
		cin >> Address;
		cout << "CNIC" << endl;
		cin >> cnic;
		cout << "Qualification" << endl;
		cin >> Qualification;
		cout << "Your pay is" << endl;
		cout << pay;
		cout << "If you agreed with your then press 1 else you will not eligible for this post" << endl;
		cin >> tc;
		if (tc == 1)
		{
			cout << "Enter teaching experience" << endl;
			cin >> te;

			cout << "ENter E-mail" << endl;
			string lm = " ";
			while (lm == " ")
			{
				CHAIRMAN ds;
				lm = ds.idformat();
			}
			while (ids == 0)
			{
				ids = idsamcechecker(lm);
				if (ids == 0)
				{
					lm = idformat();
				}
			}
			cout << "Password" << endl;
			cin >> pass;
			ofstream in;
			in.open("ALLTEACHERAPP.txt", ios::app);
			in << Name << " " << Address << " " << cnic << " " << Qualification << " " << te << " " << lm << " " << pass << " " << pay << " " << endl;
			in.close();
		}
		else
		{
			Main();
		}
	}
	void techaccapp()
	{
		int i = 0;
		string line;
		int check = 0;
		ifstream re;
		ofstream in;
		re.open("ACCEPTECHAPP.txt", ios::app);
		while (getline(re, line))
		{
			check++;
		}
		int a = check;
		re.close();
		re.open("ALLTEACHERAPP.txt", ios::app);
		while (getline(re, line))
		{
			if (check == 0)
			{
				cout << line << endl;
				i++;
			}
			else
			{
				check--;
			}
		}
		int t = 0;
		re.close();
		cout << "How many teacher you want to admit " << endl;
		cin >> t;
		while (i != 0)
		{
			cout << "You want to accept((((111)))) the teacher application or not((((0)))) " << endl;
			int h = 0;
			cin >> h;
			if (h == 1)
			{
				in.close();
				in.open("ACCEPTECHAPP.txt", ios::app);
				in << "ACCEPTED" << endl;
			}
			else if (h == 0)
			{
				in.close();
				in.open("ACCEPTECHAPP.txt", ios::app);
				in << "NOT ACCEPTED" << endl;
			}
			if (t > i)
			{
				t = i;
			}
			t--;
			i = t;
		}
		in.close();
		//ab agr acceted hai toh teacher ki line accepteacher mae a jaye gi
		int saa = 0;;
		int xx = 0;
		string line2;
		ifstream r1;
		ifstream r2, r3;
		ofstream in1;
		ofstream in2, in3;
		r1.open("TEACHEACCEP.txt", ios::app);
		while (getline(r1, line))
		{
			xx++;
		}
		r1.close();
		r1.open("TEACHER NOT ACCEPT.txt", ios::app);
		while (getline(r1, line))
		{
			xx++;
		}
		r1.close();
		r1.open("ACCEPTECHAPP.txt", ios::app);
		r2.open("ALLTEACHERAPP.txt", ios::app);
		in1.open("TEACHEACCEP.txt", ios::app);
		in2.open("TEACHER NOT ACCEPT.txt", ios::app);
		int ba = saa;
		while (getline(r1, line))
		{
			if (getline(r2, line2))
			{
				if (xx == 0)
				{
					if (line == "ACCEPTED")
					{
						in1 << line2 << endl;;
					}
					else if (line == "NOT ACCEPTED")
					{
						in2 << line2 << endl;;
					}
				}
				else
				{
					xx--;
				}
			}
		}
		r1.close();
		r2.close();
		r3.close();
		in1.close();
		in2.close();
		in3.close();
	}
	void teacheacc()
	{
		string rest[3];
		int asas[3];
		int n = 0;
		cout << "1 for paperchecking 2 for E-mail " << endl;
		cin >> n;
		if (n == 1)
		{
			int ss = 0;
			string line;
			ifstream re;
			re.open("datesheet.txt", ios::app);
			while (getline(re, line))
			{
				ss++;
			}
			if (ss >= 1)
			{
				while (getline(re, line))
				{
					int found, i = 0;
					string test2;
					test2 = line;
					while (test2 != "\0")
					{
						found = test2.find(" ");
						for (int f = 0; f < found; f++)
						{
							rest[i] += test2[f];
						}
						test2.erase(0, found + 2);
						i++;
					}
				}
				for (int i = 0; i < 3; i++)
				{
					string sa;
					sa = rest[i];
					asas[i] += atof(sa.c_str());
				}
				time_t now;
				struct tm nowLocal;
				now = time(NULL);
				nowLocal = *localtime(&now);//get time from OS
				cout << "Date is:" << nowLocal.tm_mday << ":" << nowLocal.tm_mon + 1 << ":" << nowLocal.tm_year + 1900 << endl;
				cout << "TIme is:" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << endl;
				cin.get();
				if (asas[0] <= nowLocal.tm_year + 1900 && asas[1] <= nowLocal.tm_mon + 1 && asas[2] <= nowLocal.tm_mday)//jab datsheet ka tim hata ho ga 
				{
					Employee a;
					a.Paperscheck();
				}
				else
				{
					cout << "NO time for checking paper" << endl;
				}
			}
			else
			{
				cout << "Give Date Sheet First" << endl;
				Sleep(2000);
				system("cls");
			}
		
		}

	}
};
class PaperChecker :public Employee
{
public:
	void paperschecker()
	{
		int a;
		int save;
		cout << "Enter name " << endl;
		cin >> Name;
		cout << "Enter Qualificaation" << endl;
		cin >> Qualification;
		cout << "You papers Checking cost is rupees 1000 " << endl;
		cout << "If you bwant to accept it press 1 else 0" << endl;
		cin >> a;
		if (a == 1)
		{
		//	budget();
			string line;
			ifstream read;
			read.open("BUDGET.txt", ios::app);
			while (getline(read, line))
			{
				save = atof(line.c_str());
				save = save - 100;
			}
			int ids = 0;
			cout << "ENter E-mail" << endl;
			string lm = " ";
			while (lm == " ")
			{
				lm = idformat();
			}
			while (ids == 0)
			{
				ids = idsamcechecker(lm);
				if (ids == 0)
				{
					lm = idformat();
				}
			}
			cout << "Password" << endl;
			cin >> pass;
			ofstream in;
			in.open("papercheckerallapplication.txt",ios::app);
			in << Name << " " << Qualification << " " << lm << " " << pass << " " << endl;
			in.close();
		}
		else
		{
			username();
		}

	}
};
int main()
{
	Main();
	string line;
	int i = 0, j = 0;
//	Main();
	ifstream re;
	re.open("AppAccepted.txt", ios::app);
	while (getline(re, line))
	{
		i++;
	}
	re.close();
	re.open("studentresult.txt", ios::app);
	while (getline(re, line))
	{
		j++;
	}
	if (i == j)
	{
		ofstream in;
		in.open("papercheckerallapplication.txt",ios::trunc);
		in.close(); 
		in.open("papercheckeragreedornot.txt", ios::trunc);
		in.close();
		in.open("papercheckeraccepted.txt", ios::trunc);
		in.close();
		in.open("papercheckernotaccepted.txt", ios::trunc);
		in.close();
	}
	system("pause");
}
void Main()
{
	int aa = 0;
	ifstream f1;
	ofstream f2;
	int a = 0;
	string line;
	cout << "IF YOU WANT TO LOGIN OR SIGNIN HIT 1 2 for Application forum and 3 for apply as a teacher 4 to apply AS paperchecker " << endl;
	cin >> a;
	if (a == 1)
	{
		username();
	}
	else if (a ==2)
	{
		STUDENTSINFO dsf;
		dsf.applicationforum();
	}
	else if (a == 3)
	{
		Teacher a;
		a.techapp();
	}
	else if (a == 4)
	{
		int is = 0, sj = 0;
		//	Main();
		ifstream re;
		re.open("AppAccepted.txt", ios::app);
		while (getline(re, line))
		{
			is++;
		}
		re.close();
		re.open("studentresult.txt", ios::app);
		while (getline(re, line))
		{
			sj++;
		}
		if (is != sj)
		{
			PaperChecker a;
			a.paperschecker();
		}
		else
		{
			cout << "no more syudents availabe" << endl;
			Main();
		}
	}
	else
	{
		cout << "Your input is not correct" << endl;
		Sleep(2000);
		Main();
	}
}
void username()
{
	int tak = 0;
	ofstream in2;
	in2.open("CMT.txt", std::ios::out | std::ios::trunc);
	in2.close();
	int time1 = 0;
	int pt = 0;
	int k = 0;
	int file = 0;
	string pas;
	int check = 0;
	string g;
	string line;
	string pk;
	string id;
	int a = 0;
	cout << "1 for Login And 2 For Signin" << endl;
	cin >> a;
	if (a == 1)
	{
		int et = 0;
		int t = 0;
		int s = 0;
		cout << "Enter id" << endl;
		cin >> id;
		cout << "Enter your password" << endl;
		cin >> pas;
		ifstream re;
		ofstream in;
		re.open("CM.txt", ios::app);
		while (getline(re, line))
		{
			if (check == 1)
			{
				g = line;
			}
			if (check == 2)
			{
				pk = line;;
			}
			check++;
		}
		if (id == g&&pk == pas)
		{
			cout << "CM account accesed" << endl;
			cout << "If you want to see all aplications froms students press 1 and 2 for update last submission date of application" << endl;
			cout << "3 to see teacher forms and 4 to see budget" << endl;
			cout << "5 to set Date sheet 6 to delete student and 7 to delete teacher press 8 to see Paperchecker application " << endl;
			cin >> s;
			re.close();
			in.close();
			file = 1;
			if (s == 1)
			{
				CHAIRMAN as;
				as.funcal();
				STUDENTSINFO fd;
				fd.Acceptedapp();
			}
			if (s == 2)
			{
				int pq = 0;
				ifstream re1;
				ofstream in1;
				re.close();
				in.close();
				re1.open("CM.txt", ios::app);
				in1.open("CMT.txt", ios::app);
				while (getline(re1, line) && pq < 3)
				{
					if (pq < 3)
					{
						in1 << line << endl;
					}
					pq++;
				}
				in1.close();
				re1.close();
				ifstream re2;
				ofstream in2;
				in2.open("CM.txt", std::ios::out | std::ios::trunc);
				in2.close();
				re2.open("CMT.txt", ios::app);
				in2.open("CM.txt", ios::app);
				while (getline(re2, line))
				{
					in2 << line << endl;
				}
				in1.close();
				re1.close();
				time_t now;
				struct tm nowLocal;
				now = time(NULL);
				nowLocal = *localtime(&now);//get time from OS
				cout << "Date is:" << nowLocal.tm_mday << ":" << nowLocal.tm_mon + 1 << ":" << nowLocal.tm_year + 1900 << endl;
				cout << "TIme is:" << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << endl;
				cin.get();
				cout << "Enter date ";
				int d;
				cin >> d;
				while (d > 31)
				{
					cin >> d;
				}
				if (d<31)
				{
					cout << "Enter Month";
					int m;
					cin >> m;
					while (m > 12 || m > 2 + nowLocal.tm_mon + 1)
					{
						cout << "MAXIMUM NO OF MONTH FOR ADMISSION IS 2 " << endl;
						Sleep(2000);
						cin >> m;
					}
					if (m < 12)
					{
						cout << "Year" << endl;
						int y;
						cin >> y;
						while (y < 2017 && y>2017)
						{
							cin >> y;
						}
						if (y = 2017)
						{
							re.close();
							in.open("CM.txt", ios::app);
							in << d << "." << m << "." << y << "." << endl;;
							pt = 1;//day month year correct 
							in.close();
							re.close();
							if (d == nowLocal.tm_mday&&m == nowLocal.tm_mon + 1 && y == nowLocal.tm_year + 1900)
							{
								time1 = 1;//yeni time same hai
							}
						}
						if (pt = 1)
						{
							CHAIRMAN as;
							as.times(time1);
						}
					}
				}
			}
			if (s == 3)
			{
				Teacher as;
				as.techaccapp();
			}
			if (s == 4)
			{
				CHAIRMAN as;
				as.budget();
			}
			if (s == 5)
			{
				CHAIRMAN as;
				as.datesheet();
			}
			if (s == 6)
			{
				CHAIRMAN as;
				as.studdel();
			//	GRADES1 ds;
			//	ds.Grades();
			}
			if (s == 7)
			{
				Teacher ew;
				ew.techdel();
			}

			if (s == 8)
			{
				int i = 0, j = 0,k = 0;;
				string line;
				ifstream read, read1;
				read.open("papercheckeraccepted.txt", ios::app);
				while (getline(read, line))
				{
					i++;
				}
				read.close();
				read.open("papercheckernotaccepted.txt", ios::app);
				while (getline(read, line))
				{
					i++;
				}
				j = i;
				read.close();
				read.open("papercheckerallapplication.txt", ios::app);
				while (getline(read, line))
				{
					if (i == 0)
					{
						cout << line << endl;
						k++;
					}
					else
					{
						i--;
					}
				}
				
				ofstream input;
				input.open("papercheckeragreedornot.txt", ios::app);
				read.close();
				int  no;
				cout << "Enter how many applications you waant to check " << endl;
				cin >> no;
				if (no > k)
				{
					no = k;
				}
				for (int i = 0; i < no; i++)
				{
					int p;
					cout << "You want to accept (1) " << i << " Application neglect (0) " << endl;
					cin >> p;
					if (p == 1)
					{
						input << "Agreed" << endl;
					}
					else
					{
						input << "Not Agreed" << endl;
					}
				}
				ofstream in1, in2;
				input.close();
				in1.open("papercheckeraccepted.txt", ios:: app);
				string line1;
				in2.open("papercheckernotaccepted.txt", ios::app);
				read.open("papercheckeragreedornot.txt", ios::app);
				read1.open("papercheckerallapplication.txt", ios::app);
				while (getline(read1, line1))
				{
					(getline(read, line));
					{
						if (j == 0)
						{

							if (line == "Agreed")
							{
								in1 << line1 << endl;
							}
							if (line == "Not Agreed")
							{
								in2 << line1 << endl;
							}
						}
						else
						{
							j--;
						}
					}
				}
				in1.close();
				in2.close();
				read.close();
				read1.close();
			}
		}
		if (file == 0)
		{
			check = 0;
			re.close();
			re.open("BM.txt", ios::app);
			while (getline(re, line))
			{
				if (check == 1 && id == line)
				{
					cout << "BM account accesed" << endl;
					file = 1;
					k++;
				}
				else
					check++;
			}
		}
		if (file == 0)
		{
			int mov = 0;
			int aa = 0;
			check = 2;
			re.close();
			re.open("AppAccepted.txt", ios::app);
			while (getline(re, line) && file == 0)
			{
				mov++;
				int found, i = 0;
				string test2;
				test2 = line;
				string rest[13];
				while (test2 != "\0")
				{
					found = test2.find("<<");
					for (int f = 0; f < found; f++)
					{
						rest[i] += test2[f];
					}
					test2.erase(0, found + 2);
					i++;
				}
				if (rest[10] == id&&rest[11] == pas)
				{
					file = 1;
					aa = 1;
					cout << "Student account accessed" << endl;
					STUDENTSINFO qe;
					qe.Studeacc(mov);
				}
			}
		}
		if (file == 0 && tak == 0)
		{
			int aa = 0;
			check = 2;
			re.close();
			re.open("TEACHEACCEP.txt", ios::app);
			while (getline(re, line) && tak == 0)
			{
				int found, i = 0;
				string test2;
				test2 = line;
				string rest[12];
				while (test2 != "\0")
				{
					found = test2.find(" ");
					for (int f = 0; f < found; f++)
					{
						rest[i] += test2[f];
					}
					test2.erase(0, found + 1);
					i++;
				}
				if (rest[5] == id&&rest[6] == pas)
				{
					file = 1;
					aa = 1;
					cout << "Teacher account accessed" << endl;
					tak = 1;
					Teacher qa;
					qa.teacheacc();
				}
			}
		}
		if (file == 0)
		{
			int aa = 0;
			check = 2;
			re.close();
			re.open("papercheckeraccepted.txt", ios::app);
			while (getline(re, line) && tak == 0)
			{
				int found, i = 0;
				string test2;
				test2 = line;
				string rest[7];
				while (test2 != "\0")
				{
					found = test2.find(" ");
					for (int f = 0; f < found; f++)
					{
						rest[i] += test2[f];
					}
					test2.erase(0, found + 1);
					i++;
				}
				if (rest[2] == id&&rest[3] == pas)
				{
					file = 1;
					aa = 1;
					cout << "Paper checker account accessed" << endl;
					tak = 1;
					Teacher qa;
					qa.teacheacc();
				}
			}
		}
		if (file == 0)
		{
			cout << "No account exist of this type" << endl;
			Sleep(2000);
			username();
		}
	}
	else if (a == 2)//account nai bana
	{
		int a = 0;
		ifstream re;
		ofstream in;
		re.open("BM.txt", ios::app);
		while (getline(re, line))
		{
			a = 1;//CM ka account bana hai
		}
		if (a == 0)//to board member ka account bane ga
		{
			CHAIRMAN obj;
			obj.bm();
			re.close();
		}
		else if (a = 1)
		{
			re.close();
			re.open("CM.txt", ios::app);
			a = 0;
			while (getline(re, line))
			{
				a = 1;
			}
			if (a == 0)//to board member ka account bane ga
			{
				CHAIRMAN obj;
				obj.csce("CM");
			}
			re.close();
			system("cls");
			username();
		}
	}
	else
	{
		cout << "YOur Input is not correct " << endl;
		Sleep(1500);
		username();
	}
}
