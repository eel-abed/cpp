/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:58:27 by eel-abed          #+#    #+#             */
/*   Updated: 2025/04/08 18:07:43 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>


class PhoneBook {
	private:

	Contact contacts[8];
	int oldestContactIndex;
	int contactCount;

	void displayContactList() const;
	void displayContactDetails(int index) const;
	std::string truncateString(const std::string &str) const;

	public:

	PhoneBook();

	void addContact();
	void searchContact();
};

#endif
