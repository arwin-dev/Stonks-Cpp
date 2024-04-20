#include "valleyRecognizer.h"

namespace Stonks_Cpp {
	// Constructor for valleyRecognizer class
	valleyRecognizer::valleyRecognizer() : recognizer(3, "Valley")
	{

	}

	// Override method to recognize a valley pattern for a list of candlesticks
	bool valleyRecognizer::recognize(List<smartCandlestick^>^ sc, int index)
	{

		smartCandlestick^ sc1 = sc[index];
		bool value;
		if (sc1->Patterns->TryGetValue(patternName, value))
		{
			return value;
		}
		else
		{
			int offset = patternSize / 2;
			if ((index < offset) || (index == sc->Count - offset))
			{
				sc1->Patterns->Add(patternName, false);
				return false;
			}
			else
			{
				smartCandlestick^ sc2 = sc[index - offset];
				smartCandlestick^ sc3 = sc[index + offset];
				bool check = (sc2->Low < sc1->Low) && (sc2->Low < sc3->Low);
				sc1->Patterns->Add(patternName, check);
				return check;
			}
		}
	}
}
