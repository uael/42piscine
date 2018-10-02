#include <string>
#include <ostream>
#include <iostream>

namespace zob {

	std::string truncate(std::string s) {
		if (s.size() < 10)
			s.insert(s.begin(), 10 - s.length(), ' ');
		else if (s.size() > 10)
			s[9] = '.';
		s.resize(10);
		return s;
	}

	class Stalk {
	private:
		std::string firstName, lastName, nickname, login, postalAddr, emailAddr,
			phoneNumber, birthdayDate, favoriteMeal, underwearColor,
			darkestSecret;
	public:
		Stalk() {}

		void setFirstName(const std::string &firstName) {
			Stalk::firstName = firstName;
		}

		void setLastName(const std::string &lastName) {
			Stalk::lastName = lastName;
		}

		void setNickname(const std::string &nickname) {
			Stalk::nickname = nickname;
		}

		void setLogin(const std::string &login) {
			Stalk::login = login;
		}

		void setPostalAddr(const std::string &postalAddr) {
			Stalk::postalAddr = postalAddr;
		}

		void setEmailAddr(const std::string &emailAddr) {
			Stalk::emailAddr = emailAddr;
		}

		void setPhoneNumber(const std::string &phoneNumber) {
			Stalk::phoneNumber = phoneNumber;
		}

		void setBirthdayDate(const std::string &birthdayDate) {
			Stalk::birthdayDate = birthdayDate;
		}

		void setFavoriteMeal(const std::string &favoriteMeal) {
			Stalk::favoriteMeal = favoriteMeal;
		}

		void setUnderwearColor(const std::string &underwearColor) {
			Stalk::underwearColor = underwearColor;
		}

		void setDarkestSecret(const std::string &darkestSecret) {
			Stalk::darkestSecret = darkestSecret;
		}

		void print() {
			std::cout << "first name:      " << firstName << std::endl
			          << "last name:       " << lastName << std::endl
			          << "nickname:        " << nickname << std::endl
			          << "login:           " << login << std::endl
			          << "postal address:  " << postalAddr << std::endl
			          << "email address:   " << emailAddr << std::endl
			          << "phone number:    " << phoneNumber << std::endl
			          << "birthday date:   " << birthdayDate << std::endl
			          << "favorite meal:   " << favoriteMeal << std::endl
			          << "underwear color: " << underwearColor << std::endl
			          << "darkest secret:  " << darkestSecret << std::endl;
		}

		void shortPrint() {
			std::cout << truncate(firstName) << '|'
			          << truncate(lastName) << '|'
			          << truncate(nickname) << std::endl;
		}
	};
}
