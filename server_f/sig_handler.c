/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:16:57 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/14 14:45:51 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	full_byte(unsigned char *c);
static void	get_malloc_size(unsigned char *c);

void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char	c;
	static int				i;
	void					*basura;

	g_client_info.pid_c = info->si_pid;
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
	basura = ucontext;
}

static void	full_byte(unsigned char *c)
{
	if (g_client_info.is_malloc_ready)
		get_malloc_size(c);
	else
	{
		if (*c == 4)
		{
			send_chars(g_client_info.num_chars, g_client_info.pid_c);
			ft_printf("%s", g_client_info.s);
			free(g_client_info.s);
		}
		else
		{
			g_client_info.s[g_client_info.s_pos] = (char)*c;
			g_client_info.s_pos += 1;
			g_client_info.num_chars += 1;
		}
	}
}

static void	get_malloc_size(unsigned char *c)
{
	if (*c != 'v')
	{
		g_client_info.malloc_size = (g_client_info.malloc_size * 10);
		g_client_info.malloc_size += (*c - '0');
	}
	else if (*c == 'v')
	{
		g_client_info.is_malloc_ready = 0;
		g_client_info.s = (char *)ft_calloc(g_client_info.malloc_size + 1,
				sizeof(char));
		if (!g_client_info.s)
		{
			ft_printf("Error al almacenar memoria");
			exit(1);
		}
		ft_printf("\nEl pid del cliente es: %d\n", g_client_info.pid_c);
	}
}
