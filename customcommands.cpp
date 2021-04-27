#include <iostream>
//exit

//hist
void hist()
{
if(strcmp(argc[0], "history") == 0)
    {
       for(int n = 0; n < 10 ; n++) 
        {
        if(cmdsHistory[n] != NULL)
			printf(n, cmdsHistory[n]);
        }
    }
}
//r
string r()
{
	if(strcmp(argc[1] == 0)
		 cmdsHistory[*argc[1]];
	 else
		 cmdsHistory[0];
}
//n of r