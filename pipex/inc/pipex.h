#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include "../libft/libft.h"

typedef struct s_cmd{
	char	**cmd;
	char	*path;
	char	**path_env;
	int     error;
	int     pid;
	int     fdin;
}	t_cmd;

typedef struct s_information
{
	char	*infile;
	int     infilefd;
	char	*outfile;
	int     outfilefd;
	int		nb_cmds;
}	t_info;

void    parse_cmds(t_cmd *cmd, int runner, char **argv, char **env);
void	global_parse(t_info *global_info, char **argv, int argc);
void    do_exec(t_cmd *cmd, t_info *global_info);
char	**find_env_path(char **env);
void    wait_all(t_cmd *cmd, t_info *global_info);
void free_cmd(t_cmd *cmd, t_info *global_info);
void free_a_bit(t_info *global_info);



#endif