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

namespace Rml {

// Lightweight, non-initialising constructor.
template < typename ColorType, int AlphaDefault >
Color< ColorType, AlphaDefault >::Color(ColorType rgb, ColorType alpha) 
	: red(rgb), green(rgb), blue(rgb), alpha(alpha)
{
}

// Initialising constructor.
template < typename ColorType, int AlphaDefault >
Color< ColorType, AlphaDefault >::Color(ColorType red, ColorType green, ColorType blue, ColorType alpha)
	: red(red), green(green), blue(blue), alpha(alpha)
{
}

// Returns the sum of this color and another. This does not saturate the channels.
template < typename ColorType, int AlphaDefault >
Color< ColorType, AlphaDefault > Color< ColorType, AlphaDefault >::operator+(const Color< ColorType, AlphaDefault >& rhs) const
{
	return Color< ColorType, AlphaDefault >(red + rhs.red, green + rhs.green, blue + rhs.blue, alpha + rhs.alpha);
}

// Returns the result of subtracting another color from this color.
template < typename ColorType, int AlphaDefault >
Color< ColorType, AlphaDefault > Color< ColorType, AlphaDefault >::operator-(const Color< ColorType, AlphaDefault >& rhs) const
{
	return Color< ColorType, AlphaDefault >(red - rhs.red, green - rhs.green, blue - rhs.blue, alpha - rhs.alpha);
}

// Returns the result of multiplying this color component-wise by a scalar.
template < typename ColorType, int AlphaDefault >
Color< ColorType, AlphaDefault > Color< ColorType, AlphaDefault >::operator*(float rhs) const
{
	return Color((ColorType) (red * rhs), (ColorType) (green * rhs), (ColorType) (blue * rhs), (ColorType) (alpha * rhs));
}

// Returns the result of dividing this color component-wise by a scalar.
template < typename ColorType, int AlphaDefault >
Color< ColorType, AlphaDefault > Color< ColorType, AlphaDefault >::operator/(float rhs) const
{
	return Color((ColorType) (red / rhs), (ColorType) (green / rhs), (ColorType) (blue / rhs), (ColorType) (alpha / rhs));
}

// Adds another color to this in-place. This does not saturate the channels.
template < typename ColorType, int AlphaDefault >
void Color< ColorType, AlphaDefault >::operator+=(const Color& rhs)
{
	red += rhs.red;
	green += rhs.green;
	blue += rhs.blue;
	alpha += rhs.alpha;
}

// Subtracts another color from this in-place.
template < typename ColorType, int AlphaDefault >
void Color< ColorType, AlphaDefault >::operator-=(const Color& rhs)
{
	red -= rhs.red;
	green -= rhs.green;
	blue -= rhs.blue;
	alpha -= rhs.alpha;
}

// Scales this color component-wise in-place.
template < typename ColorType, int AlphaDefault >
void Color< ColorType, AlphaDefault >::operator*=(float rhs)
{
	red = (ColorType)(red * rhs);
	green = (ColorType)(green * rhs);
	blue = (ColorType)(blue * rhs);
	alpha = (ColorType)(alpha * rhs);
}

// Scales this color component-wise in-place by the inverse of a value.
template < typename ColorType, int AlphaDefault >
void Color< ColorType, AlphaDefault >::operator/=(float rhs)
{
	*this *= (1.0f / rhs);
}

template < >
Color< float, 1 > RMLUICORE_API Color< float, 1 >::operator*(const Color< float, 1 >& rhs) const;

template < >
Color< byte, 255 > RMLUICORE_API Color< byte, 255 >::operator*(const Color< byte, 255 >& rhs) const;

template < >
void RMLUICORE_API Color< float, 1 >::operator*=(const Color& rhs);

template < >
void RMLUICORE_API Color< byte, 255 >::operator*=(const Color& rhs);

} // namespace Rml
