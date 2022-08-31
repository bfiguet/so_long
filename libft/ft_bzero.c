/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:31:16 by bfiguet           #+#    #+#             */
/*   Updated: 2021/12/05 19:49:03 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
/*
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>
int    main(void)
{
   	char   str[100] = "Hello!, ca va?";
	size_t	n;
	n = 1;
    printf("'%s, %ld'/ %s : %s\n", str, n, bzero(str, n), ft_bzero(str, n));
    n = 9;
	printf("'%s, %ld'/ %s : %s\n", str, n, bzero(str, n), ft_bzero(str, n));
    n = 0;
	printf("'%s, %ld'/ %s : %s\n", str, n, bzero(str, n), ft_bzero(str, n));   
	return (0);
}*/
