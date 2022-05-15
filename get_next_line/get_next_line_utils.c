/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagarcia <lagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:48:06 by lagarcia          #+#    #+#             */
/*   Updated: 2022/05/11 13:25:51 by lagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

static size_t getstrlen(const char *str)
{
	size_t len;

	len = 0;
	if (!str)
		return 0;
	while (str[len])
		len++;
	return (len);
}

static size_t scan_newline_pos(const char *buf)
{
	size_t pos;

	pos = 0;

	while (pos < BUFFER_SIZE)
	{
		if (*buf == '\n')
			return (pos);
		pos++;
		buf++;
	}
	return (BUFFER_SIZE);
}

static char *join(const char *fst, const char *sec, size_t size)
{
	size_t fst_len;
	size_t max;
	char *tmp;
	size_t i;

	fst_len = getstrlen(fst);
	max = (fst_len + size + 1);
	tmp = malloc(sizeof(char) * max);
	if (!tmp)
		return (NULL);

	i = 0;
	while (i < fst_len)
	{
		tmp[i] = fst[i];
		i++;
	}

	i = 0;
	while (i < size)
	{
		tmp[i + first_len] = sec[i];
		i++;
	}

	tmp[max - 1] = '\0';

	return (tmp);
}
