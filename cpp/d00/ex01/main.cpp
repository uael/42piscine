#include <string>

#include "stalk.hpp"

#define MAX_STALK (8)

static const struct {
	const char *p; void (zob::Stalk::*setter)(const std::string &);
} asks[] = {
	{ "first name ?      ", &zob::Stalk::setFirstName, },
	{ "last name ?       ", &zob::Stalk::setLastName, },
	{ "nickname ?        ", &zob::Stalk::setNickname, },
	{ "login ?           ", &zob::Stalk::setLogin, },
	{ "postal address ?  ", &zob::Stalk::setPostalAddr, },
	{ "email address ?   ", &zob::Stalk::setEmailAddr, },
	{ "phone number ?    ", &zob::Stalk::setPhoneNumber, },
	{ "birthday date ?   ", &zob::Stalk::setBirthdayDate, },
	{ "favorite meal ?   ", &zob::Stalk::setFavoriteMeal, },
	{ "underwear color ? ", &zob::Stalk::setUnderwearColor, },
	{ "darkest secret ?  ", &zob::Stalk::setDarkestSecret, },
};

int main() {
	std::string ln;
	int idx = 0;
	zob::Stalk stalks[MAX_STALK] = { }, *stalk;

	while ((std::cout << "(ADD|SEARCH|EXIT) > ", getline(std::cin, ln)))
		if (ln == "EXIT") break;
		else if (ln == "ADD") {
			if (idx == MAX_STALK) {
				std::cout << "No more space to store your stalks !" << std::endl;
				continue;
			}
			stalk = stalks + idx++;
			for (auto ask : asks) {
				do (std::cout << ask.p), getline(std::cin, ln); while (ln.empty());
				(stalk->*ask.setter)(ln);
			}
		} else if (ln == "SEARCH") {
			int i;

			if (!idx) continue;
			std::cout << "          | FIRSTNAME|  LASTNAME|  NICKNAME" << std::endl;
			for (i = 0; i < idx; ++i) {
				std::cout << "         " << i + 1 << "|";
				stalks[i].shortPrint();
			}
			std::cout << "INDEX ?" << std::endl;
			do {
				std::cin >> i;
				std::cin.clear();
				std::cin.ignore(PTRDIFF_MAX, '\n');
			} while (i < 1 || i > idx);
			std::cout << "STALK " << i << ":" << std::endl;
			stalks[i - 1].print();
		}

	return (std::cout << "GOODBYE !" << std::endl), 0;
}
