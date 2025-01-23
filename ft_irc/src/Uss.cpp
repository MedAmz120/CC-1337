/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychihab <ychihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:20:15 by ychihab           #+#    #+#             */
/*   Updated: 2025/01/23 21:30:12 by ychihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/User.hpp"

User::User() : socket(-1), isOperator(false) {}

User::User(const std::string &nick, const std::string &user, const std::string &host, int sock)
    : nickname(nick), username(user), hostname(host), socket(sock), isOperator(false) {}

void User::joinChannel(const std::string &channelName)
{
    channels.push_back(channelName);
}

void User::leaveChannel(const std::string &channelName)
{
    std::vector<std::string>::iterator it = std::find(channels.begin(), channels.end(), channelName);
    if (it != channels.end())
    {
        channels.erase(it);
    }
}

bool User::isInChannel(const std::string &channelName) const
{
    return std::find(channels.begin(), channels.end(), channelName) != channels.end();
}