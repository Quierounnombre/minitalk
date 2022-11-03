/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:20:08 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/03 18:54:57 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	parse_log(int argc, int p_case);

int	parse(int argc, char **argv)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(argv[1]);
	if (argc != 2)
	{
		parse_log(argc, 0);
		return (0);
	}
	while (argv[1] != '\0' && i != len)
	{
		if ((ft_isdigit(argv[1][i])) == 0)
		{
			ft_printf("%c\n", argv[1][i]);
			parse_log(argc, 1);
			return (0);
		}
		i++;
	}
	return (i);
}

static void	parse_log(int argc, int p_case)
{
	if (p_case == 0)
	{
		if (argc > MAX_ARGS)
			ft_printf("Me has pasado más de 2 argumentos");
		else
			ft_printf("Me has pasado menos de 2 argumentos");
	}
	else if (p_case == 1)
		ft_printf("Me has pasado algo que no era un numero");
	else
		ft_printf("No tengo ni idea de que ha fallado");
}
