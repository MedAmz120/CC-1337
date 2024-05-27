/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:29:26 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/20 13:33:49 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string.h>

class Brain {
  private:
  std::string ideas[100];

  public:
  Brain();
  ~Brain();
  Brain (const Brain& copie);
  Brain& operator=(const Brain& copie);
};


#endif