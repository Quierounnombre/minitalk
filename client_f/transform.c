/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:51:08 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/14 16:53:12 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	send(char c, pid_t pid);

void	transform(char *s, pid_t pid, int len)
{
	char	*len_s;
	char	*start_len_s;

	ft_printf("Mi pid es: %d\n", getpid());
	len_s = ft_itoa(len);
	if (len_s)
	{
		start_len_s = len_s;
		while (*len_s != '\0')
			send(*(len_s++), pid);
		free(start_len_s);
		send('v', pid);
		while (*s != '\0')
		{
			send(*s, pid);
			s++;
		}
		send(4, pid);
	}
	else
	{
		ft_printf("Ha fallado la reserva de memoria");
		exit(1);
	}
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
