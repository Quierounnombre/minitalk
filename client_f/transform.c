/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:51:08 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/15 18:20:32 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	send(char c, pid_t pid);

void	transform(char *s, pid_t pid)
{
	ft_printf("Mi pid es: %d\n\n", getpid());
	while (*s != '\0')
	{
		send(*s, pid);
		s++;
	}
	send(4, pid);
}

static void	send(char c, pid_t pid)
{
	unsigned char	pos;

	pos = 1 << 7;
	while (pos)
	{
		if (c & pos)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		pos = pos >> 1;
		usleep(100);
	}
}
