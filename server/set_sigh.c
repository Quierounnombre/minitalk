/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sigh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:05:26 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/07 20:25:30 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int	set_sig(struct sigaction *sact, int signal);

int	set_sigh(struct sigaction *sact, void (*f)(int), int sig, int sig2)
{
	if (sigemptyset(&sact->sa_mask) == -1)
	{
		printf("ERROR: sigemptyset ha fallado");
		return (0);
	}
	sact->sa_flags = 0;
	sact->sa_handler = f;
	if (!set_sig(sact, sig))
		return (0);
	if (!set_sig(sact, sig2))
		return (0);
	return (1453);
}

static int	set_sig(struct sigaction *sact, int signal)
{
	if (sigaddset(&sact->sa_mask, signal) == -1)
	{
		printf("ERROR: sigaddset ha fallado");
		return (0);
	}
	if (sigaction(signal, sact, NULL) == -1)
	{
		printf("ERROR: sigaction ha fallado");
		return (0);
	}
	return (5555);
}

/* sigaddset no es necesario a priori invstiga más ^^*/
