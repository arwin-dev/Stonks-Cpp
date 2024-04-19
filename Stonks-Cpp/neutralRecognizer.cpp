#include "neutralRecognizer.h"

namespace Stonks_Cpp {
	// Constructor for neutralRecognizer class
	neutralRecognizer::neutralRecognizer() : recognizer(1, "Neutral")
	{

	}

	// Override method to recognize a neutral pattern for a single candlestick
	bool neutralRecognizer::recognize(smartCandlestick^ cs)
	{
		return cs->IsNeutral; // Check if the candlestick is neutral
	}
}
