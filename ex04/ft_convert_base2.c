/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:56:03 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/25 15:42:22 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	if (*str == '\0')
		return (0);
	return (ft_strlen(str + sizeof(char)) + 1);
}

char	*ft_strcat(char *dest, char *src)
{
	int	dest_len;
	int	src_len;
	int	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	while (i < (src_len - 1))
	{
		dest[i + dest_len - 1] = src[i];
		i++;
	}
	dest[i + dest_len - 1] = '\0';
	return (dest);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

char	*ft_itoa_base(int nbr, char *base)
{
	int		size;
	int		negative;
	int		tmp;
	char	*str;

	negative = 0;
	size = 0;
	if (nbr < 0)
		negative = 1;
	tmp = nbr;
	tmp /= ft_strlen(base);
	while (tmp)
	{
		tmp /= ft_strlen(base);
		size++;
	}
	size = size + negative + 1;
	str = (char *) malloc(sizeof(char) * (size + 1));
	str[size] = '\0';
	ft_itoa_base2(&size, negative, base, &nbr);
	return (str);
}

void	ft_itoa_base2(int *size, int negative, char *base, int *nbr)
{
	if (negative == 1)
		str[0] = '-';
	while (size > negative)
	{
		str[size - 1] = base[ft_abs(nbr % ft_strlen(base))];
		*size--;
		*nbr /= ft_strlen(base);
	}
}
