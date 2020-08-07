#include <fstream>
#include <iostream>
#include <stdlib.h>
#include<cstring>
#include "myconsole.h"
#include "editor.h"
using namespace std;

//-------------------------------Color Codes------------------------------//
// Color Codes Hexadecimal values for both Fore Ground and Back Ground //ForeGround|BackGround
int B_BLACK			= 0x00;	int B_Royal_Blue	= 0x10;	int B_Dark_Green	= 0x20;
int B_Tale_Blue		= 0x30;	int B_Dark_Red		= 0x40;	int B_Purple		= 0x50;
int B_Tale_Green	= 0x60;	int B_Light_Grey	= 0x70; int B_Dark_Gray		= 0x80;	
int B_Light_Blue	= 0x90; int B_Light_Green	= 0xA0;	int B_Sky_Blue		= 0xB0;
int B_Red			= 0xC0;	int B_Pink			= 0xD0;	int B_Yellow		= 0xE0;
int B_White			= 0xF0;

int F_BLACK			= 0x00;	int F_Royal_Blue	= 0x01; int F_Dark_Green = 0x02;
int F_Tale_Blue		= 0x03;	int F_Dark_Red		= 0x04;	int F_Purple	 = 0x05;
int F_Tale_Green	= 0x06;	int F_Light_Grey	= 0x07; int F_Dark_Gray	 = 0x08;
int F_Light_Blue	= 0x09; int F_Light_Green	= 0x0A;	int F_Sky_Blue	 = 0x0B;
int F_Red			= 0x0C;	int F_Pink			= 0x0D;	int F_Yellow	 = 0x0E;
int F_White			= 0x0F;

//-------------------------------POINT CLASS------------------------------//
//initialize MaxPoint
point point::MaxPoint(MAX_X, MAX_Y);
bool point::incrementX()
{
	bool returnValue = true;
	if (x<MaxPoint.x)
		x++;
	else if (y<MaxPoint.y)
	{
		x = 0;
		y = y + 1;
	}
	else
		returnValue = false;

	return returnValue;
}

bool point::incrementY()
{
	bool returnValue = true;
	if (y<MaxPoint.y)
		y++;
	else
		returnValue = false;

	return returnValue;

}
bool point::decrementX()
{
	bool returnValue = true;
	if (x>0)
		x--;
	else if (y>0)
	{
		y--;
		x = MaxPoint.x;
	}
	else
		returnValue = false;

	return returnValue;
}
bool point::decrementY()
{
	bool returnValue = true;
	if (y>0)
		y--;
	else
		returnValue = false;

	return returnValue;

}
struct node
{
	char value;
	node *next= NULL;
	node *prev= NULL;
};
void initialize(node *&n)
{	
	cin >> n->value;
	if(n->value==32)
	{
		n->value=' ';
	}
}
void insert_at_tail(node *&head,node *&curr1, node *&n,int &pos)
{
	node *temp3;
	if(curr1==NULL)
	{
		curr1=n;
		head=n;
	}
	else
	{
		int i=0;
		while (curr1->next != NULL && i!=pos-2)
		{
			curr1=curr1->next;
			i++;
	    }
			temp3=curr1->next;
			curr1->next = n;
			n->prev=curr1;
			n->next=temp3;
	}
}
void insert_at_tail2(node *&head,node *&curr1, node *&n,int &pos)
{
	node *temp3;
	if(curr1==NULL)
	{
		curr1=n;
		head=n;
	}
	else
	{
		int i=0;
		while (curr1->next != NULL && i!=pos)
		{
			curr1=curr1->next;
			i++;
	    }
			temp3=curr1->next;
			curr1->next = n;
			n->prev=curr1;
			n->next=temp3;
	}
}
void del(node *&curr,int &pos,node *&head)
{
	int i=0;
	int count=0;
	while(i!=pos)
	{
		if(curr->next!=NULL)
		{
		curr=curr->next;
		count++;
	    }
		i++;
	}
	if(i==count)
	{
		if(curr->next!=NULL && curr->prev!=NULL)
		{
			curr->prev->next=curr->next;
			curr->next->prev=curr->prev;
			
		}
		else if(curr->next==NULL &&  curr->prev!=NULL )
		{
			curr->prev->next=NULL;
	     	curr->prev=NULL;
	    	delete curr;
	    	
		}
		else if(curr->next!=NULL && curr->prev==NULL)
		{
			head=curr->next;
			delete curr;
			curr=head;
			curr->prev=NULL;
	    }
	}
}
void del1(node *&curr,int &pos,node *&head)
{
	int i=0;
	int count=0;
	while(i<pos-1)
	{
		if(curr->next!=NULL)
		{
		curr=curr->next;
		count++;
	    }
		i++;
	}
	if(i==count)
	{
		if(curr->next!=NULL && curr->prev!=NULL )
		{
			curr->prev->next=curr->next;
			curr->next->prev=curr->prev;
			delete curr;
		}
		else if(curr->next==NULL &&  curr->prev!=NULL )
		{
			curr->prev->next=NULL;
	     	curr->prev=NULL;
	    	delete curr;
	    	
		}	
	}
}

void displayall(node *curr)
{	
	while (curr != NULL)
	{
		cout << curr->value ;
		curr = curr->next;
	}
}
bool search(node *head1,node *curr1,node *curr,int &p)
{
	node *head=curr;
	int count=0;
	bool found =false;
	while(curr->next!=NULL && found==false)
	{
		count++;
		if(curr->value==curr1->value  )
		{
			while(curr->next!=NULL && curr1->next!=NULL && curr->value==curr1->value )
			{
				curr=curr->next;
				curr1=curr1->next;
				cout<<endl;
			}
			if(curr1->next==NULL)
			{
				if(curr1->value==curr->value)
				{
					found=true;
			        curr=head;
			    }
			}
			else
			{
				curr1=head1;
			}
			curr=head;
		}
		curr=head;
	    	for(int i=0;i<count;i++)
			{
				if(curr->next!=NULL)
				{
				   curr=curr->next;
			    }
			}
	}
	p=count;
	p--;
		return found;
}
void insert_at_tail(node *curr1, node *&n)
{
	while (curr1->next != NULL )
	{
		curr1 = curr1->next;
	}
	if(curr1==NULL)
	{
		curr1=n;
	}
	else
	{
		curr1->next = n;
		n->prev=curr1;
    }
    
}
void del_multiple(node *head1,node *curr1,node *&curr)
{
	node *head=curr;
	int count=0;
	bool found =false;
	node *start=NULL;
	node *end=start;
	while( found==false)
	{
		count++;
		if(curr->value==curr1->value  )
		{
			start=curr;
			while(curr->next!=NULL && curr1->next!=NULL && curr->value==curr1->value )
			{
				
				curr=curr->next;
				curr1=curr1->next;
				cout<<endl;
			}
			if(curr1->next==NULL)
			{
				if(curr1->value==curr->value)
				{
					found=true;
					end=curr;
			    }
			}
			else
			{
				curr1=head1;
			}
			curr=head;
		}
		curr=head;
	    	for(int i=0;i<count;i++)
			{
				if(curr->next!=NULL)
				{
				   curr=curr->next;
			    }
			}
	}
	if(start->prev!=NULL && end->next!=NULL && found==true)
	{
			node *h=start;
			node *t=end;
			node *temp;
			start->prev->next=end->next;
			end->next->prev=start->prev;
			while(h!=t)
			{
				temp=h->next;
				delete h;
				if(h==t)
				{
					delete t;
				}
				h=temp;
			}
	}
		else  if(start->prev!=NULL && end->next==NULL && found==true)
		{
			node *temp1;
			start->prev->next=NULL;
			while(start!=end)
			{
				temp1=start->next;
				delete start;
				start=temp1;
				if(start==end)
				{
					delete start;
				}
			}
		}
		 else if(start->prev==NULL && end->next==NULL && found==true )
		{
			node *temp2;
			start=start->next;
			while(start!=end)
			{
				temp2=start->next;
				delete start;
				start=temp2;
				if(start==end)
				{
					delete start;
				}
			}
			head->next=NULL;
			curr=head;
		}
		else if(start->prev==NULL && end->next!=NULL && found==true)	
		{
			
			node *temp2;
			head=end->next;
			head->prev=NULL;
			while(start!=end)
			{
				temp2=start->next;
				delete start;
				start=temp2;
				if(start==end)
				{
					delete start;
				}
			}	
		}
		found=false;
		curr=head;
}

void display_backward(node *curr)
{
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	while(curr!=NULL)
	{
		cout<<curr->value;
		curr=curr->prev;
	}
	cout<<endl;	
}
//-------------------------------END OF POINT CLASS------------------------------------------------//


//--------------------------The function Where you will write code--------------------------------//
int mainEditor()
{	
	node *head;
	head = NULL;
	node *curr1 = head;
	int key = 0;
	bool stop = false;
	point currentPosition(0, 0);
	currentPosition.setMaxPoint(MAX_X, MAX_Y);
	bool specialKey = false;
	int pos=1;
    int pos1=pos;
    int y=0;
    node *tail=NULL;
	while (!stop)
	{
		key = CheckWhichKeyPressed(specialKey);
		//escape key
		if (key == ESCKEY)
		{
			stop = true;
			system("CLS");
			cout<<endl<<endl<<endl;
			displayall(curr1);
			display_backward(curr1);
		}
		//printable character...only adds to the end of text
		//this will not do insertions in between text
		//add code here to insert characters within text
		else if (!specialKey&&key >= 32 && key <= 126)
		{	
			if (currentPosition.getX() < MAX_X)
			{
			 
				node *n = new node;
				pos1=pos;
				insert_at_tail(head,curr1, n,pos);
				pos=pos1;
				n->value=(char)key;
				curr1=head;
				currentPosition.incrementX();
					pos++;	
				system("CLS");
				displayall(curr1);
				//You can change color of text by calling this function
			   //ForeGround|BackGround
			}
			else if (currentPosition.getY() < MAX_Y)
			{
				currentPosition.incrementY();
				y++;
				currentPosition.setX(0);
				system("CLS");
				displayall(curr1);
			}
		}
		else if (specialKey&&key == LEFTKEY)
		{
			currentPosition.decrementX();
			pos--;
			if(pos<2)
			{
				pos++;
			}
			
		}
		else if (specialKey&&key == RIGHTKEY)
		{
			currentPosition.incrementX();
			pos++;
		}
		else if (specialKey&&key == UPKEY)
		{
			currentPosition.decrementY();
			pos=pos-80;
			if(pos<2)
			{
				pos=pos+80;
			}
		}
	
		else if (specialKey&&key == DOWNKEY)
		{	//Update it so that cursur not move downword if it is at last line of text.
			currentPosition.incrementY();
			pos=pos+80;
		}
		else if (key == ENTERKEY)
		{
			     cout << ('\n');
			    currentPosition.setX(0);
			    currentPosition.incrementY();
			    node *n = new node;
				n->value='\n';
				pos++;
				pos1=pos;
				insert_at_tail(head,curr1, n,pos);
				pos=pos1;
				curr1=head;
		}
		else if (key == DELKEY)
		{
			//call a function to handle 
			del(curr1,pos,head);
			curr1=head;
			system("CLS");
			displayall(curr1);
		}
		else if (key == BACKSPACE)
		{
			cout << '\0';
			while(curr1->next!=NULL)
			{
				curr1=curr1->next;
			}
			if(curr1->value=='\n')
			{
			       curr1=head;
			       pos1=pos;
			 	    del1(curr1,pos,head);
			        pos=pos1;
			        pos--;
			        cout<<currentPosition.getX();
					currentPosition.decrementX();
					curr1=head;	
					currentPosition.setX(0);
					while(currentPosition.getX()!=pos)
					{
					    currentPosition.incrementX();
					}
					if(pos<2)
					{
						currentPosition.incrementX();
						pos++;
					}
					system("CLS");
					displayall(curr1);
			}
			else
			{
				
				    curr1=head;
				    pos--;
					del1(curr1,pos,head);
				
					if(pos<2)
					{
						currentPosition.incrementX();
						pos++;
					}
					curr1=head;	
					system("CLS");
					displayall(curr1);
			}
			 if (!currentPosition.decrementX() && currentPosition.getY() > 0)
			{
				curr1=head;
				cout << '\0';
				currentPosition.decrementY();
				currentPosition.setX(MAX_X);
			}
		}
		else if (key == F1KEY)
		{
			//handle search here
			//you can take the cursor at the bottom of the screen and get some input
			//for searching
			//PlaceCursor(0, MAX_Y);
			/*for (int i = 0; i < MAX_X; i++)
			{
				cout << '\0';
				currentPosition.incrementX();
			}*/

			//PlaceCursor(0, MAX_Y);
			int size2;
			node *head2=NULL;
	        node *curr2=NULL;
	        cout<<endl<<endl;
			cout<<"enter size of link list of search querry"<<endl;
			cin>>size2;
		    cout << "Enter Search Query: ";
			// currentPosition.setX(0 + strlen("Enter Search Query : "));
			//currentPosition.setY(MAX_Y);
			node *n2 = new node;
			initialize(n2);
			head2= n2;
			curr2 = head2;
			int k=0;
			while (k != size2-1)
			{
				node *n2 = new node;
				initialize(n2);
				insert_at_tail(curr2, n2);
				k++;
			}
			for(int i=0;i<pos;i++)
			{
				if(curr1->next!=NULL)
				{
					curr1=curr1->next;
				}
			}
			if(curr1->next!=NULL)
			{
				while(curr1->next!=NULL)
				{
					curr1=curr1->next;
					currentPosition.incrementX();
					pos++;
				}
				pos++;
				currentPosition.incrementX();	
			}
			
			curr1=head;
			 cout<<endl;
			 int p=pos;
		     bool found=search(head2,curr2,curr1,p);
		     node *d;
		     while(curr2->next!=NULL)
		     {
		     	curr2=curr2->next;
			 }
			 while(curr2->prev!=NULL)
			 {
			 	d=curr2->prev;
			 	delete curr2;
			 	curr2=d;
			 }
		     cout<<p;
		     if(found==true)
		     {
			     	if(pos!=p)
			     	{
			     	  system("CLS");
				      displayall(curr1);
				      while(pos!=p)
				      {
				      	currentPosition.decrementX();
			     		pos--;	 
					  }
				    }
			}
			 else
			 {
			 	cout<<"search query not found"<<endl;
		     	system("pause");
			 	system("CLS");
			    displayall(curr1);
			 }
			 PlaceCursor(pos,0);
		}
		else if (key == F2KEY)
		{
			//save to file
			ofstream fout;
            fout.open ("my editor.txt");
            while(curr1->next!=NULL)
            {
              fout<<curr1->value;
              curr1=curr1->next;
            }
            fout<<curr1->value;
            fout.close();
            curr1=head;
		}
		else if (key==F3KEY)
		{
				//PlaceCursor(0, MAX_Y);
		/*	for (int i = 0; i < MAX_X; i++)
			{
				cout << '\0';
				currentPosition.incrementX();
			}

			PlaceCursor(0, MAX_Y);
			*/
			int size3;
			node *head3=NULL;
	        node *curr3=NULL;
	        cout<<endl;
			cout<<"enter size of string of cut querry"<<endl;
			cin>>size3;
		    cout << "cut query: ";
			// currentPosition.setX(0 + strlen("Enter cut Query : "));
			 //urrentPosition.setY(MAX_Y);
			node *n3 = new node;
			initialize(n3);
			head3= n3;
			curr3 = head3;
			int k3=0;
			while (k3 != size3-1)
			{
				node *n3 = new node;
				initialize(n3);
				insert_at_tail(curr3, n3);
				k3++;
			}	
			
			for(int i=0;i<pos;i++)
			{
				if(curr1->next!=NULL)
				{
					curr1=curr1->next;
				}
			}
			if(curr1->next!=NULL)
			{
				while(curr1->next!=NULL)
				{
					curr1=curr1->next;
					currentPosition.incrementX();
					pos++;
				}
				pos++;
				currentPosition.incrementX();	
			}
			curr1=head;
			
			 cout<<endl;
			 int p=pos;
		     bool found1=search(head3,curr3,curr1,p);
		     p++;
		     cout<<p;

		     if(found1==true)
		     {
		     	curr1=head;
		     	del_multiple(head3,curr3,curr1);
		     	if(pos!=p)
		     	{
		     	  system("CLS");
			      displayall(curr1);
			      while(pos!=p)
			      {
			      	currentPosition.decrementX();
		     		pos--;	 
				  }
				  currentPosition.decrementX();
		     		pos--;	
		     		currentPosition.decrementX();
		     		pos--;	
			    }
				 cout<<endl<<endl;
			    int size5=0,s=0;
			    cout<<"enter size of string you want to paste"<<endl;
			    cin>>size5;
			    cout<<"enter string you want to paste"<<endl;
			    while(s!=size5)
			    {
				    node *n = new node;
					cin>>n->value;
					if(pos<1)
                	{
	             	pos++;
                   	}
					pos1=pos;
					insert_at_tail2(head,curr1, n,pos);
					pos=pos1;
					pos++;
					currentPosition.incrementX();
					curr1=head;
					s++;
			    }
			    curr1=head;
			    system("CLS");
			    displayall(curr1);
			 }
			 else
			 {
			 	cout<<"cut querry not found"<<endl;
			     system("pause");
			 }
		     PlaceCursor(pos,0);
		}
		PlaceCursor(currentPosition.getX(), currentPosition.getY());
	}
	cout<<endl<<endl<<endl<<endl<<endl;
	return 0;
}
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 1537
#endif

#include <windows.h>
#ifdef _WIN32_WINNT
#undef _WIN32_WINNT
#define _WIN32_WINNT 1537
#endif
#include <WinCon.h>
#include <iostream>
//#include <fstream>
//#include <stdio.h>
//#include <stdlib.h>
#include <conio.h> 

using namespace std;

#include "myconsole.h"


//this function outputs a string str at position (x,y) of the screen 
void OutputString(int x, int y, char *str)
{
	COORD c;
	c.X = x;
	c.Y = y;

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, c);
	cout << str;
	cout.flush();
}

//this function will clear the screen
void ClearScreen()
{
	CONSOLE_SCREEN_BUFFER_INFO info;

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(h, &info);
	system("cls");
	SetConsoleCursorPosition(h, info.dwCursorPosition);

}

//alternative to ClearScreen for Windows7 platform
/*void ClearScreen1()
{
PlaceCursor(0,0);

cout << string(10000, ' ');

cout.flush();
PlaceCursor(0,0);
}
*/
//this function will place the cursor at a certain position on the screen
void PlaceCursor(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, c);
}




//this function checks if a key is pressed and if a key is pressed
//then it returns the ascii code/virtual code of the key pressed
//specialKey would be returned as true if it is a key associated with a non-printable character
//specialKey would be returned as false if ordinary printable characters are typed
//if no key is pressed then specialKey value will not be changed
//the parameter waitTime specifies how long we have to wait for an input
//the default value is 20 millisecond.  If within the wait time no key is pressed
//the function returns zero.
unsigned int CheckWhichKeyPressed(bool &specialKey, int waitTime)
{
	HANDLE h = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD r;
	DWORD w = 1;
	DWORD eventss;
	DWORD waitResult = 0;
	int keypressed = false;
	int toReturn = 0;

	waitResult = WaitForSingleObject(h, waitTime);

	if (waitResult == WAIT_OBJECT_0)
	{
		//FlushConsoleInputBuffer(h);..commented out as this takes to asynchronous mode on some systems
		keypressed = ReadConsoleInput(h, &r, 1, &eventss);

		if (keypressed && r.EventType == KEY_EVENT && r.Event.KeyEvent.bKeyDown)
		{
			toReturn = r.Event.KeyEvent.wVirtualKeyCode;

			if (r.Event.KeyEvent.uChar.AsciiChar)
			{
				toReturn = r.Event.KeyEvent.uChar.AsciiChar;
				specialKey = false;
			}
			else
				specialKey = true;

		}
		//this should make sure that checkKeyPressed is not called twice for arrow keys
		if (toReturn == 224)
			toReturn = CheckWhichKeyPressed(specialKey, waitTime);


		FlushConsoleInputBuffer(h);
	}
	return toReturn;
}
void GetMaxWindowSize(int &maxHorizontal, int &maxVertical)
{
	COORD c;
	//    c.X = x;
	//   c.Y = y;

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	c = GetLargestConsoleWindowSize(h);
	maxHorizontal = c.X;
	maxVertical = c.Y;
}

//set the title of the window
/*void SetWindowTitle(char Title[])
{
	SetConsoleTitle(Title);
}*/


void GetMaxWindowCoordinates(int &x, int &y)
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(h, &info);
	x = info.srWindow.Right;
	y = info.srWindow.Bottom;
}

//won't set for more than a certain height and certain width, depending
//upon your system
void SetWindowSize(int width, int height)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	bool bAbs = true;
	SMALL_RECT r;

	r.Left = 0;
	r.Top = 0;
	r.Right = width;
	r.Bottom = height;

	SetConsoleWindowInfo(h, bAbs, &r);
}

//changes the color of a certain co-ordinate
//color can be input using a combination of foreground and Back grounfd Color and | operator
bool SetColorAtPoint(int x, int y, int color)
{
	COORD c, size;
	c.X = x;
	c.Y = y;
	size.X = 1;
	size.Y = 1;

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD w = color;
	unsigned long written = 0;
	WriteConsoleOutputAttribute(h, &w, 1, c, &written);

	if (written)
		return true;

	return false;
}
//-------------------------------------------End Main Editor--------------------------//
int main()
{
	mainEditor();
}


