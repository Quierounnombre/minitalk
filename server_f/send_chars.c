/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_chars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:51:08 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/14 14:32:00 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	send(char c, pid_t pid);

void	send_chars(int i, pid_t pid)
{
	char	*s;
	char	*first_s;

	ft_printf("\nEscribo a: %d\nQue ha enviado un total de %d bytes\n", pid, i);
	s = ft_itoa(i);
	if (s)
	{
		first_s = s;
		while (*s)
		{
			send(*s, pid);
			s++;
			usleep(100);
		}
		write(1, "\n", 1);
		free(first_s);
		send(4, pid);
		init_global();
	}
	else
		ft_printf("Ha fallado la reserva de memoria\n");
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
