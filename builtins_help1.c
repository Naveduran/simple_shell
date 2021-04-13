#include "shell.h"

int builtin_cd_help(data_of_program *data)
{
char description[] = "\n\
cd:\tcd [dir]\n\
	Change the shell working directory.\n\n\
\
	If no argument is given to cd the command will be interpreted\n\
	as cd $HOME.\n\
	if the argument is - (cd -), the command will be interpreted\n\
	as cd $OLDPWD.\n";
	_print(description);
	return (1);
}
