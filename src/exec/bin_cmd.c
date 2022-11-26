/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vitor <vsergio@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:50:59 by Vitor             #+#    #+#             */
/*   Updated: 2022/11/25 23:16:04 by Vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/minishell.h"

void	run_bin_cmd(char *command)
{
	char		**splitted_paths;
	char		**arguments;
	int			countargs;

	countargs = 0;
	arguments = ft_split_quotes(command, ' ');
	while (arguments[countargs++])
		arguments[countargs] = ft_strtrim_edges(arguments[countargs], "'\"");
	splitted_paths = ft_split(getenv("PATH"), ':');
	exec_bin_cmd(splitted_paths, arguments);
}

void	exec_bin_cmd(char **paths, char **arguments)
{
	char	*path_completed;
	int		i;

	i = 0;
	if (ft_strncmp(arguments[0], "history", 7) == 0)
	{
		printf("encontrou\n");
		execve(arguments[0], arguments, NULL);
	}
	while (paths[i++])
	{
		path_completed = ft_strjoin(paths[i], "/", 1);
		path_completed = ft_strjoin(path_completed, arguments[0], 1);
		if (!access(path_completed, F_OK | X_OK))
			execve(path_completed, arguments, NULL);
		free(path_completed);
	}
	free(paths);
	printf("zsh: command not found (fake)\n");
	// error_msg("zsh: command not found", 127);
}