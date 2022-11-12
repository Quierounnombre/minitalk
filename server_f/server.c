/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:51:30 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/10 13:05:39 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main(void)
{
	struct sigaction	sact;

	g_client_info.is_pid_ready = 1810;
	g_client_info.num_chars = 0;
	g_client_info.pid_c = 0;
	ft_printf("Mi ID es: %d\n", getpid());
	if (set_sigh(&sact, sig_handler, SIGUSR1, SIGUSR2))
	{
		while (1)
			pause();
	}
}
