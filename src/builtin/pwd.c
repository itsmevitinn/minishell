/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:49:00 by Vitor             #+#    #+#             */
/*   Updated: 2023/01/02 21:24:08 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	pwd(t_cmd_lst *cmd)
{
	char	*pwd;
	int		status;

	if (!check_heredoc(cmd))
		return (0);
	cmd->pid = fork();
	if (!cmd->pid)
	{
		pwd = getcwd(NULL, 0);
		ft_putstr_fd(pwd, cmd->output);
		ft_putchar_fd('\n', cmd->output);
		free(pwd);
		exit(0);
	}
	waitpid(cmd->pid, &status, 0);
	g_exit_status = WEXITSTATUS(status);
	return (1);
}
