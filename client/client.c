/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:15:54 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/04 14:58:52 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (parse(argc, argv))
	{
		pid = ft_atoi(argv[1]);
		ft_printf("Escribo a: %d\n", pid);
		kill(pid, SIGUSR1);
	}
}
