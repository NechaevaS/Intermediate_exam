/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:21:17 by snechaev          #+#    #+#             */
/*   Updated: 2019/08/09 14:02:51 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int str_len(char *s)
{
	int i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int check_sing(char *s)
{
	if (s[0] == '-')
		return (1);
	return (0);
}
void fill_str(char *s1, char *s2, int len)
{
	int i = 0;
	while (s[i])
	{
		s[i] = 0;
		i++;
	}
}

int	main (int argc, char **argv)
{
	int in_mind = 0;
	char *s1;
	char *s2;
	char *sum;
	int len1;
	int len2;
	int len_sum;
	int sign1;
	int sign2;

	sign1 = check_sing(argv[1]);
	sign2 = check_sing(argv[2]);
	len1 = str_len(argv[1]);
	len2 = str_len(argv[2]);
	if (sign1)
		len1--;
	if (sign2)
		len2--;

	if (len1 > len2)
		len_sum = len1;
	else
		len_sum = len2;
	s1 = (char *)malloc(sizeof(char) * len_sum + 2);
	s2 = (char *)malloc(sizeof(char) * len_sum + 2);
	sum = (char *)malloc(sizeof(char) * len_sum + 2);

	if (sign1 || sign2)

}