//*********************************************************
//
// Includes and Defines
//
//*********************************************************
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <cstdlib>
#include <sys/wait.h>
#include <cstring>
#include <stdio.h>
using namespace std;
char history[10];
//*********************************************************
//
// Class Declarations
//
//*********************************************************
class hist 
{
   private:
     char data[10][100];
     int count;
   public:
     hist();
     void add(char[]);
     void get(int, char[]);
     void display();
};

hist::hist()
{
   count = 0;
   for (int i = 0; i < 10; ++ i)
     strcpy(data[i], "");
}

void hist::add(char x[])
{
  int i;
  if (count < 10)
  {
     strcpy(data[count], x);
     ++ count;
  }
  else   // shift if it is full
  {
    for (i = 0; i < 9; ++ i)
       strcpy(data[i], data[i+1]);
    strcpy(data[9],x);
  }
  return;
}

void hist::get(int x, char y[])
{
   if (x <= count)
     strcpy(y, data[x - 1]);
   else
     strcpy (y, "");
   return;
}

void hist::display()
{
   for (int i = 0; i < count; ++ i)
      cout << data[i] << endl;
   return; 
}
hist commands;
//*********************************************************
//
// Extern Declarations
//
//*********************************************************
extern "C"
{
  extern char **gettoks();
} 

void exe(char** argc) //shell fork function
{
pid_t pid;
int status = 0;
if ((pid = fork()) < 0) //will not execute if pid is less than 0, basic error checking
cout << "Fork not implemented correctly.";
else if( pid == 0) //extant child
	if ((status == execvp(argc[0], argc)) < 0 )
	{
		cout << "\nInvalid command.\n";
		exit(255);
	}
	wait(&status); //waits for child function to complete
	int i = 0; 
	commands.add(argc[i]);
}
*/
//*********************************************************
//
// Main Function
//
//*********************************************************
int main( int argc, char *argv[] )
{
  // local variables
  int ii;
  char **toks;
  int retval;
  // initialize local variables
  ii = 0;
  toks = NULL;
  retval = 0;

  // main (infinite) loop
  while( true )
    {
      // get arguments
	  cout << "Shell>";
      toks = gettoks();
      //if( toks[0] != NULL )
		  // simple loop to echo all arguments
		for( ii=0; toks[ii] != NULL; ii++ )
			{
			  cout << "Argument " << ii << ": " << toks[ii] << endl;
			}
		if( !strcmp( toks[0], "exit" )) //exit function
		{
			break;
		}
		else if( !strcmp( toks[0], "hist" )) //history function
		{
			commands.display();
		}
	else
		exe(toks);
	}
	// return to calling environment
	return( retval );
}