/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 19:11:10 by rpassafa          #+#    #+#             */
/*   Updated: 2017/02/17 19:12:48 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	main(void)
{
	char				str[100];
	int					listen_fd;
	int					comm_fd;
	struct sockaddr_in	servaddr;

	listen_fd = socket(AF_INET, SOCK_STREAM, 0);
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htons(INADDR_ANY);
	servaddr.sin_port = htons(22000);
	bind(listen_fd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	listen(listen_fd, 10);
	while (1)
	{
		bzero(str, 100);
		comm_fd = accept(listen_fd, (struct sockaddr*)NULL, NULL);
		read(comm_fd, str, 100);
		//logic
		printf("%s\n", str);
		write(comm_fd, str, strlen(str));
	}
}
