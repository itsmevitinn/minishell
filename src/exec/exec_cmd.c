/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vitor <Vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:59:16 by vsergio           #+#    #+#             */
/*   Updated: 2022/12/22 00:05:53 by Vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exec_cmds(t_cmd_info *data, t_var_lst **env_lst)
{
	data->pid = malloc(sizeof(int) * data->qty);
	while(data->lst_cmd)
	{
		if (!exec_builtin_cmd(data->lst_cmd, env_lst, data))
			exec_bin_cmd(data->lst_cmd, data);
		data->lst_cmd = data->lst_cmd->next;
	}
}