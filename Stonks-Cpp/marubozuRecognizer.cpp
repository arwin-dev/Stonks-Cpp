#include "marubozuRecognizer.h"


namespace Stonks_Cpp {
	// Constructor for marubozuRecognizer class
	marubozuRecognizer::marubozuRecognizer() : recognizer(1, "Marubozu")
	{

	}

	// Override method to recognize a marubozu pattern for a single candlestick
	bool marubozuRecognizer::recognize(List<smartCandlestick^>^ sc, int index)
	{
		smartCandlestick^ sc1 = sc[index];
		bool value;
		if (sc1->Patterns->TryGetValue(patternName, value))
		{
			return value;
		}
		else
		{
			sc1->Patterns->Add(patternName, sc1->IsMarubozu);
			return sc1->IsMarubozu;
		}
	}
}