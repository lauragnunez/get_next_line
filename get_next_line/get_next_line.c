/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagarcia <lagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:00:18 by lagarcia          #+#    #+#             */
/*   Updated: 2022/05/11 13:18:57 by lagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char *get_next_line(int fd)
{
	static char *new_string = NULL;
	char buffer[BUFFER_SIZE];

	size_t readed = 0;
	size_t nl_pos = 0;

	while (1)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		nl_pos = scan_newline_pos(buffer);

		if (!readed)
		{
			if (new_string)
			{
				char *tmp = new_string;
				new_string = NULL;
				return tmp;
			}
			else
				return NULL;
		}

		char *tmp = new_string;
		new_string = join(tmp, buffer, nl_pos);
		if (!new_string)
			return tmp;

		if (nl_pos < BUFFER_SIZE)
		{
			tmp = new_string;
			new_string = join(NULL, buffer + nl_pos, BUFFER_SIZE - nl_pos);
			return tmp;
		}
	}
}
