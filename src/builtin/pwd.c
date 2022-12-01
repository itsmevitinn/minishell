/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vitor <vsergio@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:49:00 by Vitor             #+#    #+#             */
/*   Updated: 2022/11/30 22:50:06 by Vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/minishell.h"

void	pwd(int fd)
{
	char *pwd;
	int i;

	i = 0;
	pwd = getcwd(NULL, 0);
	while(pwd[i])
		write(fd, &pwd[i++], 1);
	write(fd, "\n", 1);
	free(pwd);
}
