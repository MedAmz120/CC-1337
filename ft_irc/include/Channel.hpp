/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychihab <ychihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:57:22 by ychihab           #+#    #+#             */
/*   Updated: 2025/01/23 21:07:56 by ychihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <string>
#include <vector>
#include <map>
#include "Client.hpp"

class Channel {
private:
    std::string name;
    std::vector<User*> users;
    std::vector<User*> operators;
    std::string topic;
    std::string password;
    int userLimit;
    bool isInviteOnly;
    bool isTopicRestricted;
    User* findUserByNickname(const std::string& nickname);
    static std::map<std::string, Channel*> channels;
    
public:
    Channel();
    Channel(const std::string& name);
    static Channel* createChannel(const std::string& name, User* creator);
    static Channel* getChannel(const std::string& name);
    static bool deleteChannel(const std::string& name);
    bool addUser(User* user);
    void removeUser(User* user);
    bool isUserInChannel(User* user) const;
    void addOperator(User* user);
    void removeOperator(User* user);
    bool isOperator(User* user) const;
    void broadcastMessage(const std::string& message);
    void setInviteOnly(bool inviteOnly);
    void setPassword(const std::string& password);
    void setUserLimit(int limit);
    std::string getName() const;
    std::string getTopic() const;
    std::vector<User*> getUsers() const;
    std::vector<User*> getOperators() const;
    void kickUser(User* operatorUser, User* targetUser, const std::string& reason);
    void inviteUser(User* operatorUser, User* targetUser);
    void setTopic(User* user, const std::string& newTopic);
    void getTopic(User* user);
    void setMode(User* user, const std::string& mode, const std::string& argument = "");

};

#endif