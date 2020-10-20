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

#include "../../Include/RmlUi/Core/StringView.h"
#include "../../Include/RmlUi/Core/StringUtilities.h"
#include "../../Include/RmlUi/Core/Log.h"
#include <algorithm>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <memory>

namespace Rml
{
	StringView::StringView()
	{
		const char* empty_string = "";
		p_begin = empty_string;
		p_end = empty_string;
	}

	StringView::StringView(const char* p_begin, const char* p_end) : p_begin(p_begin), p_end(p_end)
	{
		RMLUI_ASSERT(p_end >= p_begin);
	}

	StringView::StringView(const char* c_str) : p_begin(c_str), p_end(c_str + strlen(c_str)) { }

	StringView::StringView(const char* p_begin, size_t count) : p_begin(p_begin), p_end(p_begin + count)
	{
		RMLUI_ASSERT(p_end >= p_begin);
	}

	StringView::StringView(const String& string) : p_begin(string.data()), p_end(string.data() + string.size())
	{}
	StringView::StringView(const String& string, size_t offset) : p_begin(string.data() + offset), p_end(string.data() + string.size())
	{}
	StringView::StringView(const String& string, size_t offset, size_t count) : p_begin(string.data() + offset), p_end(string.data() + std::min<size_t>(offset + count, string.size()))
	{}

	inline bool StringView::operator==(const char* other) const noexcept
	{
		const char* cur = p_begin;
		for (; *other && *cur == *other; cur++, other++);

		return cur == p_end;
	}

	bool StringView::operator<(const StringView& other) const noexcept
	{
		const char* cur = p_begin;
		const char* otherCur = other.p_begin;
		for (; cur < p_end && otherCur < other.p_end; cur++, otherCur++)
		{
			if (*cur != *otherCur)
				return *cur < *otherCur;
		}

		return false;
	}

	std::ostream& operator<<(std::ostream& stream, const StringView& object)
	{
		stream.write(object.data(), object.size());
		return stream;
	}

	int StringView::compare(const StringView& other) const noexcept
	{
		size_t thisSize = this->size();
		size_t otherSize = other.size();
		if (thisSize != otherSize)
			return (int)otherSize - (int)thisSize;

		return strncmp(p_begin, other.p_begin, thisSize);
	}

	size_t StringView::find(char ch) const noexcept
	{
		for (const char* cur = p_begin; cur < p_end; ++cur)
		{
			if (*cur == ch)
				return cur - p_begin;
		}

		return npos;
	}

	size_t StringView::find(char ch, size_t offset) const noexcept
	{
		for (const char* cur = p_begin + offset; cur < p_end; ++cur)
		{
			if (*cur == ch)
				return size_t(cur - p_begin);
		}

		return npos;
	}

	size_t StringView::rfind(char ch) const noexcept
	{
		for (const char* cur = p_end - 1; cur >= p_begin; --cur)
		{
			if (*cur == ch)
				return cur - p_begin;
		}

		return npos;
	}

	size_t StringView::rfind(char ch, size_t offset) const noexcept
	{
		for (const char* cur = (p_begin + offset) - 1; cur >= p_begin; --cur)
		{
			if (*cur == ch)
				return cur - p_begin;
		}

		return npos;
	}

	StringView StringView::substr(size_t pos) const noexcept
	{
		const char* start = p_begin + pos;
		if (start > p_end)
			return StringView(p_end, p_end);
		else
			return StringView(start, p_end);
	}

	StringView StringView::substr(size_t pos, size_t count) const noexcept
	{
		const char* start = p_begin + pos;
		if (start > p_end)
			return StringView(p_end, p_end);
		else
		{
			if (count >= size())
				return StringView(start, p_end);
			else
			{
				// check for overflow
				RMLUI_ASSERT(count <= (std::numeric_limits<size_t>::max() - uintptr_t(p_begin)));
				return StringView(start, start + count);
			}
		}
	}

	int StringView::stoi(const StringView& str)
	{
		const char* cur = str.begin();
		const char* end = str.end();

		int n = 0;
		while (cur < end)
		{
			RMLUI_ASSERT(*cur >= '0' && *cur <= '9');
			n = n * 10 + *cur++ - '0';
		}

		return n;
	}
} // namespace Rml
