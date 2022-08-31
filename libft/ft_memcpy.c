/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:28:45 by bfiguet           #+#    #+#             */
/*   Updated: 2022/01/10 11:28:55 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;

	i = 0;
	if ((n == 0) || (dst == src))
		return (dst);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
/*#include <string.h>
#include <stdio.h>
int    main()
{
    char dest[] = "oldstring";
    char src[] = "newstring";

    printf("Before dest = %s, src = %s\n", dest, src);
    printf("After dest= %s/ %s : %s\n", dest, memcpy(dest, src, 10),
	ft_memcpy(dest, src, 10));

    return(0);
}*/
