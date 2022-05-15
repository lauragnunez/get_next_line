/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagarcia <lagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:29:05 by lagarcia          #+#    #+#             */
/*   Updated: 2022/05/11 13:24:24 by lagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#define BUFF_SIZE 3

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_buff
{
	int buff_size;
	char buff[BUFF_SIZE];
} t_buff;

typedef struct s_list_fd
{
	int fd;
	struct s_buff *buff;
	struct s_list_fd *next;
} t_list_fd;

char *get_next_line(int fd);

#endif