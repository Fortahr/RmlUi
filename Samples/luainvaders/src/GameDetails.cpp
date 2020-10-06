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

#include "GameDetails.h"

static GameDetails::Difficulty difficulty = GameDetails::EASY;
static Rml::Colorb color = Rml::Colorb(255, 0, 0);
static int score = -1;
static int wave = 0;
static bool paused = false;

static GameDetails::GraphicsQuality graphics_quality = GameDetails::OK;
static bool reverb = true;
static bool spatialisation = false;

GameDetails::GameDetails()
{
}

GameDetails::~GameDetails()
{
}

// Sets the game difficulty.
void GameDetails::SetDifficulty(Difficulty _difficulty)
{
	difficulty = _difficulty;
}

// Returns the game difficulty.
GameDetails::Difficulty GameDetails::GetDifficulty()
{
	return difficulty;
}

// Sets the color of the player's ship.
void GameDetails::SetDefenderColor(const Rml::Colorb& _color)
{
	color = _color;
}

// Returns the player's ship color.
const Rml::Colorb& GameDetails::GetDefenderColor()
{
	return color;
}

// Sets the score the player achieved in the last game.
void GameDetails::SetScore(int _score)
{
	score = _score;
}

// Resets the player's score.
void GameDetails::ResetScore()
{
	score = -1;
}

// Returns the score the player achieved in the last game.
int GameDetails::GetScore()
{
	return score;
}

// Set the current wave number
void GameDetails::SetWave(int _wave)
{
	wave = _wave;
}

// Get the current wave number
int GameDetails::GetWave()
{
	return wave;
}

// Sets the pauses state of the game
void GameDetails::SetPaused(bool _paused)
{
	paused = _paused;
}

// Gets if the game is paused or not
bool GameDetails::GetPaused()
{
	return paused;
}

// Sets the quality of the graphics used in-game.
void GameDetails::SetGraphicsQuality(GraphicsQuality quality)
{
	graphics_quality = quality;
}

// Returns the quality of the graphics to use in-game.
GameDetails::GraphicsQuality GameDetails::GetGraphicsQuality()
{
	return graphics_quality;
}

// Enables or disables reverb.
void GameDetails::SetReverb(bool enabled)
{
	reverb = enabled;
}

// Returns the current state of reverb.
bool GameDetails::GetReverb()
{
	return reverb;
}

// Enables or disables 3D spatialisation in the audio engine.
void GameDetails::Set3DSpatialisation(bool enabled)
{
	spatialisation = enabled;
}

// Returns the current state of audio spatialisation.
bool GameDetails::Get3DSpatialisation()
{
	return spatialisation;
}
