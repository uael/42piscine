#include <iostream>
#include <cstdlib>

struct Data { std::string s1; int n; std::string s2; };

static void *serialize() {
	char rdm[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char c;
	std::string *s = new std::string("");

	for (c = 0; c < 8; ++c)
		s->push_back(rdm[rand() % static_cast<int>(sizeof(rdm) - 1)]);
	for (c = 0; c < 8; ++c)
		s->push_back(rdm[rand() % 10]);
	for (c = 0; c < 8; ++c)
		s->push_back(rdm[rand() % static_cast<int>(sizeof(rdm) - 1)]);

	return reinterpret_cast<void *>(s);
}

static Data *deserialize(void *raw) {
	Data *data = new Data;
	std::string *s = reinterpret_cast<std::string *>(raw);

	data->s2 = s->substr(16);
	data->n = atoi(s->substr(8, 8).c_str());
	data->s1 = s->substr(0, 8);

	delete s;
	return data;
}

int main() {
	srand(static_cast<unsigned int>(time(NULL)));

	Data *data = deserialize(serialize());

	std::cout << data->s1 << std::endl << data->n << std::endl
	          << data->s2 << std::endl;

	return 0;
}
