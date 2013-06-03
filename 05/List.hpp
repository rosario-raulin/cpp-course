#ifndef HAVE_LIST_HPP
#define HAVE_LIST_HPP

template <class T>
class List {
public:
	virtual ~List() {}

	virtual void add(const T element) = 0;
	virtual const T& get() const = 0;
	virtual int getSize() const = 0;
};

#endif