#ifndef _Colors
#define _Colors

class Vect;

class Colors {

private:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	Colors::Colors() = default;
	///
	/// \brief	Default constructor
	/// 		
	///Colors is a static class which offers access to Vectors that hold common color RGBs.
	/// Currently available are blue, red, green, black, and white
	///
	/// \author	jehalter
	/// \date	3/17/2019
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Colors() = default;
	Colors(const Colors&) = delete;
	Colors& operator=(const Colors&) = delete;
	~Colors() = default;;
public:
	static const Vect BLUE;
	static const Vect RED;
	static const Vect GREEN;
	static const Vect BLACK;
	static const Vect WHITE;
};

#endif _Colors
