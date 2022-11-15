/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:07:30 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/15 18:19:24 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../libft_def/libftprintf.h"

typedef struct s_client
{
	pid_t			pid_c;
	int				num_chars;
}				t_client;

t_client	g_client_info;

int		set_sigh(struct sigaction *sact, int sig, int sig2);
void	sig_handler(int sig, siginfo_t *info, void *ucontext);
void	send_chars(int i, pid_t pid);
void	init_global(void);

#endif