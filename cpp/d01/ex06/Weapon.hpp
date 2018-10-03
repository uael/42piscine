#ifndef PROJECT_WEAPON_HPP
#define PROJECT_WEAPON_HPP

#include <string>

namespace zob {

	class Weapon {
	private:
		std::string type;
	public:
		Weapon(const std::string &type = "soap");
		const std::string &getType() const;
		void setType(const std::string &type);
	};
}

#endif //PROJECT_WEAPON_HPP
