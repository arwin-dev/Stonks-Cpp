#include "dojiRecognizer.h"


namespace Stonks_Cpp {
	// Constructor for dojiRecognizer class
	dojiRecognizer::dojiRecognizer() : recognizer(1, "Doji")
	{

	}

	// Override method to recognize a doji pattern for a single candlestick
	bool dojiRecognizer::recognize(List<smartCandlestick^>^ sc, int index)
	{
		smartCandlestick^ sc1 = sc[index];
		bool value;
		if (sc1->Patterns->TryGetValue(patternName, value))
		{
			return value;
		}
		else
		{
			sc1->Patterns->Add(patternName, sc1->IsDoji);
			return sc1->IsDoji;
		}
	}
}