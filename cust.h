void execute(char** cmd, int count[], string history[]){
                  pid_t pid;
                  int sts = 0;
                  if((pid = fork()) < 0){//create another process and test if it actually happened
                        printf("There was a fork error. Terminating process.");//if not this message will be displayed and the function closed
                  }
                  else if( pid == 0){//if child execute the following
                        if( (sts = execvp(cmd[0], cmd)) < 0){//execute the cmd
                                printf("\nCould not find the command: %s\n", cmd[0]);//print message if there was an error
                                exit(127);//exit with status of 127
                        }
                  }
                  wait(&sts);//wait for child and read exit status
                  if(WEXITSTATUS(sts) != 0){//if exit status is not zero, print the following and add to failed cmd count
                        printf("\nThe exit status of the failed command, %s, is %d\n", cmd[0], WEXITSTATUS(sts));
                        count[1]++;
                  }
                  else{
                        count[0]++;//if no error add to successful cmd count
                  }
                  addHistory(cmd, history);//add cmd to history
}

//char** cmd is a pointer to a set of pointers to char/toks
while( true )
      {
         //  get arguments
              printf("cmd # %d:>", (cmdCount[0] + cmdCount[1] + 1)); //command line prompt
              toks = gettoks();
              if(toks[0] == NULL){ //if nothing was entered, blank line will be printed
                        printf("\n");
              }
              else if( !strcmp( toks[0], "exit")) //if exit was entered, the system will display the end info and break from the loop to exit the program
              {
                        exitDisplay(sigCount, cmdCount);
                        break;
              }