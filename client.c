/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:44:41 by anayef            #+#    #+#             */
/*   Updated: 2023/04/29 16:38:47 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == 32
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
		sign = -1;
		i++;
	}
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	return (res * sign);
}

void	t_to_b(char *s, int pid)
{
	int	i;
	int	base;
	int	ascii;

	i = 0;
	while (s[i] != '\0')
	{
		base = 128;
		ascii = s[i];
		while (base > 0)
		{
			if (ascii >= base)
			{
				kill(pid, SIGUSR1);
				ascii -= base;
			}
			else
				kill (pid, SIGUSR2);
			base /= 2;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
		return (0);
	if (!ft_isdigit(ft_atoi(argv[1])))
		return (0);
	pid = ft_atoi (argv[1]);
	t_to_b(argv[2], pid);
}
