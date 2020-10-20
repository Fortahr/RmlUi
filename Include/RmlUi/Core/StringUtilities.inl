#include "StringUtilities.h"

#include <algorithm>

namespace Rml
{
	// Expands character-delimited list of values in a single string to a whitespace-trimmed list of values.
	template<typename L, typename S>
	inline void StringUtilities::ExpandString(Vector<L>& string_list, const S& string, const char delimiter)
	{
		char quote = 0;
		bool last_char_delimiter = true;
		const char* ptr = string.data();
		const char* ptr_end = ptr + string.size();
		const char* start_ptr = nullptr;
		const char* end_ptr = ptr;

		size_t num_delimiter_values = std::count(string.begin(), string.end(), delimiter);
		if (num_delimiter_values == 0)
		{
			string_list.push_back(static_cast<L>(TrimWhitespace(StringView(string))));
			return;
		}
		string_list.reserve(string_list.size() + num_delimiter_values + 1);

		while (ptr < ptr_end)
		{
			// Switch into quote mode if the last char was a delimeter ( excluding whitespace )
			// and we're not already in quote mode
			if (last_char_delimiter && !quote && (*ptr == '"' || *ptr == '\''))
			{
				quote = *ptr;
			}
			// Switch out of quote mode if we encounter a quote that hasn't been escaped
			else if (*ptr == quote && *(ptr - 1) != '\\')
			{
				quote = 0;
			}
			// If we encounter a delimiter while not in quote mode, add the item to the list
			else if (*ptr == delimiter && !quote)
			{
				if (start_ptr)
					string_list.emplace_back(start_ptr, end_ptr + 1);
				else
					string_list.emplace_back();
				last_char_delimiter = true;
				start_ptr = nullptr;
			}
			// Otherwise if its not white space or we're in quote mode, advance the pointers
			else if (!IsWhitespace(*ptr) || quote)
			{
				if (!start_ptr)
					start_ptr = ptr;
				end_ptr = ptr;
				last_char_delimiter = false;
			}

			ptr++;
		}

		// If there's data pending, add it.
		if (start_ptr)
			string_list.emplace_back(start_ptr, end_ptr + 1);
	}

	template<typename L, typename S>
	inline void StringUtilities::ExpandString(Vector<L>& string_list, const S& string, const char delimiter, char quote_character, char unquote_character, bool ignore_repeated_delimiters)
	{
		int quote_mode_depth = 0;
		const char* ptr = string.data();
		const char* ptr_end = ptr + string.size();
		const char* start_ptr = nullptr;
		const char* end_ptr = ptr;

		while (ptr < ptr_end)
		{
			// Increment the quote depth for each quote character encountered
			if (*ptr == quote_character)
			{
				++quote_mode_depth;
			}
			// And decrement it for every unquote character
			else if (*ptr == unquote_character)
			{
				--quote_mode_depth;
			}

			// If we encounter a delimiter while not in quote mode, add the item to the list
			if (*ptr == delimiter && quote_mode_depth == 0)
			{
				if (start_ptr)
					string_list.emplace_back(start_ptr, end_ptr + 1);
				else if (!ignore_repeated_delimiters)
					string_list.emplace_back();
				start_ptr = nullptr;
			}
			// Otherwise if its not white space or we're in quote mode, advance the pointers
			else if (!IsWhitespace(*ptr) || quote_mode_depth > 0)
			{
				if (!start_ptr)
					start_ptr = ptr;
				end_ptr = ptr;
			}

			ptr++;
		}

		// If there's data pending, add it.
		if (start_ptr)
			string_list.emplace_back(start_ptr, end_ptr + 1);
	}

	// Joins a list of string values into a single string separated by a character delimiter.
	template<typename S>
	inline void StringUtilities::JoinString(String& string, const S& string_list, const char delimiter)
	{
		for (size_t i = 0; i < string_list.size(); i++)
		{
			string += string_list[i];
			if (delimiter != '\0' && i < string_list.size() - 1)
				string += delimiter;
		}
	}
}