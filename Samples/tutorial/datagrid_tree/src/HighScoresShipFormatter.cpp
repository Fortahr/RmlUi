/*
 * Copyright (c) 2006 - 2008
 * Wandering Monster Studios Limited
 *
 * Any use of this program is governed by the terms of Wandering Monster
 * Studios Limited's Licence Agreement included with this program, a copy
 * of which can be obtained by contacting Wandering Monster Studios
 * Limited at info@wanderingmonster.co.nz.
 *
 */

#include "HighScoresShipFormatter.h"
#include <RmlUi/Core/TypeConverter.h>

HighScoresShipFormatter::HighScoresShipFormatter() : Rml::DataFormatter("ship")
{
}

HighScoresShipFormatter::~HighScoresShipFormatter()
{
}

void HighScoresShipFormatter::FormatData(Rml::String& formatted_data, const Rml::StringList& raw_data)
{
	// Data format:
	// raw_data[0] is the color, in "%d, %d, %d, %d" format.

	Rml::Colorb ship_color;
	Rml::TypeConverter< Rml::String, Rml::Colorb >::Convert(raw_data[0], ship_color);

	Rml::String color_string = Rml::CreateString(32, "%d,%d,%d", ship_color.red, ship_color.green, ship_color.blue);

	formatted_data = "<defender style=\"color: rgb(" + color_string + ");\" />";
}
