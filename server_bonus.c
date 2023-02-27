/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 09:26:19 by hobenaba          #+#    #+#             */
/*   Updated: 2023/02/27 14:37:07 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	power(int base)
{
	if (base < 0)
		return (0);
	else if (base == 0)
		return (1);
	return (2 * power(base - 1));
}

int	back_to_number(int *arr)
{
	int	nb;
	int	i;
	int	base;

	nb = 0;
	base = 7;
	i = 0;
	while (i <= 7)
	{
		if (arr[i] == 1)
			nb += power(base);
		base--;
		i++;
	}
	return (nb);
}

void	ft_bonus(int nb, siginfo_t *info)
{
	if (nb == 0)
	{
		kill (info->si_pid, SIGUSR1);
		ft_printf("\n");
	}
	else
		ft_printf("%c", nb);
}

void	sig_handler(int signal, siginfo_t *info, void *contest)
{
	static int	*arr;
	static int	i;
	static int	count;
	int			nb;

	(void)contest;
	if (count++ == 0)
		arr = malloc(sizeof(int) * 8);
	if (signal == SIGUSR1)
		arr[i++] = 0;
	else if (signal == SIGUSR2)
		arr[i++] = 1;
	if (i == 8)
	{
		nb = back_to_number(arr);
		ft_bonus(nb, info);
		i = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("%d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
