#include "dragonFlyDojiRecognizer.h"


namespace Stonks_Cpp {
	// Constructor for dragonFlyDojiRecognizer class
	dragonFlyDojiRecognizer::dragonFlyDojiRecognizer() : recognizer(1, "DragonFlyDoji")
	{

	}

	// Override method to recognize a dragonfly doji pattern for a single candlestick
	bool dragonFlyDojiRecognizer::recognize(List<smartCandlestick^>^ sc, int index)
	{
		smartCandlestick^ sc1 = sc[index];
		bool value;
		if (sc1->Patterns->TryGetValue(patternName, value))
		{
			return value;
		}
		else
		{
			sc1->Patterns->Add(patternName, sc1->IsDragonFlyDoji);
			return sc1->IsDragonFlyDoji;
		}
	}
}