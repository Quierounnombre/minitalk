/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:16:57 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/10 15:47:55 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	full_byte(unsigned char *c);

void	sig_handler(int sig)
{
	static unsigned char	c;
	static int				i;

	if (sig == SIGUSR1)
		c = c << 1 | 1;
	else if (sig == SIGUSR2)
		c = c << 1;
	i++;
	if (i == 8)
	{
		full_byte(&c);
		i = 0;
		c = 0;
	}
}

static void	full_byte(unsigned char *c)
{
	if (g_client_info.is_pid_ready)
	{
		if (*c != 'v')
			g_client_info.pid_c = (g_client_info.pid_c * 10) + (*c - '0');
		else if (*c == 'v')
		{
			g_client_info.is_pid_ready = 0;
			ft_printf("El pid del cliente es: %d\n", g_client_info.pid_c);
		}
	}
	else
	{
		if (*c == 4)
			send_chars(g_client_info.num_chars, g_client_info.pid_c);
		else
		{
			ft_printf("%c", *c);
			g_client_info.num_chars += 1;
		}
	}
}
