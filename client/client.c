/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 19:08:47 by rpassafa          #+#    #+#             */
/*   Updated: 2017/02/17 19:08:50 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int					sockfd;
	char				recvline[100];
	char 				str[100];
	struct sockaddr_in	servaddr;

	while (1)
	{
		sockfd = socket(AF_INET, SOCK_STREAM, 0);
		servaddr.sin_family = AF_INET;
		servaddr.sin_port = htons(22000);
		inet_pton(AF_INET, "127.0.0.1", &(servaddr.sin_addr));
		connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
		bzero(str, 100);
		bzero(recvline, 100);
		printf("%s\n", "write echo phrase");
		scanf("%s", str);
		write(sockfd, str, strlen(str));
		read(sockfd, recvline, 100);
		write(1, recvline, strlen(recvline));
		write(1,"\n",1);
	}
}
