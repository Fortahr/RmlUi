/*
 * This source file is part of RmlUi, the HTML/CSS Interface Middleware
 *
 * For the latest information, see http://github.com/mikke89/RmlUi
 *
 * Copyright (c) 2008-2010 CodePoint Ltd, Shift Technology Ltd
 * Copyright (c) 2019 The RmlUi Team, and contributors
 * Copyright (c) 2020 Eracle Games
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

#ifndef RMLUI_CORE_STRINGVIEW_H
#define RMLUI_CORE_STRINGVIEW_H

#include "Header.h"
#include "Types.h"

namespace Rml {

/*
	String view primarily used to speed up parsing code. 
	
	The string view is agnostic to the underlying encoding, any operation will strictly operate on bytes.
*/

class RMLUICORE_API StringView
{
public:
	static constexpr size_t npos = size_t(-1);

	StringView();
	StringView(const char* p_begin, const char* p_end);
	StringView(const char* p_begin, size_t count);
	StringView(const String& string);
	StringView(const String& string, size_t offset);
	StringView(const String& string, size_t offset, size_t count);

	// String comparison to another view
	inline bool operator==(const StringView& other) const noexcept { size_t size = this->size(); return size == other.size() && memcmp(p_begin, other.p_begin, size) == 0; }
	inline bool operator!=(const StringView& other) const noexcept { size_t size = this->size(); return size != other.size() || memcmp(p_begin, other.p_begin, size) != 0; }

	inline bool operator==(const String& other) const noexcept { size_t size = this->size(); return size == other.size() && memcmp(p_begin, other.data(), size) == 0; }
	inline bool operator!=(const String& other) const noexcept { size_t size = this->size(); return size != other.size() || memcmp(p_begin, other.data(), size) != 0; }

	bool operator==(const char* other) const noexcept;
	inline bool operator!=(const char* other) const noexcept { return !operator==(other); }

	bool operator<(const StringView& other) const noexcept;

	// make sure you ask for a position < size(), this function doesn't safe guard it
	inline char operator[](size_t pos) const noexcept { return p_begin[pos]; }

	int compare(const StringView& other) const noexcept;

	inline const char* begin() const { return p_begin; }
	inline const char* end() const { return p_end; }

	inline const char* data() const noexcept { return p_begin; }

	inline size_t size() const { return size_t(p_end - p_begin); }
	inline bool empty() const { return p_end == p_begin; }

	size_t find(char ch) const noexcept;
	size_t find(char ch, size_t offset) const noexcept;
	size_t rfind(char ch) const noexcept;
	size_t rfind(char ch, size_t offset) const noexcept;

	StringView substr(size_t pos = 0) const noexcept;
	StringView substr(size_t pos, size_t count) const noexcept;

	explicit inline operator String() const { return String(p_begin, p_end); }

	static int stoi(const StringView& str);

private:
	const char* p_begin;
	const char* p_end;
};

} // namespace Rml
#endif
