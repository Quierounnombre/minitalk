/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sigh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:05:26 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/14 14:34:27 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int	set_sig(struct sigaction *sact, int signal);

int	set_sigh(struct sigaction *sact, int sig, int sig2)
{
	if (sigemptyset(&sact->sa_mask) == -1)
	{
		printf("ERROR: sigemptyset ha fallado");
		return (0);
	}
	sact->sa_flags = SA_SIGINFO;
	sact->__sigaction_u.__sa_sigaction = &sig_handler;
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
