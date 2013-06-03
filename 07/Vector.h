#pragma once
#pragma once

#include <memory>

namespace Math
{
	/// Vector number-type.
	typedef float Element;

	class Vector
	{
	public:
		/// Create empty from size, filled with a given value.
		/// \param size		vectors size
		/// \param value	value applied to all elements
		explicit Vector(unsigned int size, Element value = 0);
		explicit Vector(std::unique_ptr<Element[]> elements, unsigned int size);

		/// Copy constructor.
		Vector(const Vector& vector);

		/// Destructor, releases allocated memory.
		~Vector();

		/// Returns number of elements
		unsigned int getNumElements() const { return m_size; }
		
		/// Destroys content of this instance and copies all data from the right one
		/// \param right	assigned Math::Vector
		/// \return Reference to this
		Vector& operator = (const Vector& right);

		/// Returns element at a given position.
		/// \param index	
		/// \return Reference to last element if index is invalid 
		Element operator [] (unsigned int index) const;

		/// Returns reference to element at a given position.
		/// \param index	
		/// \return Reference to last element if index is invalid
		Element& operator [] (unsigned int index);

		Vector operator+ (const Vector& other) const;
		Vector operator- (const Vector& other) const;
		Vector operator* (const Element& other) const;
		int operator* (const Vector& other) const;
		operator char*();

		// // TODO: Insert additional Operators (here or global where necessary)
		// // -> Use const wherever possible and useful!
		// // -> Where possible use methods in favor of global functions!
		// //
		// // Vector + Vector
		// // Vector - Vector
		// // Element * Vector
		// // Vector * Element
		// // Vector * Vector (scalar product, element wise multiplication, then sum)
		// // std::ostream << Vector (output as formated text)

	private:
		/// intern element array
		std::unique_ptr<Element[]> m_elements;

		/// number of elements
		unsigned int m_size;

		int getIndex(int i, int j) const;
	};
}

Math::Vector operator* (const Math::Element& scalar, const Math::Vector& vector);
