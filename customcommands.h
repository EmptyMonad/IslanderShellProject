function hist()
{
if(strcmp(argc[0], "history") == 0)
    {
       for(int n = 0; n<10 ; n++) 
        {
        if(cmdsHistory[n] != NULL)
			printf(n, cmdsHistory[n]);
        }
    }
}
void exe(char** argc)
{
pid_t pid;
int i = 0;
if ((pid = fork()) < 0) //will not execute if pid is less than 0, failsafe error checking
cout << "Fork not implemented correctly.";
else if( pid == 0) //extant child
	if ((sts == execvp(argc[0], argc)) < 0 )
	{
		cout << "\nInvalid command.\n";
		break;
	}
		
