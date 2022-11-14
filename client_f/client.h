/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:24:31 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/14 16:40:03 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "../libft_def/libftprintf.h"

# define MAX_ARGS 3

int		parse(int argc, char **argv);
void	transform(char *s, pid_t pid, int len);
int		set_sigh(struct sigaction *sact, void (*f)(int), int sig, int sig2);
void	sig_handler(int sig);

#endif