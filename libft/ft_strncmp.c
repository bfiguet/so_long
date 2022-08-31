/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:30:19 by bfiguet           #+#    #+#             */
/*   Updated: 2021/12/07 18:02:24 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s2 && *s1 == *s2 && n - 1 > 0)
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
/*
#include <stdio.h>
#include <string.h>
int    main()
{
    char    *s1;
    char    *s2;
    int n;
    
    s1 = "Hello toi";
    s2 = "Hello moi";
    n = 5;
    printf("%s : s2 %s\n", s1, s2);
    printf("%d/ %d : %d\n", n, strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
    n = 7;
    printf("%d/ %d : %d\n", n, strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
    n = 10;
    printf("%d/ %d : %d\n", n, strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
    n = 0;
    printf("%d/ %d : %d\n", n, strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
    return (0);
}*/
