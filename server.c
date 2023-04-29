/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:40:26 by anayef            #+#    #+#             */
/*   Updated: 2023/04/29 15:49:12 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n * -1);
	}
	else if (n < 10)
		ft_putchar((char)(n + '0'));
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}

void	b_to_t(char *binary)
{
	int		i;
	int		base;
	int		ascii;
	char	buffer[2];

	i = 0;
	while (binary[i] != '\0')
	{
		base = 128;
		ascii = 0;
		while (base > 0)
		{
			if (binary[i] == '1')
				ascii += base;
			i++;
			base /= 2;
		}
		buffer[0] = ascii;
		buffer[1] = '\0';
		write (1, buffer, 1);
	}
}

void	signal_handler(int sig)
{
	static int	i = 0;
	static char	binary[8];

	if (sig == SIGUSR1)
		binary[i] = '1';
	else if (sig == SIGUSR2)
		binary[i] = '0';
	i++;
	if (i == 8)
	{
		i = 0;
		b_to_t(binary);
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr (pid);
	signal (SIGUSR1, signal_handler);
	signal (SIGUSR2, signal_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
