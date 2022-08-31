/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:36:23 by bfiguet           #+#    #+#             */
/*   Updated: 2021/12/07 17:20:43 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void	*b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)b;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
/*#include <stdio.h>
#include <string.h>
int    main()
{
    char    str[50] = "Hello";
    printf("'%s ->#, 1' %s : %s\n", str, memset(str, '#', 1),
	ft_memset(str, '#', 1));
    printf("'%s ->&, 3' %s : %s\n", str, memset(str, '&', 3),
	ft_memset(str, '&', 3));
    printf("'%s ->8, 5' %s : %s\n", str, memset(str, '8', 5),
	ft_memset(str, '8', 5));
    return (0);
}*/
