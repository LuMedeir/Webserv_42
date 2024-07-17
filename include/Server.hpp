/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:40:41 by bmoretti          #+#    #+#             */
/*   Updated: 2024/07/13 14:14:47 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include "common.hpp"
# include "Request.hpp"
# include "Response.hpp"
# include "Config.hpp"

class Server
{
public:
	Server(const std::string &address, int port);
	~Server();

  void run();

private:
  /* Server initialization */
  void _initServer();
  void handleConnection(int client_fd);
  void handleEvents();
  void setNonBlocking(int fd);

  std::string _address;
  int _port;
  int _server_fd;
  int _epoll_fd;
  struct epoll_event _events[MAX_EVENTS];
};

#endif
