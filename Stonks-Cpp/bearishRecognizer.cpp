#include "bearishRecognizer.h"


namespace Stonks_Cpp {
	// Constructor for bearishRecognizer class
	bearishRecognizer::bearishRecognizer() : recognizer(1, "Bearish")
	{

	}

	// Override method to recognize a bearish pattern for a single candlestick
	bool bearishRecognizer::recognize(List<smartCandlestick^>^ sc, int index)
	{
		smartCandlestick^ sc1 = sc[index];
		bool value;
		if (sc1->Patterns->TryGetValue(patternName, value))
		{
			return value;
		}
		else
		{
			sc1->Patterns->Add(patternName, sc1->IsBearish);
			return sc1->IsBearish;
		}
	}
}