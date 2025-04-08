/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:47:20 by eel-abed          #+#    #+#             */
/*   Updated: 2025/04/01 18:24:04 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

// Classe Contact pour stocker les informations d'un contact
class Contact
{
private:
	// Variables membres privées pour stocker les informations
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	Contact();

	void setFirstName(const std::string &firstName);
	void setLastName(const std::string &lastName);
	void setNickName(const std::string &nickName);
	void setPhoneNumber(const std::string &phoneNumber);
	void setDarkestSecret(const std::string &darkestSecret);

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;

	bool isEmpty() const;
};

#endif
