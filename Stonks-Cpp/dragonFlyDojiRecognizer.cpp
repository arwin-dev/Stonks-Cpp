#include "dragonFlyDojiRecognizer.h"


namespace Stonks_Cpp {
	// Constructor for dragonFlyDojiRecognizer class
	dragonFlyDojiRecognizer::dragonFlyDojiRecognizer() : recognizer(1, "DragonFlyDoji")
	{

	}

	// Override method to recognize a dragonfly doji pattern for a single candlestick
	bool dragonFlyDojiRecognizer::recognize(smartCandlestick^ cs)
	{
		return cs->IsDragonFlyDoji; // Check if the candlestick is a dragonfly doji
	}
}