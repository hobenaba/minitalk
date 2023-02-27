/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:48:04 by hobenaba          #+#    #+#             */
/*   Updated: 2023/02/27 14:38:48 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	my_countnbr(int n)
{
	int	j;

	j = 0;
	if (n <= 0)
		j++;
	while (n != 0)
	{
		n /= 10;
		j++;
	}
	return (j);
}

int	ft_check_args(int nb, char *str)
{
	int	i;

	i = 0;
	if (nb == 0
		|| ft_strlen(str) != my_countnbr(nb))
	{
		while (str[i])
		{	
			if (!(str[i] >= '0' && str[i] <= '9'))
				return (1);
			i++;
		}
	}
	return (0);
}
