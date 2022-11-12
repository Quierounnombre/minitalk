/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:15:54 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/10 15:43:50 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sact;

	if (set_sigh(&sact, sig_handler, SIGUSR1, SIGUSR2))
	{
		if (parse(argc, argv))
		{
			pid = ft_atoi(argv[1]);
			ft_printf("Escribo a: %d\n", pid);
			transform(argv[2], pid);
			while (1)
				pause();
		}
	}
}
