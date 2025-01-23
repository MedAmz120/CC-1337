#include "../include/Client.hpp"

Client::Client() {}

Client::Client(int fd) {
    client_fd = fd;
    nick      = "NULL";
    user      = "NULL";
    ip        = "NULL";
    real_name = "NULL";
    servername= "NULL";
    hostname  = "NULL";
    auth_not  = 0;
    session_duration = 0;
    joinedchannel_not = false;
}

Client::Client(const Client& copie) {
    if (this != &copie)
        return ;
}

Client::~Client() {}

int Client::getClientFd() const {
    return this->client_fd;
}

void    Client::SetAuth () {
    session_duration = true;
    auth_not = 1;
}

bool Client::getAuth() const {
    return this->auth_not;
}

void    Client::SetUserName (const std::string& username_it) {
    this->user = username_it;
}

void    Client::SetNickName (const std::string& nickname_it) {
    this->nick = nickname_it;
}

void    Client::SetRealName (const std::string& realname_it) {
    this->real_name = realname_it;
}

void    Client::SetHostName(const std::string& hostname_it) {
    this->hostname = hostname_it;
}

void    Client::SetServerName(const std::string& servername_it) {
    this->servername = servername_it;
}

const std::string& Client::getUser() const {
    return this->user;
}

const   std::string& Client::getNickname() const {
    return this->nick;
}