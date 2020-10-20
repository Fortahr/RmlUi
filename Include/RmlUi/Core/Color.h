/*
 * This source file is part of RmlUi, the HTML/CSS Interface Middleware
 *
 * For the latest information, see http://github.com/mikke89/RmlUi
 *
 * Copyright (c) 2008-2010 CodePoint Ltd, Shift Technology Ltd
 * Copyright (c) 2019 The RmlUi Team, and contributors
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#ifndef RMLUI_CORE_COLOR_H
#define RMLUI_CORE_COLOR_H

#include "Header.h"

namespace Rml {

/**	
	Templated class for a four-component RGBA color.

	@author Peter Curry
 */

template < typename ColorType, int AlphaDefault >
class Color
{
public:
	/// Initializing constructor.
	/// @param[in] rgb Initial red, green and blue value of the color.
	/// @param[in] alpha Initial alpha value of the color.
	inline Color(ColorType rgb = ColorType{ 0 }, ColorType alpha = ColorType{ AlphaDefault });
	/// Initializing constructor.
	/// @param[in] red Initial red value of the color.
	/// @param[in] green Initial green value of the color.
	/// @param[in] blue Initial blue value of the color.
	/// @param[in] alpha Initial alpha value of the color.
	inline Color(ColorType red, ColorType green, ColorType blue, ColorType alpha = ColorType{ AlphaDefault });

	/// Returns the sum of this color and another. This does not saturate the channels.
	/// @param[in] rhs The color to add this to.
	/// @return The sum of the two colors.
	inline Color operator+(const Color& rhs) const;
	/// Returns the result of subtracting another color from this color.
	/// @param[in] rhs The color to subtract from this color.
	/// @return The result of the subtraction.
	inline Color operator-(const Color& rhs) const;
	/// Returns the result of multiplying this color by another.
	/// @param[in] rhs The color to multiply by.
	/// @return The result of the multiplication.
	Color operator*(const Color& rhs) const;
	/// Returns the result of multiplying this color component-wise by a scalar.
	/// @param[in] rhs The scalar value to multiply by.
	/// @return The result of the scale.
	inline Color operator*(float rhs) const;
	/// Returns the result of dividing this color component-wise by a scalar.
	/// @param[in] rhs The scalar value to divide by.
	/// @return The result of the scale.
	inline Color operator/(float rhs) const;

	/// Adds another color to this in-place. This does not saturate the channels.
	/// @param[in] rhs The color to add.
	inline void operator+=(const Color& rhs);
	/// Subtracts another color from this in-place.
	/// @param[in] rhs The color to subtract.
	inline void operator-=(const Color& rhs);
	/// Multiplies this color component-wise with another in-place.
	/// @param[in] rhs The color to multiply by.
	/// @return This color, post-operation.
	void operator*=(const Color& rhs);
	/// Scales this color component-wise in-place.
	/// @param[in] rhs The value to scale this colors's components by.
	inline void operator*=(float rhs);
	/// Scales this color component-wise in-place by the inverse of a value.
	/// @param[in] rhs The value to divide this color's components by.
	inline void operator/=(float rhs);

	/// Equality operator.
	/// @param[in] rhs The color to compare this against.
	/// @return True if the two colors are equal, false otherwise.
	inline bool operator==(const Color& rhs)	{ return red == rhs.red && green == rhs.green && blue == rhs.blue && alpha == rhs.alpha; }
	/// Inequality operator.
	/// @param[in] rhs The color to compare this against.
	/// @return True if the two colors are not equal, false otherwise.
	inline bool operator!=(const Color& rhs)	{ return red != rhs.red || green != rhs.green || blue != rhs.blue || alpha != rhs.alpha; }

	/// Auto-cast operator.
	/// @return A pointer to the first value.
	inline operator const ColorType*() const { return &red; }
	/// Constant auto-cast operator.
	/// @return A constant pointer to the first value.
	inline operator ColorType*() { return &red; }

#pragma warning(disable : 4201)
	union{
		struct { ColorType r, g, b, a; };
		struct { ColorType x, y, z, w; };
		struct { ColorType red, green, blue, alpha; };
	};
#pragma warning(default : 4201)

#ifdef RMLUI_COLOR_USER_EXTRA
	#if defined(__has_include) && __has_include(RMLUI_COLOR_USER_EXTRA)
		#include RMLUI_COLOR_USER_EXTRA
	#else
		RMLUI_COLOR_USER_EXTRA
	#endif
#endif
};

} // namespace Rml


#include "Color.inl"


#endif
