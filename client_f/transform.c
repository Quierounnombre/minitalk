/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:51:08 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/10 15:25:42 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	send(char c, pid_t pid);

void	transform(char *s, pid_t pid)
{
	pid_t	my_pid;
	char	*pid_s;
	char	*start_pid_s;

	my_pid = getpid();
	ft_printf("Mi pid es: %d\n", my_pid);
	pid_s = ft_itoa(my_pid);
	if (pid_s)
	{
		start_pid_s = pid_s;
		while (*pid_s != '\0')
		{
			send(*(pid_s++), pid);
		}
		free(start_pid_s);
		send('v', pid);
		while (*s != '\0')
		{
			send(*s, pid);
			s++;
		}
		send(4, pid);
	}
	else
		ft_printf("Ha fallado la reserva de memoria");
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
