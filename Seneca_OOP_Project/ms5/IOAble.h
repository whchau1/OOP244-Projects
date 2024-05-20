/*Final Project Milestone 5
Module: IOAble
Filename: IOAble.cpp
Version 1.0
Author   Wing Ho Chau
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef IOABLE_H
#define IOABLE_H
#include <iostream>
using namespace std;

namespace seneca {

	class IOAble {
	public:
		/// <summary>
		/// Pure virtual function write
		/// </summary>
		/// <param name="os"></param>
		/// <returns></returns>
		virtual ostream& write(ostream& os) const = 0;

		/// <summary>
		/// Pure virtual function read
		/// </summary>
		/// <param name="is"></param>
		/// <returns></returns>
		virtual istream& read(istream& is) = 0;

		/// <summary>
		/// Default virtual destructor
		/// </summary>
		virtual ~IOAble() = default;
	};

	/// <summary>
	/// Enable feature to insert the information of an IOAble object into ostream using the IOAble::write function
	/// </summary>
	/// <param name="os">- ostream object</param>
	/// <param name="io">- IOAble object to insert</param>
	/// <returns>A reference of ostream reference</returns>
	ostream& operator<<(ostream& os, const IOAble& io);

	/// <summary>
	/// Enable feature to extract information from an istream into an IOAble object using the IOAble::read function.
	/// </summary>
	/// <param name="is">- istream object</param>
	/// <param name="io">- IOAble object extract to</param>
	/// <returns></returns>
	istream& operator>>(istream& is, IOAble& io);

}

#endif // !IOABLE_H
