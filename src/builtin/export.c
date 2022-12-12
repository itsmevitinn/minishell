/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vitor <Vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:08:25 by gcorreia          #+#    #+#             */
/*   Updated: 2022/12/11 22:52:11 by Vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void print_error(char *cmd, int fd);
static void parse_cmd(char *cmd);
static void print_error(char *cmd, int fd);

void export(char **cmd, t_var_lst *env_lst, int fd)
{
	char **temp;

	cmd++;
	while (*cmd)
	{
		parse_cmd(*cmd);
		if (ft_strchr(*cmd, '='))
		{
			temp = split_env(*cmd);
			*(temp + 1) = ft_strtrim_edges(*(temp + 1), "\"");
			if (!temp)
				print_error(*cmd, fd);
			else if (is_env(*temp, env_lst))
				change_content(*temp, *(temp + 1), env_lst);
			else
				ft_varadd_back(&env_lst, ft_var_new(*temp, *(temp + 1)));
			free(temp);
		}
		cmd++;
	}
}

static void parse_cmd(char *cmd)
{
	char *aux;

	while (*cmd && *cmd != '=')
	{
		if (*cmd == '\'' || *cmd == '\"')
		{
			aux = cmd;
			while (*(aux + 1))
			{
				*aux = *(aux + 1);
				aux++;
			}
			*aux = '\0';
		}
		else
			cmd++;
	}
}

static void print_error(char *cmd, int fd)
{
	ft_putstr_fd("export: `", fd);
	ft_putstr_fd(cmd, fd);
	ft_putstr_fd("': not a valid identifier\n", fd);
}