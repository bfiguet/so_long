/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:51:37 by bfiguet           #+#    #+#             */
/*   Updated: 2021/12/05 23:46:05 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t size)
{
	if (size == 0)
		return (0);
	while (size--)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int    main()
{
    char dest[] = "oldstring";
    char src[] = "newstring";

    printf("Before dest = %s, src = %s\n", dest, src);
    printf("After dest= %s/ %d : %d\n", dest, memcmp(dest, src, 10),
	ft_memcmp(dest, src, 10));

    return(0);
}*/
