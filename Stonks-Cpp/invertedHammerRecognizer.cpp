#include "invertedHammerRecognizer.h"

namespace Stonks_Cpp {
	// Constructor for invertedHammerRecognizer class
	invertedHammerRecognizer::invertedHammerRecognizer() : recognizer(1, "InvertedHammer")
	{

	}

	// Override method to recognize an inverted hammer pattern for a single candlestick
	bool invertedHammerRecognizer::recognize(List<smartCandlestick^>^ sc, int index)
	{
		smartCandlestick^ sc1 = sc[index];
		bool value;
		if (sc1->Patterns->TryGetValue(patternName, value))
		{
			return value;
		}
		else
		{
			sc1->Patterns->Add(patternName, sc1->IsInvertedHammer);
			return sc1->IsInvertedHammer;
		}
	}
}