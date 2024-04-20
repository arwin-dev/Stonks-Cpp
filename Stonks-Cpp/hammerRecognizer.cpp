#include "hammerRecognizer.h"

namespace Stonks_Cpp {
	// Constructor for bullishRecognizer class
	hammerRecognizer::hammerRecognizer() : recognizer(1, "Hammer")
	{

	}

	// Override method to recognize a bullish pattern for a single candlestick
	bool hammerRecognizer::recognize(List<smartCandlestick^>^ sc, int index)
	{
		smartCandlestick^ sc1 = sc[index];
		bool value;
		if (sc1->Patterns->TryGetValue(patternName, value))
		{
			return value;
		}
		else
		{
			sc1->Patterns->Add(patternName, sc1->IsHammer);
			return sc1->IsHammer;
		}
	}
}