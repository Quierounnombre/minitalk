/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:16:57 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/14 20:16:31 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	full_byte(int *i, unsigned char *c);

void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char	c;
	static int				i;
	void					*basura;

	if (!g_client_info.pid_c)
	{
		g_client_info.pid_c = info->si_pid;
		ft_printf("\nEl pid del cliente es: %d\n", g_client_info.pid_c);
	}
	if (sig == SIGUSR1)
		c = c << 1 | 1;
	else if (sig == SIGUSR2)
		c = c << 1;
	i++;
	if (c == 4 && i == 8)
	{
		full_byte(&i, &c);
		send_chars(g_client_info.num_chars, g_client_info.pid_c);
		g_client_info.pid_c = 0;
	}
	if (i == 8)
		full_byte(&i, &c);
	basura = ucontext;
	if (g_client_info.pid_c)
		kill(g_client_info.pid_c, SIGUSR2);
}

static void	full_byte(int *i, unsigned char *c)
{
	g_client_info.num_chars++;
	ft_printf("%c", *c);
	*i = 0;
	*c = 0;
}
