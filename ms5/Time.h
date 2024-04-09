/*Final Project Milestone 5
Module: Time
Filename: Time.h
Version 1.0
Author   Wing Ho Chau
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;

namespace seneca{

	class Time {
		size_t m_mins{};  //Data member to store the time in min
	public:
		/// <summary>
		/// Constructor initializes Time object with the given number of minutes value
		/// </summary>
		/// <param name="min">- The value to initializes m_mins</param>
		Time(unsigned int min = 0u);

		/// <summary>
		/// Default destructor
		/// </summary>
		virtual ~Time() = default;

		/// <summary>
		/// Reset m_mins to current time
		/// </summary>
		/// <returns>A reference of the current object</returns>
		Time& reset();

		/// <summary>
		/// Writes the time into ostream in the HH:MM format. If the hours or minutes are single-digit numbers, it pads them with a leading zero.
		/// </summary>
		/// <param name="os">- ostream object</param>
		/// <returns>A reference of ostream object os</returns>
		ostream& write(ostream& os) const;

		/// <summary>
		/// Reads the time from istream in the H:M format. It ensures that the two integers (hours and minutes) are separated by a colon (:)
		/// </summary>
		/// <param name="is">- istream object</param>
		/// <returns>A reference of istream object is</returns>
		istream& read(istream& is);

		/// <summary>
		/// Cast Time object to unsigned int. It will return the number of minutes in the object.
		/// </summary>
		operator unsigned int()const;

		/// <summary>
		/// Multiplies the number of minutes held in the Time object by val
		/// </summary>
		/// <param name="val">- The value to multiple</param>
		/// <returns>A reference of the current object</returns>
		Time& operator*= (const int val);

		/// <summary>
		/// Calculates the time difference between the current Time object and the Time object D passed as an argument.
		/// </summary>
		/// <param name="D">- The Time object to compare</param>
		/// <returns>A reference of the current object</returns>
		Time& operator-= (const Time& D);

		/// <summary>
		/// Calculates the time difference between the current Time object and the Time object T passed as an argument without changing the current object
		/// </summary>
		/// <param name="T">- The Time object to compare</param>
		/// <returns>Modified object value</returns>
		Time operator-(const Time& T)const;
	};
	/// <summary>
	/// Enable the feature to insert a Time object into an ostream object
	/// </summary>
	/// <param name="os">- ostream object</param>
	/// <param name="time">- The Time object to insert to</param>
	/// <returns></returns>
	ostream& operator<<(ostream& os, const Time& time);
	/// <summary>
	/// Enable the feature to extract data from an istream object into the Time object
	/// </summary>
	/// <param name="is">- istream object</param>
	/// <param name="time">- The Time object to extract to</param>
	/// <returns></returns>
	istream& operator>>(istream& is, Time& time);

}

#endif // !TIME_H
