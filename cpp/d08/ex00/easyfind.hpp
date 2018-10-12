template<typename T>
bool easyfind(T &iterable, int v) {
	typename T::iterator it;

	for (it = iterable.begin(); it != iterable.end(); ++it)
		if (*it == v)
			return true;
	return false;
}
