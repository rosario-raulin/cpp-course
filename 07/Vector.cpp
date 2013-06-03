#include "Vector.h"

#include <cassert>
#include <sstream>
#include <cstring>

namespace Math
{
	Vector::Vector(unsigned int size, Element value) : m_elements(new Element[size]), m_size(size) {
		for (int i = 0; i < size; ++i) {
			m_elements[i] = value;
		}
	}

	Vector::Vector(const Vector& other) : m_size(other.getNumElements()), m_elements(new Element[other.getNumElements()]) {
		for (int i = 0; i < m_size; ++i) {
			m_elements[i] = other[i];
		}
	}

	Vector::~Vector() {
		m_elements.reset();
	}

	Vector::Vector(std::unique_ptr<Element[]> elements, unsigned int size) : m_elements(std::move(elements)), m_size(size) {}

	Element Vector::operator [] (unsigned int index) const {
		if (index > m_size) {
			index = m_size;
		}
		return m_elements[index];
	}

	Element& Vector::operator [] (unsigned int index) {
		if (index > m_size) {
			index = m_size;
		}
		return m_elements[index];
	}

	Vector& Vector::operator = (const Vector& right) {
		m_elements.reset();

		m_size = right.getNumElements();
		std::unique_ptr<Element[]> newVector(new Element[right.getNumElements()]);
		m_elements = std::move(newVector);

		for (int i = 0; i < m_size; ++i) {
			m_elements[i] = right[i];
		}

		return *this;
	}

	Vector Vector::operator+ (const Vector& other) const {
		//assert(getNumElements() == other.getNumElements());

		std::unique_ptr<Element[]> result(new Element[m_size]);
		for (int i = 0; i < m_size; ++i) {
			result[i] = m_elements[i] + other[i];
		}

		Vector r(std::move(result), m_size);

		return r;
	}

	Vector Vector::operator- (const Vector& other) const {
		//assert(getNumElements() == other.getNumElements());

		std::unique_ptr<Element[]> result(new Element[m_size]);
		for (int i = 0; i < m_size; ++i) {
			result[i] = m_elements[i] - other[i];
		}

		Vector r(std::move(result), m_size);

		return r;
	}

	Vector Vector::operator* (const Element& scalar) const {
		std::unique_ptr<Element[]> result(new Element[m_size]);

		for (int i = 0; i < m_size; ++i) {
			result[i] = m_elements[i] * scalar;
		}

		return Vector(std::move(result), m_size);
	}

	int Vector::operator* (const Vector& other) const {
		//assert(getNumElements() == other.getNumElements());
		
		int sum = 0;
		for (int i = 0; i < m_size; ++i) {
			sum += m_elements[i] * other[i];
		}

		return sum;
	}

	Vector::operator char*() {
		std::stringstream out;

		out << "(";
		for (int i = 0; i < m_size-1; ++i) {
			out << m_elements[i] << " ";
		}
		out << m_elements[m_size-1];
		out << ")";

		std::string tmp = out.str();
		char* result = new char[tmp.length()];
		strcpy(result, tmp.c_str());

		return result;
	}
}

Math::Vector operator* (const Math::Element& scalar, const Math::Vector& vector) {
	return Math::Vector(vector) * scalar;
}
