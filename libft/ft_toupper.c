/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:09:27 by bfiguet           #+#    #+#             */
/*   Updated: 2021/12/02 12:12:09 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>
#include <xlocale.h>
int    main()
{
    int c;
    
    c = 'H';
    printf("%d/ %d : %d\n", c, toupper(c), ft_toupper(c));
    c = 'e';
    printf("%d/ %d : %d\n", c, toupper(c), ft_toupper(c));
    c = '4';
    printf("%d/ %d : %d\n", c, toupper(c), ft_toupper(c));
    return (0);
}*/
