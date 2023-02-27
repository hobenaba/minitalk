/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:26:50 by hobenaba          #+#    #+#             */
/*   Updated: 2023/02/26 18:52:50 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	manage_errors(int a)
{
	if (a == 1)
		ft_printf ("Error\nNot enough arguments");
	else if (a == 2)
		ft_printf("Error\nThe Pid is invalid");
	exit (1);
}

void	change_to_binary(char c, int *arr)
{
	int	n;
	int	j;

	n = (int)c;
	j = 7;
	while (n)
	{
		if (n % 2 == 1)
			arr[j] = 1;
		else
			arr[j] = 0;
		n /= 2;
		j--;
	}
	while (j != -1)
	{
		arr[j] = 0;
		j--;
	}
}

void	check_array(int *arr, int pid)
{
	int	i;
	int	a;

	i = 0;
	while (i <= 7)
	{
		if (arr[i] == 0)
			a = kill(pid, SIGUSR1);
		else if (arr[i] == 1)
			a = kill(pid, SIGUSR2);
		usleep (200);
		if (a == -1)
			manage_errors(2);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	*arr;
	int	j;

	j = 0;
	if (ac != 3)
		manage_errors(1);
	pid = ft_atoi(av[1]);
	if (pid == 0 || pid == -1 || ft_check_args(pid, av[1]) == 1)
		manage_errors(2);
	arr = malloc (sizeof(int) * 8);
	while (av[2][j])
	{
		change_to_binary(av[2][j], arr);
		check_array(arr, pid);
		j++;
		usleep (300);
	}
	change_to_binary('\n', arr);
	check_array(arr, pid);
	free(arr);
	return (0);
}
