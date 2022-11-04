/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:51:30 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/04 15:03:57 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main(void)
{
	struct sigaction	sact;
	int					i;

	i = 0;
	ft_printf("Mi ID es: %d\n", getpid());
	if (set_sigh(&sact, sig_handler, SIGUSR1))
	{
		if (set_sigh(&sact, sig_handler, SIGUSR2))
		{
			while (1)
			{
			}
		}
	}
}
