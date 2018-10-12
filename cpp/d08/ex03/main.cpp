#include <map>
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <cstring>

struct Script {
	char *ip;
	char *data;
};

class Inst {
public:
	Inst() {}
	virtual ~Inst() {}
	Inst(const Inst &src) { *this = src; }
	Inst &operator=(Inst const &src) { (void)src; return *this; }

	virtual void execute(Script &script) const { (void)script; };
};

class Right : public Inst {
public:
	void execute(Script &script) const {
		++script.data;
	}
};

class Left : public Inst {
public:
	void execute(Script &script) const {
		--script.data;
	}
};

class Plus : public Inst {
public:
	void execute(Script &script) const {
		++(*script.data);
	}
};

class Minus : public Inst {
public:
	void execute(Script &script) const {
		--(*script.data);
	}
};

class Dot : public Inst {
public:
	void execute(Script &script) const {
		std::cout << *script.data;
	}
};

class LeftBracket : public Inst {
public:
	void execute(Script &script) const {
		if (*script.data != '\0') return;

		int counter = 1;

		do {
			++script.ip;

			if (*script.ip == '[') counter++;
			else if (*script.ip == ']') counter--;
		} while (counter != 0);
	}
};

class RightBracket : public Inst {
public:
	void execute(Script &script) const {
		int counter = 0;

		do {
			if (*script.ip == '[') counter++;
			else if (*script.ip == ']') counter--;

			--script.ip;
		} while (counter != 0);
	}
};

class Intr {
public:
	typedef std::map<char, Inst *> Insts;

	Intr(const char *filename, Insts &i)
		: mem(), insts(i) {
		std::ifstream file(filename, std::ios::binary | std::ios::ate);

		if (!file)
			throw new std::runtime_error("no such file or directory");

		std::streamsize size = file.tellg();
		buffer.reserve(static_cast<unsigned long>(size));

		file.seekg(0, std::ios::beg);
		if (!file.read(buffer.data(), size)) {
			file.close();
			throw std::runtime_error("cannot read file");
		}
		file.close();
	}
	Intr(const Intr &src) : insts(src.insts) { *this = src; }
	virtual ~Intr() { }
	Intr &operator=(Intr const &src) {
		buffer = src.buffer;
		insts = src.insts;
		return *this;
	}

	void eval() {
		Script script = {
			.ip = buffer.data(),
			.data = mem
		};

		for (; *script.ip; ++script.ip) {
			Insts::iterator it;

			if ((it = insts.find(*script.ip)) == insts.end())
				continue;

			(*it).second->execute(script);
		}
	}

	static void eval(char *mem, std::queue<Inst *> insts) {
		Script script = {
			.ip = NULL,
			.data = mem
		};

		while (!insts.empty()) {
			Inst *inst = insts.front();
			insts.pop();

			inst->execute(script);
		}
	}

	unsigned queue(std::queue<Inst *> &i) {
		unsigned n = 0, m = 0;
		Script script = {
			.ip = buffer.data(),
			.data = mem
		};

		for (; *script.ip; ++script.ip) {
			Insts::iterator it;

			if ((it = insts.find(*script.ip)) == insts.end())
				continue;

			if ((*it).first != '>') { if (++n > m) m = n; }
			else if ((*it).first != '<') {
				if (n == 0)
					throw std::runtime_error("write error, out of memory");
				--n;
			}

			if ((*it).first != '.')
				(*it).second->execute(script);
			if ((*it).first != '[' && (*it).first != ']')
				i.push((*it).second);
		}

		return m;
	}

private:
	char mem[9999];
	std::vector<char> buffer;
	Insts &insts;
};

int main(int ac, char *av[]) {
	if (ac != 2) {
		std::cerr << "usage: " << *av << " <filename>" << std::endl;
		return 1;
	}

	Intr::Insts insts;

	insts['>'] = new Right();
	insts['<'] = new Left();
	insts['+'] = new Plus();
	insts['-'] = new Minus();
	insts['.'] = new Dot();
	insts['['] = new LeftBracket();
	insts[']'] = new RightBracket();

	try {
		Intr intr(*(av + 1), insts);

#if 1
		std::queue<Inst *> queue;

		unsigned n = intr.queue(queue);
		char mem[n];

		std::memset(mem, 0, n);
		Intr::eval(mem, queue);
#else
		intr.eval();
#endif

	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	delete insts['>'];
	delete insts['<'];
	delete insts['+'];
	delete insts['-'];
	delete insts['.'];
	delete insts['['];
	delete insts[']'];

	return 0;
}
