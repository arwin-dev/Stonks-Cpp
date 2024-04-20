#include "gravestoneDojiRecognizer.h"

namespace Stonks_Cpp {

	// Constructor for gravestoneDojiRecognizer class
	gravestoneDojiRecognizer::gravestoneDojiRecognizer() : recognizer(1, "GravestoneDoji")
	{

	}

	// Override method to recognize a gravestone doji pattern for a single candlestick
	bool gravestoneDojiRecognizer::recognize(List<smartCandlestick^>^ sc, int index)
	{
		smartCandlestick^ sc1 = sc[index];
		bool value;
		if (sc1->Patterns->TryGetValue(patternName, value))
		{
			return value;
		}
		else
		{
			sc1->Patterns->Add(patternName, sc1->IsGravestoneDoji);
			return sc1->IsGravestoneDoji;
		}
	}
}