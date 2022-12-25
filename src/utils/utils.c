/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vitor <Vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:23:45 by gcorreia          #+#    #+#             */
/*   Updated: 2022/12/25 14:45:52 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void print_matrix(char **cmd_args)
{
	int i;

	i = 0;
	while (cmd_args[i])
	{
		printf("[%i] %s ", i, cmd_args[i]);
		i++;
	}
	printf("\n");
}

void	close_all_pipes(t_cmd_info *data)
{
	int i;

	i = -1;
	while(++i < (data->qty - 1))
	{
		close(data->pipes[i][0]);
		close(data->pipes[i][1]);
	}
}