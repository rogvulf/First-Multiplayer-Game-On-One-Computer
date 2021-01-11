// air_hockey.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <thread>
#include "math.h"

using namespace std;

class hockey_racket
{
	class racket_part
	{
		int x,
			y;
	public:
		racket_part(){}
		racket_part(int X,int Y);
		~racket_part(){}
		int getX();
		int getY();
		void setX(int X);
		void setY(int Y);
	};
	racket_part racket[3];	
	void changeble(int X,int Y);
	char symbol;
public:
	hockey_racket(){}	
	hockey_racket(int X,int Y);
	racket_part return_by_part_of_racket(int number_of_part);
	void pressed_right();
	void pressed_left();
	void pressed_up();
	void pressed_down();
	void setSymbol(char Symbol);
	char getSymbol();
	//void create_racket();	
};

/*void hockey_racket::create_racket()
{
	racket_part parts[3]{};
	cout << parts[0].getX()<<endl;
	cout << parts[1].getX()<<endl;
	cout << parts[2].getX()<<endl;
	//racket_part part_1(x, y);
	//racket_part part_2(x, y + 1);
	//racket_part part_3(x, y + 2);
}*/

class ball
{
	int x, y;
	char symbol;
public:
	ball(){}
	~ball(){}
	int GetX();
	int GetY();
	void SetX(int X);
	void SetY(int Y);
	char GetSymbol();
	void SetSymbol(char Symbol);
	void direction(hockey_racket){} //?
	void test_direction(hockey_racket, hockey_racket, bool &, bool&);
	void gravitation(bool&);
};

void function_ai(hockey_racket &object);
void function_on_screen(hockey_racket object, hockey_racket object2, ball playball, ball graviball, ball[]);

int some_function(int){ return NULL; }

int someInSquare(int);
void strangething(){}
int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	/*if (3 <= 5)
		cout << 5 << endl;
	if (5==5)
		//if (3==5)
		cout << "true" <<endl;*/
	/*some_function(5);
	cout << some_function(rand()) << endl;
	cout << someInSquare<< endl;
	//something() = (int*)5;
	cout << &someInSquare << endl;
	cout << strangething << endl;
	cout << someInSquare(rand()%10)*someInSquare(rand()%10) << endl;					// trying to get size of function, at now unresultible
	cout << someInSquare <<	endl
		<< (int*)(someInSquare)+1 << endl
		<< (void*)((char*)(someInSquare)+1) << endl
		<< sizeof(*someInSquare) << endl;		


		*/
	system("pause");			////// new method to divide program!!!!!
	hockey_racket object(1,11);
	object.setSymbol(254);
	hockey_racket object2(78, 11);
	object2.setSymbol(254);
	bool direction{};
	bool choose_direction{};
	bool gravitation{ 1 }, UpOrdawn{};
	ball playball;  playball.SetX(40);  playball.SetY(1); playball.SetSymbol(2);
	ball graviball; graviball.SetX(40); graviball.SetY(1); graviball.SetSymbol(1);
	ball gravball[5];
	for (int counter{}; counter < 5; counter++)
	{
		gravball[counter].SetX(counter);
		gravball[counter].SetY(1);
		gravball[counter].SetSymbol(1);
	}		
	while (true)
	{		
		/*if ((object2.return_by_part_of_racket(0).getY() >= 0 && !choose_direction) || 23 == object2.return_by_part_of_racket(2).getY() || object2.return_by_part_of_racket(1).getY()>playball.GetY())
		{
			choose_direction = false;
			object2.pressed_left();
		}
		//object.pressed_up();
		if ((object2.return_by_part_of_racket(2).getY() < 23 && choose_direction) || 0 == object2.return_by_part_of_racket(0).getY() || object2.return_by_part_of_racket(1).getY()<playball.GetY())
		{
			choose_direction = true;
			object2.pressed_right();
		}*/
		//if (GetAsyncKeyState(VK_NUMPAD8) & 0x8000)
		//if (GetAsyncKeyState(VK_NUMPAD2) & 0x8000)
		if (GetAsyncKeyState(VK_NUMPAD8) & 0x8000)
		{
			//Player.counterdown--;
			object2.pressed_up();
		}
		else if (GetAsyncKeyState(VK_NUMPAD2) & 0x8000)
		{
			object2.pressed_down();
		}
		playball.test_direction(object, object2, direction, UpOrdawn);
		graviball.gravitation(gravitation);
		//for (int counter{}; counter < 5; counter++)
			//gravball[counter].gravitation(gravitation);
		//function_ai(object2);
		//object2.pressed_up();
		/*if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			//Player.counterright++;
			object2.pressed_right();
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			object2.pressed_left();
		}
		else */if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			//Player.counterdown--;
			object.pressed_up();
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			object.pressed_down();
		}
		function_on_screen(object, object2, playball,graviball,gravball);
		//this_thread::sleep_for(chrono::milliseconds(30));
		system("CLS");
	}	
	system("pause");
	return 0;
}

void hockey_racket::setSymbol(char Symbol)
{
	this->symbol = Symbol;
}

char hockey_racket::getSymbol()
{
	return this->symbol;
}

void hockey_racket::changeble(int X, int Y)
{	
	for (int counter{}; counter < sizeof(this->racket) / (sizeof(racket_part)); counter++)
	{
		if (!counter)
		{
			this->racket[counter].setX(X);
			this->racket[counter].setY(Y);
		}
		else
		{
			this->racket[counter].setX(X);
			this->racket[counter].setY(Y + counter);
		}
		//cout << "part " << counter << " (X) " << this->racket[counter].getX() << endl;
		//cout << "part " << counter << " (Y) " << this->racket[counter].getY() << endl;
	}
	//cout << sizeof(racket)/(sizeof(racket_part)) <<" objects be in da array" << endl;
	//cout << (this->racket) << endl;;
}
hockey_racket::hockey_racket(int X, int Y)
{
	this->changeble(X,Y);
}

hockey_racket::racket_part hockey_racket::return_by_part_of_racket(int number_of_part_begin_from_0_do_not_forgot_this)  // good hint:)
{
	return *(this->racket + number_of_part_begin_from_0_do_not_forgot_this);
	// another variant return this->racket[number_of_part];
}

hockey_racket::racket_part::racket_part(int X,int Y)
{
	this->x=X;
	this->y=Y;
}

int hockey_racket::racket_part::getX()
{
	return this->x;
}
int hockey_racket::racket_part::getY()
{
	return this->y;
}
void hockey_racket::racket_part::setX(int X)
{
	this->x = X;
}
void hockey_racket::racket_part::setY(int Y)
{
	this->y = Y;
}

void hockey_racket::pressed_right()
{
	if (this->return_by_part_of_racket(0).getY()<21)
		this->changeble(this->return_by_part_of_racket(0).getX(), this->return_by_part_of_racket(0).getY() + 1);
}
void hockey_racket::pressed_left()
{
	if (this->return_by_part_of_racket(0).getY()>0)
		this->changeble(this->return_by_part_of_racket(0).getX(), this->return_by_part_of_racket(0).getY() - 1);
}
void hockey_racket::pressed_up()
{
	if (this->return_by_part_of_racket(0).getY()>0)
	this->changeble(this->return_by_part_of_racket(0).getX(), this->return_by_part_of_racket(0).getY() - 1);
}
void hockey_racket::pressed_down()
{
	if (this->return_by_part_of_racket(0).getY()<21)
	this->changeble(this->return_by_part_of_racket(0).getX(), this->return_by_part_of_racket(0).getY() + 1);
}

/*void function_ai(hockey_racket &object)
{
	bool choose_direction{};
	if ((object.return_by_part_of_racket(0).getY() >= 0 && !choose_direction) || 22 == object.return_by_part_of_racket(2).getY())
	{
		choose_direction = true;
		object.pressed_left();
	}		
	//object.pressed_up();
	if ((object.return_by_part_of_racket(2).getY() < 22 && !choose_direction) || 0 == object.return_by_part_of_racket(0).getY())
	{
		choose_direction = false;
		object.pressed_right();
	}
		
}*/

void function_on_screen(hockey_racket object, hockey_racket object2, ball playball, ball graviball, ball ballarray[])
{
	bool checker{};
	for (int y{}, var_counter{}, var_counter2{}; y < 24; y++)
		for (int x{}; x < 80; x++)
		{
		if (x == object.return_by_part_of_racket(var_counter).getX() && y == object.return_by_part_of_racket(var_counter).getY())
		{
			cout << object.getSymbol();
			var_counter++;
		}
		else
			if (x == object2.return_by_part_of_racket(var_counter2).getX() && y == object2.return_by_part_of_racket(var_counter2).getY())
			{
			cout << object2.getSymbol();
			var_counter2++;
			}
			else
				if (x == playball.GetX() && y == playball.GetY())
				{						
						cout << playball.GetSymbol();
						if (playball.GetX() == 40 && playball.GetY() == 11)
							this_thread::sleep_for(chrono::milliseconds(1000));
					/*if (false/*playball.GetX() != 40 && playball.GetY() != 11);			//we have some interest bugif(false condition) work like with true
						{
							cout << "hgfgfdgfdgfdsrgfdsrtfs";
							this_thread::sleep_for(chrono::milliseconds(500));
						}	*/				
				}					
				else
				//if (x == graviball.GetX() && y == graviball.GetY())
						//cout << graviball.GetSymbol();
					//else
						//for (int counter{}; counter < 5; counter++)
						
							//if (x == ballarray[counter].GetX() && y == ballarray[counter].GetY())
							//{
								//checker = true;
								//cout << ballarray[counter].GetSymbol();
							//}	
							// if(checker)
							
								 cout << " ";
							// checker = 0;
			/*else
				if (y== playball.GetY())
					cout << playball.GetSymbol();*/ // interesting idea for powerful strike 		
		}
			
	//cout << endl;
}


int ball::GetX()
{
	return this->x;
}
int ball::GetY()
{
	return this->y;
}
void ball::SetX(int X)
{
	this->x = X;
}
void ball::SetY(int Y)
{
	this->y = Y;
}
char ball::GetSymbol()
{
	return this->symbol;
}
void ball::SetSymbol(char Symbol)
{
	this->symbol = Symbol;
}

void ball::test_direction(hockey_racket hockey_object, hockey_racket hockey_object2, bool &direction, bool& UpOrdawn)
{
	int checker{};
	/*for (int counter{};
		counter < (sizeof(hockey_racket) / sizeof(hockey_object.return_by_part_of_racket(rand() % 3)));
		counter++)
	{
		//if ((x>hockey_object.return_by_part_of_racket(counter).getX() && !direction || hockey_object.return_by_part_of_racket(counter).getX() == x)) //x>0= old version
		if ((78 == this->x && this->y == hockey_object2.return_by_part_of_racket(counter).getY()) || (1 == this->x && this->y == hockey_object.return_by_part_of_racket(counter).getY()))
			checker = 1;

		
		if (hockey_object.return_by_part_of_racket(counter).getX() == x)
		{
			direction = true;
			//this->x++;
		}
		else if (hockey_object2.return_by_part_of_racket(counter).getX() == x)
		{
			direction = false;
			//this->x--;
		}			
		 // we have some troubles, if we using functions bool var will be recalled, and his value would be rewrited, and will been false again and again as we called function     ..oops			
		//if ((x<78 && direction)||) // still be old
	}	*/	

	if (0 == this->y)
		UpOrdawn = 0;
	if (23 == this->y)
		UpOrdawn = 1;
	if (!direction)
	{ 
		if (!UpOrdawn)
			this->y++;
		else if (UpOrdawn)
			this->y--;
		
		this->x--;
	}		
	else if (direction)
	{
		this->x++;
		if (!UpOrdawn)
			this->y++; //dawn
		else if (UpOrdawn)
			this->y--;  //  up!
	}		
	for (int counter{};
		counter < (sizeof(hockey_racket) / sizeof(hockey_object.return_by_part_of_racket(rand() % 3)));
		counter++)
	{
		//if ((x>hockey_object.return_by_part_of_racket(counter).getX() && !direction || hockey_object.return_by_part_of_racket(counter).getX() == x)) //x>0= old version
		if ((78 == this->x && this->y == hockey_object2.return_by_part_of_racket(counter).getY()) || (1 == this->x && this->y == hockey_object.return_by_part_of_racket(counter).getY()))
			checker = 1;


		if (hockey_object.return_by_part_of_racket(counter).getX() == this->x && hockey_object.return_by_part_of_racket(counter).getY() == this->y)
		{
			direction = true;
			this->x++;
			cout << char(7);
		}
		if (hockey_object2.return_by_part_of_racket(counter).getX() == this->x && hockey_object2.return_by_part_of_racket(counter).getY() == this->y)
		{
			direction = false;
			this->x--;
			cout << char(7);
		}
		// we have some troubles, if we using functions bool var will be recalled, and his value would be rewrited, and will been false again and again as we called function     ..oops			
		//if ((x<78 && direction)||) // still be old
	}
	if (!checker && 78 == this->x || 1 == this->x && !checker)
	{
		system("pause");
		system("cls");
		this->x = 40;
		this->y = 11;
		direction = rand() % 2;
		UpOrdawn = rand() % 2;

	}
	//if (0 == this->y)
		//this->y++;
	//if (23 == this->y)
		//this->y--;
	&someInSquare;




	


}

void ball::gravitation(bool &gravitation)
{
	if (this->y > 22)
		this->y = 0;
	if (gravitation)
		this->y++;
}